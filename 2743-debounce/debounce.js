/**
 * @param {Function} fn
 * @param {number} t milliseconds
 * @return {Function}
 */
var debounce = function(fn, t) {
    let timerId;
    
    return function(...args) {
        // Clear the previous active timeout if it exists
        clearTimeout(timerId);
        
        // Start a new timeout delay window
        timerId = setTimeout(() => {
            fn(...args);
        }, t);
    };
};

/**
 * const log = debounce(console.log, 100);
 * log('a'); // cancelled
 * log('b'); // cancelled
 * log('c'); // logs "c" after 100ms
 */