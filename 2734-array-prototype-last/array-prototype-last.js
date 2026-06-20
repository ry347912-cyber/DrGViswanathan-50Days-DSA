/**
 * @return {null|boolean|number|string|Array|Object}
 */
Array.prototype.last = function() {
    // If the array has elements, return the one at the final index
    if (this.length > 0) {
        return this[this.length - 1];
    }
    
    // Return -1 for an empty array
    return -1;
};

/**
 * const arr = [1, 2, 3];
 * arr.last(); // 3
 */