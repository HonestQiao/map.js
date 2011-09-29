var fs = require('fs');
var path = require('path');
var mapjs = require('../mapjs');
var Mapper = require('./map').Mapper;
var OutputCollector = mapjs.OutputCollector;
var inherits = require('util').inherits;

function JobClient() {
}

inherits(JobClient, mapjs.JobClient);

exports.JobClient = JobClient;

JobClient.prototype.run = function(jobconf) {
    if(!jobconf.inputFormat) throw new Error(
        'JobClient.run fail. No input format specified.');
    if(!jobconf.mapper) throw new Error(
        'JobClient.run fail. No mapper specified.');
    if(!jobconf.reducer) throw new Error(
        'JobClient.run fail. No reducer specified.');

    console.log('jobclient started running');
    var mappers = this._generateMappers(jobconf);
    var intermediatePairs = new OutputCollector();

    // All mappers start mapping, push results into a list of intermediate pairs.
    for(var i = 0; i < mappers.length; ++i) {
        var outputCollector = new OutputCollector();
        mappers[i].map(outputCollector);
        intermediatePairs.join(outputCollector);
    }

    // All reducers start reducing, each reducer gets a list of values with
    // the same key from the list of intermediate pairs generated from the 
    // mappers.
    var valuesByKeys = splitByKeys(intermediatePairs);

    for(var i = 0; i < valuesByKeys.length; ++i) {
        var valuesByKey = valuesByKeys[i];
        var key = valuesByKey.keys()[0];
        var values = valuesByKey.values(key);
        var resultOutputCollector = new OutputCollector();
        var reducer = jobconf.reducer.clone();
        reducer.key = key;
        reducer.values = values;
        reducer.reduce(resultOutputCollector);
    }
};

function splitByKeys(outputCollector) {
    var outputCollectors = [];
    var keys = outputCollector.keys();

    for(var i = 0; i < keys.length; ++i) {
        var key = keys[i];
        var oc = new OutputCollector();
        var values = outputCollector.values(key);
        for(var j = 0; j < values.length; ++j) {
            var value = values[j];
            oc.collect(key, value);
        }
        outputCollectors.push(oc);
    }

    return outputCollectors;
}

JobClient.prototype._generateMappers = function(jobconf) {
    var inputFiles = fs.readdirSync(jobconf.inputPath);
    var inputSplits = [];
    var mappers = [];
    for(var i = 0; i < inputFiles.length; ++i) {
        var absPath = path.join(jobconf.inputPath, inputFiles[i]);
        inputSplits = inputSplits.concat(jobconf.inputFormat.split(absPath));
    }

    // TODO: for now we assign both the key and value of each mapper as the 
    // value of the input split. Probably this is not the correct way.
    for(var i = 0; i < inputSplits.length; ++i) {
        var mapper = jobconf.mapper.clone();
        mapper.key = inputSplits[i].value;
        mapper.value = inputSplits[i].value;
        mappers.push(mapper);
    }

    return mappers;
};
