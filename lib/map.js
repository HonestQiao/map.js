var fs = require('fs');
var events = require('events');
var mapjs = require('../mapjs');
var inherits = require('util').inherits;

function Mapper(mapFunction) {
    if (!(this instanceof Mapper)) return new Mapper(mapFunction);
    //events.EventEmitter.call(this);
    var self = this;

    for(var l = arguments.length - 1; l >= 0; l--) {
        if(typeof arguments[l] == 'function') {
            self._mapFunction = arguments[l];
        }
        if(arguments[l] == undefined) break;
    }
}

inherits(Mapper, mapjs.Mapper);

exports.Mapper = Mapper;

Mapper.prototype.map = function(outputCollector) {
    if(!this._mapFunction) throw new Error("Mapper.map fail. No map function specified.");
    if(!this.value) throw new Error('Mapper.map fail. No value specified.');
    this._mapFunction(this.key, this.value, outputCollector, null);
};

exports.createMapper = function() {
    return new Mapper(arguments[0]);
};

Mapper.prototype.clone = function() {
     return new Mapper(this._mapFunction);
};


