#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex < 0)
            return {};
        
        if(rowIndex == 0)
            return {{1}};
        
        vector<int> row(rowIndex + 1, 1);
        for(int i = 1; i < rowIndex + 1; i++)
        {
            for(int j = i; j>=0 ; j--)
            {
                if(j==i || j==0)
                    row[j] = 1;
                else
                    row[j] = row[j] + row[j-1];
            }
        }
        
        return row;
    }
};