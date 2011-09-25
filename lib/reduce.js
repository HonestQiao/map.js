var mapjs = require('../mapjs');
var inherits = require('utils').inherits;

exports.createReducer = function(reduceFunction) {
    return new Reducer(reduceFunction);
};

function Reducer(reduceFunction) {
  if (!(this instanceof Reducer)) return new Reducer(Reducer);
  this._reduceFunction = reduceFunction;
}

inherits(Reducer, mapjs.Reducer);

exports.Reducer = Reducer;
