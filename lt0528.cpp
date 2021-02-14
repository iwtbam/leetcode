// https://leetcode-cn.com/problems/random-pick-with-weight/
// random pick with weight
class Solution {
public:
    Solution(vector<int>& w) {
        size = w.size();
        sums.resize(size + 1, 0);
        for(int i = 0; i < size; i++)
            sums[i + 1] = sums[i] + w[i];
        
        // for(int i = 0; i <= size; i++)
        //     cout << sums[i] << " ";
        // cout << endl;
        srand((unsigned)time(nullptr));

    }
    
    int pickIndex() {
        int num = (rand() % sums[size]) + 1;
        // cout << num << endl;
        return search(1, size, num) - 1;
    }

    int search(int l, int r, int target){
        while(l < r){
            int mid = (l + r) >> 1;
            if(sums[mid] >= target){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        return l;
    }

private:
    vector<int> sums;
    size_t size;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */