var mapjs = require('../mapjs');
var inherits = require('util').inherits;

function Reducer(reduceFunction) {
  if (!(this instanceof Reducer)) return new Reducer(Reducer);
  this._reduceFunction = reduceFunction;
}

inherits(Reducer, mapjs.Reducer);

exports.Reducer = Reducer;

exports.createReducer = function() {
    return new Reducer(arguments[0]);
};

Reducer.prototype.reduce = function(outputCollector) {

    if(!this._reduceFunction) throw new Error("Reducer.reduce fail. No reduce function specified.");
    if(!this.key) throw new Error('Reducer.reduce fail. No key specified.');
    if(!this.values) throw new Error('Reducer.reduce fail. No values specified.');
    this._reduceFunction(this.key, this.values, outputCollector, null);
};

Reducer.prototype.clone = function() {

    return new Reducer(this._reduceFunction);
};
