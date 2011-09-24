var mapjs = require('mapjs');

exports.createReducer = function(reduceFunction) {
    return new Reducer(reduceFunction);
};

/* USAGE

var reduce = require('require');

var reducer = reduce.createReducer(function(key, values, outputArray) {
    // values is an array.
});

var reducedList = reducer.reduce();

*/


/* Constructor for Reducer. */
function Reducer(reduceFunction) {
  if (!(this instanceof Reducer)) return new Reducer(Reducer);
  this._reduceFunction = reduceFunction;
}

/* Maps a key/value pair into a set of intermediate key/value pairs. */
Reducer.prototype.reduce = function(key, values, outputArray) {
    assert(this._reduceFunction);
    this._reduceFunction(key, values, outputArray);
};
