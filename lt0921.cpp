// https://leetcode-cn.com/problems/minimum-add-to-make-parentheses-valid/
// minimum add to make parentheses valid
class Solution {
public:
	int minAddToMakeValid(string S) {
		
		stack<char> ic;
		for (int i = 0; i < S.size(); i++) {
			char cur = S[i];
			if (!ic.empty()) {
				char top = ic.top();
				if (cur > top) {
					ic.pop();
				}else{
					ic.push(cur);
				}
			}
			else {
				ic.push(cur);
			}

		}
		return ic.size();
	}
};