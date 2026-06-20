/**
 * @param {Function} fn
 * @return {Function}
 */
var memoize = function(fn) {
    const cache = new Map();
    
    return function(...args) {
        // Stringify the arguments array to create a unique object/map key
        const key = JSON.stringify(args);
        
        if (cache.has(key)) {
            return cache.get(key);
        }
        
        const result = fn(...args);
        cache.set(key, result);
        return result;
    }
};

/** * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *	 callCount += 1;
 * return a + b;
 * })
 * memoizedFn(2, 2) // 4
 * memoizedFn(2, 2) // 4
 * console.log(callCount) // 1
 */