var f = function(key, value) {

    console.log(key + value);
};

var Mapper = require('../mapjs').Mapper;
var mapper = new Mapper();
mapper.map(f);


var JobConf = require('../mapjs').JobConf;
var jobconf = new JobConf();
jobconf.mapper = 3;
jobconf.inputPath = "input path";
jobconf.outputPath = "output path";
console.log(jobconf.mapper);
console.log(jobconf.inputPath);
console.log(jobconf.outputPath);
