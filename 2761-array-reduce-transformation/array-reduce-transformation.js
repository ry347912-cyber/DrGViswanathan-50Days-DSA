/**
 * @param {number[]} nums
 * @param {Function} fn
 * @param {number} init
 * @return {number}
 */
var reduce = function(arr, fn, init) {
    let res = init;
    
    for (let i = 0; i < arr.length; i++) {
        res = fn(res, arr[i]);
    }
    
    return res;
};