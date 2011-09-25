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

exports.Mapper = Mapper;
