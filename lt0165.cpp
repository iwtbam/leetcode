#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> v1 = to_vector(version1);
        vector<int> v2 = to_vector(version2);
        size_t size = min(v1.size(), v2.size());
        for(int i = 0; i < size; i++)
        {
            if(v1[i] == v2[i])
                continue;
            else if(v1[i] > v2[i])
                return 1;
            else
                return -1;
        }
        
        if(v1.size() == v2.size())
            return 0;
        
        return v1.size() < v2.size() ? -1 : 1;
    }

    vector<int> to_vector(const string& version)
    {
        string temp = version;
        vector<int> res = {};
        while(temp.size())
        {
            int pos = temp.find('.');
            string v = temp.substr(0, pos);
         
            int zero_pos = 0;
            while(v[zero_pos]=='0')
                zero_pos++;
            v = v.substr(zero_pos);
            if(v.empty())
                v = "0";
            res.push_back(stoi(v));  
            temp = pos==string::npos ? "" : temp.substr(pos + 1);
          
        }
        
        while(res.size()  && res.back() == 0)
            res.pop_back();

        return res;
    }
};