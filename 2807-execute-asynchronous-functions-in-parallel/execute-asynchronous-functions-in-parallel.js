/**
 * @param {Array<Function>} functions
 * @return {Promise<any>}
 */
var promiseAll = function(functions) {
    return new Promise((resolve, reject) => {
        const results = new Array(functions.length);
        let resolvedCount = 0;
        
        if (functions.length === 0) {
            resolve(results);
            return;
        }
        
        functions.forEach((fn, index) => {
            fn()
                .then((val) => {
                    results[index] = val;
                    resolvedCount++;
                    
                    // If all promises are resolved, return the accumulated array
                    if (resolvedCount === functions.length) {
                        resolve(results);
                    }
                })
                .catch((err) => {
                    // Reject immediately on the very first failure
                    reject(err);
                });
        });
    });
};

/**
 * const promise = promiseAll([() => new Promise(res => res(42))])
 * promise.then(console.log); // [42]
 */