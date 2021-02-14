// https://leetcode-cn.com/problems/additive-number/
// additive number
class Solution {
public:
    bool isAdditiveNumber(string num) {
        int size = num.size();
        for(int i = 0; i < size - 2; i++){
            if(i > 0 && num[0] == '0')
                return false;

            for(int j = i + 1; j < size - 1; j++){
                if(num[i + 1] == '0' && j - i > 1)
                    break;
                string n1 = num.substr(0, i + 1);
                string n2 = num.substr(i + 1, j - i);
                int k = j + 1;
                while(k < size){
                    string n3 = add(n1, n2);
                    // cout << n1 << " " << n2 << " " << n3 <<" ";
                    // if(k + n3.size() <= size)
                    //     cout << num.substr(k, n3.size());
                    // cout << endl;
                    if(k + n3.size() > size || n3 != num.substr(k, n3.size()))
                        break;
                    n1 = n2;
                    n2 = n3;
                    k += n3.size();
                   
                }

                if(k == size)
                    return true;
            }
        }

        return false;
    }

    string add(const string& n1, const string& n2){
        int co = 0;
        int p1 = n1.size() - 1, p2 = n2.size() - 1;
        int p3 = max(p1, p2) + 1;
        string res(p3 + 1, '0');
        res[0] = '1';
        while(p1 >= 0 || p2 >= 0){
            int left = p1 >= 0 ? n1[p1] - '0' : 0;
            int right = p2 >= 0 ? n2[p2] - '0' : 0;
            int sum = left + right + co;
            res[p3] = sum % 10 + '0';
            co = sum / 10;
            p1--;
            p2--;
            p3--;
        }
        if(co)
            return res;
        return res.substr(1);
    }
};
