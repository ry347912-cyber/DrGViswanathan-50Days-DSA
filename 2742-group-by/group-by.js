/**
 * @param {Function} fn
 * @return {Object}
 */
Array.prototype.groupBy = function(fn) {
    const result = {};
    
    for (let i = 0; i < this.length; i++) {
        const item = this[i];
        const key = fn(item);
        
        // If the key doesn't exist yet, initialize it with an empty array
        if (!result[key]) {
            result[key] = [];
        }
        
        // Push the current item into the corresponding group
        result[key].push(item);
    }
    
    return result;
};

/**
 * [1,2,3].groupBy(String) // {"1":[1],"2":[2],"3":[3]}
 */