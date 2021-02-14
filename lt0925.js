// https://leetcode-cn.com/problems/long-pressed-name/
// long pressed name
/**
 * @param {string} name
 * @param {string} typed
 * @return {boolean}
 */
var isLongPressedName = function (name, typed) {
    if (name === typed) return true;
    if (name.length > typed.length) return false;
    let left = 0, right = 0;
    while (name[left] && typed[right]) {
        if (name[left] === typed[right]) {
            left++;
            right++;
        } else {
            right++;
        }
    }
    return left === name.length;
};