#include <string>

using namespace std;

class Solution {
public:
    bool canTransform(string start, string end) {
        int size = start.size();
        if(size != end.size())
            return false;

        string nox_start = remove_x(start);
        string nox_end = remove_x(end);

        if(nox_end != nox_start)
            return false;
        return check(end, start, 'L') && check(start, end, 'R');
    }

    bool check(const string& start, const string& end, char c){
        int e = 0, size = start.size();
        for(int i = 0; i < size; i++){
            if(start[i] == c){
                while(e < size && end[e]!= c)
                    e++;
                if(e < i)
                    return false;
                e++;
            }
        }
        return true;
    }


    string remove_x(string str){
        string res = {};
        int size = str.size();
        for(int i = 0; i < size; i++){
            if(str[i] == 'X')
                continue;
            res.push_back(str[i]);
        }
        return res;
    }
};