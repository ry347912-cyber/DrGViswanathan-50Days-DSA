/**
 * @param {Function} fn
 * @param {Array} args
 * @param {number} t
 * @return {Function}
 */
var cancellable = function(fn, args, t) {
    const timerId = setTimeout(() => {
        fn(...args);
    }, t);
    
    return function cancelFn() {
        clearTimeout(timerId);
    };
};

/**
 * const result = [];
 *
 * const log = (...args) => {
 * result.push({"time": Date.now() - start, "returned": fn(...args)});
 * }
 * * const cancel = cancellable(log, [2], 20);
 *
 * const maxLater = Math.max(10, 50);
 *
 * setTimeout(() => {
 * cancel();
 * console.log(result); // [{"time":20,"returned":10}]
 * }, maxLater);
 */