// https://leetcode-cn.com/problems/bulls-and-cows/
// bulls and cows
class Solution {
public:
    string getHint(string secret, string guess) {
        vector<int> record(10, 0);
        size_t size = secret.size();
        
        int A = 0, B = 0;

        for(int i = 0; i < size; i++){
            if(secret[i] == guess[i])
                A++;
            else{
                if(record[secret[i] - '0']++ < 0)
                    B++;
                if(record[guess[i] - '0']-- > 0)
                    B++;
            }
        }


        return to_string(A) + "A" + to_string(B) + "B";
    }
};