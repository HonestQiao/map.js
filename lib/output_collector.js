var mapjs = require('../mapjs');
var inherits = require('util').inherits;

function OutputCollector(key, value) {
    this.collect(key, value);
}

inherits(OutputCollector, mapjs.OutputCollector);

OutputCollector.prototype.splitByKeys = function() {

    var outputCollectors = [];
    var keys = this.keys();
    for(var i = 0; i < keys.length; ++i) {
        var key = keys[i];
        var values = this.values(key);
        for(var j = 0; j < values.length; ++j) {
            var value = values[i];
            outputCollectors.push(new outputCollector(key, value));
        }
    }
};

exports.OutputCollector = OutputCollector;
