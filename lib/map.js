var mapjs = require('../mapjs');
var inherits = require('util').inherits;

function Mapper(mapFunction) {
    if (!(this instanceof Mapper)) return new Mapper(mapFunction);
    this._mapFunction = mapFunction;
}

Mapper.prototype.map = function() {
    console.log("Inside Mapper.prototype.map");
    if(this._mapFunction) throw new Error("Mapper.map fail. No map function specified");

    var string = 'var value = {0};' + this._mapFunction.toString();
    fs.write('./tmp_worker.js', string);

    var worker = new Worker('./tmp_worker.js');
    worker.addEventListener('message', function(event) { return event.data }, false);
    worker.postMessage();
};

inherits(Mapper, mapjs.Mapper);

exports.Mapper = Mapper;

exports.createMapper = function(mapFunction) {
    return new Mapper(mapFunction);
};

