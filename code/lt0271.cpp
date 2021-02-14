#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
using namespace std;

class Codec {
public:

    string encode(vector<string>& strs) {
        if(strs.empty())
            return {};
        stringstream ss;
        for(int i = 0; i < strs.size(); i++)
            ss << strs[i].size() << " " << strs[i];
        return ss.str();
    }
                            
    vector<string> decode(string s) {
        int size;
        string tmp;
        stringstream ss(s);
        vector<string> res;
        while(ss >> size >> setw(size) >> tmp)
            res.push_back(tmp);
        return res;
    }
};

int main()
{
    stringstream ss;
    int v = 5;
    ss << setw(10) << left << 5;
    ss << 3;
    ss << 1;
    cout << ss.str() << endl;
    return 0;
}