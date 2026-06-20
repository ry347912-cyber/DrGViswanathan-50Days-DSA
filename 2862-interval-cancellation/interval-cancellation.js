/**
 * @param {Function} fn
 * @param {Array} args
 * @param {number} t
 * @return {Function}
 */
var cancellable = function(fn, args, t) {
    // 1. Execute the function immediately at 0ms
    fn(...args);
    
    // 2. Set up the recurring interval execution
    const timerId = setInterval(() => {
        fn(...args);
    }, t);
    
    // 3. Return the cancel function to clear the interval
    return function cancelFn() {
        clearInterval(timerId);
    };
};

/**
 * const result = [];
 *
 * const log = (...args) => {
 * result.push({"time": Date.now() - start, "returned": fn(...args)});
 * }
 * * const cancel = cancellable(log, [4], 35);
 * * setTimeout(() => {
 * cancel();
 * console.log(result); // Ready with interval snapshots!
 * }, 190);
 */