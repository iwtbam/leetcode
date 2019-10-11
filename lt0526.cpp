#include <vector>
using namespace std;

class Solution {
public:
    int countArrangement(int N) {
        int total = 0;
        vector<int> visited(N, 0);
        helper(N, visited, 1, total);
        return total;
    }
    
    void helper(int N, vector<int>& visited, int pos,  int& total)
    {
        if(pos > N)
        {
            total++;
            return;
        }
        
        for(int i = 1; i <= N; i++)
        {
            if(!visited[i-1] && (i%pos == 0 || pos%i == 0)){
                visited[i-1] = 1;
                helper(N, visited, pos+1, total);
                visited[i-1] = 0;
            }
        }
    }  
};