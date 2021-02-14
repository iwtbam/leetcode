#include <string>
#include <sstream>
#include <iostream>

using namespace std;


class Solution{
public:
    int myAtoi(string str){
        int flag = 0;
        int sign = 0;
        int s = 0, l = 0;
        for(int i = 0; i < str.size(); i++)
        {
            if(str[i] ==' ')
            {
                if(!flag)
                    continue;
                return 0;
            }

            if(str[i] >='0' && str[i] <='9'){
                if(flag == 0){
                    s = i;
                    l = 1;
                    flag = 1;
                }else{
                    l++;    
                }

                continue; 
            }

            if(str[i] == '-' || str[i] == '+'){
                if(sign)
                    return 0;
                sign = (str[i] == '-') ? -1 : 1;

                continue;
            }

            if(flag == 0)
                return 0;
        }

        string data = str.substr(s, l);
        cout << data << endl;
        stringstream ss(data);

        int res;

        ss >> res;
        return res;
    }
};