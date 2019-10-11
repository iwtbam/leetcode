#include <vector>
#include <string>

using namespace std;

#if defined S1

//2019-08-07:23-03  回溯+减枝 超时了
class Solution {
public:
    int minStickers(vector<string>& stickers, string target) {
        int size = stickers.size();
        vector<vector<int>> records = {size, vector<int>(26, 0)};
        vector<int> s_record(26, 0);
        vector<int> t_record(26, 0);

        for(int i = 0; i < size; i++)
        {
            int ssize = stickers[i].size();
            for(int j = 0;  j < ssize; j++)
            {
                records[i][stickers[i][j] - 'a']++;
                s_record[stickers[i][j] - 'a'] = 1;
            } 
        }

        for(int i = 0; i < target.size(); i++)
        {
            if(s_record[target[i] - 'a'] == 0)
                return -1;
            t_record[target[i] - 'a']++;
        }
         
        helper(records, t_record, 0, 0);
        return min_time;
    }


    void helper(vector<vector<int>>& records, vector<int> t_record, int step, int num)
    {
        if(isvalid(t_record))
        {
            min_time = min(min_time, num);
            return;
        }

        if(num >= min_time)
            return;

        for(int i = step; i < records.size(); i++)
        {
            if(!check(t_record, records[i]))
                continue;
            
            helper(records, sub(t_record, records[i]), i, num+1);
        }
    }
    

    inline bool check(const vector<int>& a, const vector<int>& b)
    {
        for(int i = 0; i < 26; i++)
        {
            if(a[i] > 0 && b[i] > 0)
                return true;
        }
        return false;
    }
    
    inline vector<int> sub(const vector<int>& a, const vector<int>& b)
    {
        vector<int> res(26, 0);
        for(int i = 0; i < 26; i++)
            res[i] = a[i] - b[i];
        return move(res);
    }

    inline bool isvalid(vector<int>& a)
    {
   
        for(int i = 0; i < 26; i++)
            if(a[i] > 0)
                return false;
        return true;
    }

private:
    int min_time = INT_MAX;
};


#else


#endif