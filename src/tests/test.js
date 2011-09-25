var Mapper = require('../mapjs').Mapper;
var JobConf = require('../mapjs').JobConf;

var f = function(key, value) {

    console.log(key + value);
};

var mapper = new Mapper();

mapper.map(f);

var jobconf = new JobConf();

//jobconf.mapper = 3;
