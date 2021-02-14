// https://leetcode-cn.com/problems/calculator-lcci/
// calculator lcci
class Solution {
public:
    int calculate(string s) {
		stack<long long> is;
		size_t size = s.size();
		long long num = 0;
        char op = '+';
		for(int i = 0; i < size; i++){
			if(s[i] >= '0' && s[i] <= '9')
				num = num * 10 + s[i] - '0';
            
            if(i == size - 1 || (s[i] != ' ' && s[i] < '0' || s[i] > '9')) {
                switch(op){
                    case '-':
                        num = -num;
                    case '+':
                        is.push(num);
                        break;
                    case '*':
                        num = num * is.top();
                        is.pop();
                        is.push(num);
                        break;
                    case '/':
                        num = is.top() / num;
                        is.pop();
                        is.push(num);
                        break;                        
                }
                num = 0;

                op = s[i];
            }
		}
        int res = 0;
        while(is.size()){
            res += is.top();
            is.pop();
        }
		return res;
    }
};


