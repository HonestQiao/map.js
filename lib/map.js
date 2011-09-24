/* USAGE

var mapper = map.createMapper(function(key, value, outputArray) {
    // here value is an array.
    for(int i = 0; i < value.length; ++i) {
        outputArray.push(new KeyValuePair(i, value[i]);
    }
});

var mappedList = mapper.map();

*/

var mapjs = require('mapjs');

exports.createMapper = function(mapFunction) {
    return new Mapper(mapFunction);
};

/* Constructor for Mapper. */
function Mapper(mapFunction) {
  if (!(this instanceof Mapper)) return new Mapper(mapFunction);
  this._mapFunction = mapFunction;
}

/* Maps a key/value pair into a set of intermediate key/value pairs. */
Mapper.prototype.map = function(key, value, outputArray, reporter) {
    assert(this._mapFunction);
    this.mapFunction(key, value, _outputArray);
};
