var mapjs = require('../mapjs');
var inherits = require('utils').inherits;

function InputSplit(value) {
  if (!(this instanceof InputSplit)) return new InputSplit(value);
  this.value = value;
}

exports.InputSplit = InputSplit;
