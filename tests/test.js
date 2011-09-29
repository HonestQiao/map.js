var fs = require('fs');
var mapjs = require('../mapjs');
var map = require('../lib/map');
var reduce = require('../lib/reduce');
var input = require('../lib/input');
var OutputCollector = mapjs.OutputCollector;
var JobConf = require('../lib/jobconf').JobConf;
var JobClient = require('../lib/jobclient').JobClient;
var InputSplit = input.InputSplit;

var mapper = map.createMapper(function(key, value, outputCollector, reporter) {
    outputCollector.collect(key, 1); // here we mark every word we encounter.
});

var reducer = reduce.createReducer(function(key, values, outputCollector, reporter) {
    console.log(key + " has occurred " + values.length.toString() + " times.");
});

var inputFormat = input.createInputFormat(function(fileName) {
    var inputSplits = [];

    var data = fs.readFileSync(fileName, 'ascii');
    if(data) {
        var chunks = data.toString().split(' ');
        for(var i = 0; i < chunks.length; ++i) {
            inputSplits.push(new InputSplit(chunks[i]));
        }
    }

    return inputSplits;
});

var jobconf = new JobConf();
var jobclient = new JobClient();
jobconf.mapper = mapper;
jobconf.reducer = reducer;
jobconf.inputFormat = inputFormat;
jobconf.inputPath = "./tests/data/input/";
jobconf.outputPath = "./tests/data/output/";
jobclient.run(jobconf);
