var mapjs = require('../mapjs');
var inherits = require('util').inherits;

function OutputCollector() {
    if (!(this instanceof OutputCollector)) return new OutputCollector();
}

inherits(OutputCollector, mapjs.OutputCollector);

exports.OutputCollector = OutputCollector;

OutputCollector.prototype.splitByKeys = function() {

    var outputCollectors = [];
    var keys = this.keys();
    for(var i = 0; i < keys.length; ++i) {
        var key = keys[i];
        var values = this.values(key);
        for(var j = 0; j < values.length; ++j) {
            var value = values[i];
            var oc = new outputCollector();
            outputCollectors.push(oc.collect(key, value));
        }
    }
};
