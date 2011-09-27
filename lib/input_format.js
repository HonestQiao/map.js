var mapjs = require('../mapjs');
var inherits = require('util').inherits;

function InputFormat(splitFunction) {
  if (!(this instanceof InputFormat)) return new InputFormat(splitFunction);
  this._splitFunction = splitFunction;
}

InputFormat.prototype.split = function(fileName) {
    if(this._splitFunction) return this._splitFunction(fileName);
};

exports.InputFormat = InputFormat;

exports.createInputFormat = function(splitFunction) {
    return new InputFormat(splitFunction);
};

