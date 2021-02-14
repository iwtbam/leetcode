// https://leetcode-cn.com/problems/pacific-atlantic-water-flow/
// pacific atlantic water flow
class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        
        int rows = matrix.size();
        if(rows == 0)
            return {};
        int cols = matrix[0].size();
    
        memset(mark, 0, sizeof(mark));

        vector<vector<int>> res;

        vector<int> item(2, 0);

        queue<pair<int, int>> q;

        for(int i = 0; i < rows; i++){
            q.emplace(i, 0);
            q.emplace(i, cols - 1);    
            mark[i][0] |= 1;
            mark[i][cols - 1] |= 2;
        }

        for(int i = 0; i < cols; i++)
        {
            q.emplace(0, i);
            q.emplace(rows - 1, i);
            mark[0][i] |= 1;
            mark[rows - 1][i] |= 2;
        }

        while(q.size())
        {
            auto [cx, cy] = q.front();
            q.pop();
            for(int i = 0; i < 4; i++)
            {
                int nx = cx + dxs[i];
                int ny = cy + dys[i];
                if(nx < 0 || nx >= rows || ny < 0 || ny >= cols || matrix[nx][ny] < matrix[cx][cy])
                    continue;
                
                
                if(mark[nx][ny] >= (mark[cx][cy] | mark[nx][ny]))
                    continue;
                mark[nx][ny] = mark[cx][cy] | mark[nx][ny];
                q.emplace(nx, ny);
            }
        }

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(mark[i][j] == 3){
                    item[0] = i;
                    item[1] = j;
                    res.push_back(item);
                }
            }
        }

        return res;
    }

    

private:
    int dxs[4] = {0, 0, 1, -1};
    int dys[4] = {1, -1, 0, 0};
    int mark[151][151];
};