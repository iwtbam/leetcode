// https://leetcode-cn.com/problems/video-stitching/
// video stitching
class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        
        if(clips.size() == 0)
            return -1;
        
        
        sort(clips.begin(), clips.end(), 
             [](const vector<int>& v1, const vector<int>& v2){
                return v1[0] == v2[0] ? v1[1] < v2[1] : v1[0] < v2[0];      
             }
            );
        
        if(clips[0][0] > 0)
            return -1;
        
        int left  = 0;
        int count = 1;
        vector<int> ml = {0, 0};
        vector<int> pre = {0, 0};
        for(int i = 0; i < clips.size(); i++){
            vector<int> cur = clips[i];
            if(cur[0] > left){
                left = pre[1];
                ml = pre;
               // cout << pre[0] << " " << pre[1] << endl;
                count++;
                
            }
            
            if(cur[0] > ml[1])
                return -1;
            
            if(cur[1] >= T){
                //cout << cur[0] << " " << cur[1] << endl;
                return count;
            }
            
            pre = cur;
        }
        
        if(pre[1] < T)
            return -1;
        
        return count;
    }
};