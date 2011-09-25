var Mapper = require('../mapper').Mapper;

var f = function(key, value) {

    console.log(key + value);
};

var mapper = new Mapper();

mapper.map(f);
