var mapjs = require('../mapjs');
var inherits = require('utils').inherits;

function InputFormat(splitFunction) {
  if (!(this instanceof InputFormat)) return new InputFormat(splitFunction);
  this.splitFunction = splitFunction;
}

InputFormat.prototype.split = function() {

    if(this.splitFunction) return this.splitFunction.call();
};


exports.InputFormat = InputFormat;

var customSplit = function() {

    var inputSplits = [];

    fs.readFile.('./data.in', function(err, data) {
        var lines = data.split('\n');
        for(line in lines) {
            inputSplit.push(new InputSplit(line));
        }
    });
    
    return inputSplits;
};
