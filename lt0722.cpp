// https://leetcode-cn.com/problems/remove-comments/
// remove comments
class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        size_t line_no = source.size();
        vector<string> res;
        int state = 0, nstate = 0;

        unordered_map<char, unordered_map<int, int>> state_convert_table = 
        {
            {'.', {{0, 0}, {1, 0}, {2, 2}, {3, 3}, {4, 3}, {5, 0}}},
            {'*', {{0, 0}, {1, 3}, {2, 2}, {3, 4}, {4, 4}, {5, 0}}},
            {'/', {{0, 1}, {1, 2}, {2, 2}, {3, 3}, {4, 5}, {5, 1}}}
        };

        vector<vector<int>> state_table = {
            {0, 0, 2, 3, 3, 0},
            {0, 3, 2, 4, 4, 0},
            {1, 2, 2, 3, 5, 1}
        };

        string no_comment_line;
        for(int i = 0; i < line_no; i++){
            size_t width = source[i].size();
            for(int j = 0; j < width; j++){
                char c = source[i][j];
                int type = 0;
                if(c == '*')
                    type = 1;
                if(c == '/')
                    type = 2;
                
                nstate = state_table[type][state];

                if(nstate == 0 || nstate == 1){
                    no_comment_line.push_back(source[i][j]);
                }else if(state == 1 && (nstate == 2 || nstate == 3)){
                    no_comment_line.pop_back();
                }
                
                state = nstate;    
            }
            if(state != 3 && no_comment_line.size()){
                res.push_back(no_comment_line);
            }

            if(state != 3) {
                state = 0;
                no_comment_line.clear();
            }
        }

        return res;
    }
};