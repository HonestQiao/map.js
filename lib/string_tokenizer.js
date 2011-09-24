function StringTokenizer(string) {
    
    assert(typeof(string)=='string');
    this._string = string;
    this._array = null;
}

StringTokenizer.prototype.split = function(delimiter, limit) {

    if(!delimiter) return this._string;

    this._array = this_string.split(delimiter, limit);
    
};

StringTokenizer.prototype.hasNextToken = function() {

    if(this._array && this._array.length > 0) {
        return true;
    }
    return false;
};

StringTokenizer.prototype.nextToken = function() {

    var nextToken = this._array.pop();
    return nextToken;
};
