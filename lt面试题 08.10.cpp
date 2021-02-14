// https://leetcode-cn.com/problems/color-fill-lcci/
// color fill lcci
class Solution {
public:

    int dxs[4] = {0, 0, -1, 1};
    int dys[4] = {1, -1, 0, 0};

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int rows = image.size();
        if(rows == 0)
            return {};
        int cols = image[0].size(); 
        if(cols == 0)
            return {};
        
        if(image[sr][sc] == newColor)
            return image;

        int oldColor = image[sr][sc];

        queue<pair<int, int>> q;
        q.push({sr, sc});
        image[sr][sc] = newColor;
        while(q.size()){
            auto [sr, sc] = q.front();
            q.pop();
            for(int i = 0; i < 4; i++){
                int nr = sr + dxs[i];
                int nc = sc + dys[i];
                if(nc < 0 || nr < 0 || nr >= rows || nc >= cols || image[nr][nc] != oldColor)
                    continue;
                
                q.push({nr, nc});
                image[nr][nc] = newColor;
            }
        }

        return image;
    }
};