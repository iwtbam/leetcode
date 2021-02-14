#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//可以用树状数组

class NumArray {
public:

    NumArray(vector<int> nums):L(0), R(nums.size()-1){
        _seg.resize(nums.size() * 2);
        build(nums, 0, nums.size() - 1, 0);
    }

    void update(int i, int val) {
        update(L, R, i, val, 0);    
    }
    
    int sumRange(int i, int j) {
        return sumRange(L, R, i, j, 0);
    }

    void print()
    {
        for(int i = 0; i < _seg.size() ; i++)
            cout << _seg[i] << ends;
        cout << endl;
    }

private:
    void build(const vector<int> nums, int start, int end, int i)
    {
        if(start == end)
        {
            _seg[i] = nums[start];
            return;
        }
        int mid = (start + end) / 2;
        build(nums, start, mid, i * 2 + 1);
        build(nums, mid + 1, end, i * 2 + 2);
        _seg[i] = _seg[i * 2 + 1] + _seg[i * 2 + 2];
    }

    void update(int L, int R, int i, int val, int id)
    {
        if(L == R)
        {
            _seg[id] = val;
        }
        else
        {
            int mid = (L + R)/2;
            if(i <= mid)
                update(L, mid, i, val, id * 2 + 1);
            else
                update(mid + 1, R, i , val, id * 2 + 2);
             _seg[id] = _seg[id * 2 + 1] + _seg[id * 2 + 2];
        }
       
    }

    int sumRange(int L, int R, int qL, int qR, int i)
    {
        if(R < qL || L > qR )
            return 0;
        
        if(qL <= L && qR >= R)
            return _seg[i];

        int mid = (L + R) /2;
        return sumRange(L, mid, qL, qR, i * 2 + 1) + sumRange(mid + 1, R, qL, qR, i * 2 + 2);
    }

private:
    vector<int> _seg;
    int L;
    int R;
};

int main()
{
    vector<int> nums = {1, 3, 5};
    NumArray array(nums);
    int s = array.sumRange(0, 2);
    cout << s << endl;
    array.print();
    array.update(1, 2);
    array.print();
    s = array.sumRange(0, 2);
    cout << s << endl;
    return 0;
}


// template<typename _T, int N>
// class segment_tree
// {
// public:
//     void build(int start, int end, int idx)
//     {
//         if(nums[start] == nums[end])

//     }
// private:
//     _T num[N];
//     _T segment[N];
// }