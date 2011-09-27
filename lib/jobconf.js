var mapjs = require('../mapjs');
var inherits = require('util').inherits;

function JobConf() {
    if (!(this instanceof JobConf)) return new JobConf();
}

inherits(JobConf, mapjs.JobConf);

exports.JobConf = JobConf;
