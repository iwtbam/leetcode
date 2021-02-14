#include <string>

using namespace std;

class Solution {
public:
    string toHex(int num){
        int unsigned_num = static_cast<unsigned>(num);
        string result = {};
        while(unsigned_num){
            result.push_back(record[unsigned_num % 16]);
            unsigned_num = unsigned_num / 16;
        }

        return {result.rbegin(), result.rend()};
    }
private:
    char record[16] = {
        '0', '1', '2', '3',
        '4', '5', '6', '7',
        '8', '9', 'a', 'b',
        'c', 'd', 'e', 'f'
    };
};