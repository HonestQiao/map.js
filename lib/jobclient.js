var mapjs = require('../mapjs');
var inherits = require('util').inherits;

function JobClient() {
}

inherits(JobClient, mapjs.JobClient);

exports.JobClient = JobClient;

JobClient.prototype.run = function(jobconf) {
    console.log('frr');
    if(!jobconf.inputSplit) throw new Error('JobClient.run fail. No input split specified.');
    if(!jobconf.mapper) throw new Error('JobClient.run fail. No mapper specified.');
    if(!jobconf.reducer) throw new Error('JobClient.run fail. No reducer specified.');

    var mappers = getMappersFromInputSplit(jobconf);
    var intermediatePairs;

    for(mapper in mappers) {
        var outputCollector;
        mapper.map(outputCollector);
        intermediatePairs.join(outputCollector);
    }

    for(oc in outputCollector.splitByKeys()) {
        var resultOutputCollector;
        var reducer = jobconf.reducer.clone();
        reducer.outputCollector = oc;
        reducer.reduce(resultOutputCollector);
    }
};



function getMappersFromInputSplit(jobconf) {
    var mappers = [];
    var splits = jobconf.inputSplit.split();
    for(s in splits) {
        var mapper = jobconf.mapper.clone();
        mapper.value = s;
    }
    return mappers;
};
