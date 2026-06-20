/**
 * @param {Array} arr1
 * @param {Array} arr2
 * @return {Array}
 */
var join = function(arr1, arr2) {
    const resultObj = {};
    
    // Add all elements from arr1 into the storage object mapped by their id
    for (let i = 0; i < arr1.length; i++) {
        resultObj[arr1[i].id] = arr1[i];
    }
    
    // Merge or override with elements from arr2
    for (let i = 0; i < arr2.length; i++) {
        const item = arr2[i];
        if (resultObj[item.id]) {
            // If the id exists, spread properties from arr1's item then override with arr2's item
            resultObj[item.id] = { ...resultObj[item.id], ...item };
        } else {
            // If the id doesn't exist, simply insert the new item
            resultObj[item.id] = item;
        }
    }
    
    // Convert object values back to an array and sort them dynamically by id
    return Object.values(resultObj).sort((a, b) => a.id - b.id);
};