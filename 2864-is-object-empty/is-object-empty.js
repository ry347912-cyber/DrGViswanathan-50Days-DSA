/**
 * @param {Object|Array} obj
 * @return {boolean}
 */
var isEmpty = function(obj) {
    // Since the input can be an array or an object, a simple for...in loop
    // checks for the existence of any iterable property (elements or keys).
    for (const key in obj) {
        return false;
    }
    return true;
};