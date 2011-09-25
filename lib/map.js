/* USAGE

var mapper = map.createMapper(function(key, value, outputArray) {
    // here value is an array.
    for(int i = 0; i < value.length; ++i) {
        outputArray.push(new KeyValuePair(i, value[i]);
    }
});

var mappedList = mapper.map();

*/

var mapjs = require('../mapjs');
var inherits = require('utils').inherits;

exports.createMapper = function(mapFunction) {
    return new Mapper(mapFunction);
};

function Mapper(mapFunction) {
  if (!(this instanceof Mapper)) return new Mapper(mapFunction);
  this._mapFunction = mapFunction;
}

inherits(Mapper, mapjs.Mapper);

Mapper.prototype.map = function(key, value, outputCollector, reporter) {
    assert(this._mapFunction);
    this.mapFunction(key, value, outputCollector, reporter);
};

exports.Mapper = Mapper;
