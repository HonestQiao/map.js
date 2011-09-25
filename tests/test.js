var f = function(key, value, outputCollector, reporter) {

    console.log('Inside map function');
    console.log(key + value);
};

var Mapper = require('../mapjs').Mapper;
var mapper = new Mapper();
mapper.map(f(3,4));

var OutputCollector = require('../mapjs').OutputCollector;
var outputCollector = new OutputCollector();
outputCollector.collect(1,2);
outputCollector.collect(1,3);
outputCollector.collect(1,4);
var array = outputCollector.values(1);
console.log(array);
/*
var JobConf = require('../mapjs').JobConf;
var jobconf = new JobConf();
jobconf.mapper = 3;
jobconf.inputPath = "input path";
jobconf.outputPath = "output path";
console.log(jobconf.mapper);
console.log(jobconf.inputPath);
console.log(jobconf.outputPath);

JobConf.reducer = mapper;
JobConf.reducer.map(f);

var Reducer = require('../mapjs').Reducer;
var reducer = new Reducer();
reducer.reduce(f);
*/
