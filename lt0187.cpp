#include <set>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        set<string> s1;
        set<string> s2;
        int size = s.size();
        for(int i = 0; i < size - 10; i++){
            auto str = s.substr(0, 10);

            if(s1.find(str) == s1.end()){
                s1.insert(str);
            }
            else{
                s2.insert(str);
            }
        }    

        return {s2.begin(),  s2.end()};    
    }
};

