#include <string>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        string s = to_string(N);
        int size = s.size();
        int pos = size;
        for(int i = size - 1; i >= 1; i--){
            if(s[i] < s[i-1]){
                pos = i - 1;
                s[pos]--;
            }
        }

        for(int i = pos + 1; i < size; i++)
            s[i] = '9';
        
        int i = 0;
        while(s[i] == '0')
            i++;

        return atoi(s.substr(i).c_str());
    }
};;