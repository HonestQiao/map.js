var f = function(key, value) {

    console.log(key + value);
};

var Mapper = require('../mapjs').Mapper;
var mapper = new Mapper();
mapper.map(f);


var JobConf = require('../mapjs').JobConf;
var jobconf = new JobConf();
jobconf.mapper = 3;
console.log(jobconf.mapper);
