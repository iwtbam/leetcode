bool isBadVersion(int version);
class Solution {
public:
    int firstBadVersion(int n) {
        long left = 1, right = n - 1;
        while(left  < right)
        {
            long mid = (left + right) / 2;
            if(isBadVersion(mid))
                right = mid - 1;
            else
            {
                if(isBadVersion(mid + 1))
                    return mid + 1;
                left = mid + 1;
            }
        }
        
        if(isBadVersion(left))
            return left;
        return left + 1;
        
    }
};