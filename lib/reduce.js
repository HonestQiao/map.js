var mapjs = require('../mapjs');
var inherits = require('util').inherits;

function Reducer(reduceFunction) {
  if (!(this instanceof Reducer)) return new Reducer(Reducer);
  this._reduceFunction = reduceFunction;
}

inherits(Reducer, mapjs.Reducer);

exports.Reducer = Reducer;

exports.createReducer = function(reduceFunction) {
    return new Reducer(reduceFunction);
};
