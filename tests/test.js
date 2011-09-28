var fs = require('fs');
var mapjs = require('../mapjs');
var map = require('../lib/map');
var reduce = require('../lib/reduce');
var input = require('../lib/input_format');
var OutputCollector = require('../lib/output_collector').OutputCollector;
var InputSplit = require('../lib/input_split').InputSplit;
var JobConf = require('../lib/jobconf').JobConf;
var JobClient = require('../lib/jobclient').JobClient;

var mapper = map.createMapper(function(key, value, outputCollector, reporter) {
    outputCollector.collect(value, 1);
});

var reducer = reduce.createReducer(function(key, value, outputCollector, reporter) {
    
    outputCollector.collect(value, 1);
});

var inputFormat = input.createInputFormat(function(fileName) {
    var inputSplits = [];

    var data = fs.readFileSync(fileName, 'ascii');
    if(data) {
        var lines = data.toString().split(' ');
        for(line in lines) {
            inputSplits.push(new InputSplit(line));
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
