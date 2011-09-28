var fs = require('fs');
var mapjs = require('../mapjs');
var inherits = require('util').inherits;

function Mapper(mapFunction) {
    if (!(this instanceof Mapper)) return new Mapper(mapFunction);
    this._mapFunction = mapFunction;
}

inherits(Mapper, mapjs.Mapper);

exports.Mapper = Mapper;

Mapper.prototype.map = function(outputCollector) {

    if(!this._mapFunction) throw new Error("Mapper.map fail. No map function specified.");
    if(!this.value) throw new Error('Mapper.map fail. No value specified.');
    //console.log(this._mapFunction.toString());
    this._mapFunction(this, 'key', this.value, outputCollector, null);
};

exports.createMapper = function(mapFunction) {
    return new Mapper(mapFunction);
};

Mapper.prototype.clone = function() {
     return new Mapper(this._mapFunction);
};


