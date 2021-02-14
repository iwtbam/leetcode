// https://leetcode-cn.com/problems/sort-array-by-parity-ii/
// sort array by parity ii
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        
        auto cmp = [](int x, int y)->bool 
		{
			return x % 2 < y % 2;
		};

		sort(A.begin(), A.end(), cmp);

		vector<int> sortedV;

		int halfSize = A.size() / 2;
		for (int i = 0; i < halfSize; i++) {
			sortedV.push_back(A.at(i));
			sortedV.push_back(A.at(i + halfSize));
		}
		return sortedV;
    }
};