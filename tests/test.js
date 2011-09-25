var f = function(key, value, outputCollector, reporter) {

    for(var i = key; i <= 10; ++i) {
        outputCollector.collect(key, value+i);
    }
};

var Mapper = require('../mapjs').Mapper;
var mapper = new Mapper(f);

var OutputCollector = require('../mapjs').OutputCollector;
var outputCollector = new OutputCollector();
mapper.map(f(1,1, outputCollector));
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
