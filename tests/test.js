var mapjs = require('../mapjs');
var map = require('../lib/map');
var reduce = require('../lib/reduce');
var JobConf = require('../lib/jobconf').JobConf;
var JobClient = require('../lib/jobclient').JobClient;

var mapper = map.createMapper(function(key, value, outputCollector, reporter) {
    outputCollector.collect(value, 1);
});

var reducer = reduce.createReducer(function(key, value, outputCollector, reporter) {
    outputCollector.collect(value, 1);
});

var jobconf = new JobConf();
var jobclient = new JobClient();
jobconf.mapper = mapper;
jobconf.reducer = reducer;
jobconf.inputPath = "./tests/data/input/";
jobconf.outputPath = "./tests/data/output/";
jobclient.run(jobconf);
