var mapjs = require('../mapjs');
var inherits = require('util').inherits;

function OutputCollector() {
    if (!(this instanceof OutputCollector)) return new OutputCollector();
}

inherits(OutputCollector, mapjs.OutputCollector);

exports.OutputCollector = OutputCollector;
