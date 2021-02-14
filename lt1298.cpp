// https://leetcode-cn.com/problems/maximum-candies-you-can-get-from-boxes/
// maximum candies you can get from boxes
class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        queue<int> q;
        list<int> locked_boxes = {};
        set<int> key_set = {};

        for(int box : initialBoxes){
            q.push(box);
        }

        int candy = 0;
        bool update =  true;

        while(q.size() && update){
            update = false;
            int size = q.size();
            bool key_update = false; 
            for(int i = 0; i < size; i++){
                int cur = q.front();
                q.pop();

                if(!status[cur] && key_set.find(cur) == key_set.end()){
                    q.push(cur);
                    continue;
                }

                update = true;

                candy += candies[cur];
                vector<int> contain_boxes = containedBoxes[cur];
                vector<int> contain_keys = keys[cur];
                int box_size = contain_boxes.size();
                int key_size = contain_keys.size();
                for(int i = 0; i < box_size; i++){
                    int box_id = contain_boxes[i];
                    // if(status[box_id] ){
                    //     q.push(box_id);
                    // }else{
                    //     locked_boxes.push_back(box_id);
                    // }
                    q.push(box_id);
                }

                key_update = key_size > 0 || box_size > 0;

                for(int i = 0; i < key_size; i++)
                    key_set.insert(contain_keys[i]);
            }

            // if(!key_update)
            //     continue;

            // int locked_boxes_size = locked_boxes.size();
            // for(auto iter = locked_boxes.begin(); iter != locked_boxes.end(); ){
            //     if(key_set.find(*iter)!=key_set.end()){
            //         q.push(*iter);
            //         iter = locked_boxes.erase(iter);
            //     }else{
            //         iter++;
            //     }
            // }
        }        


        return candy;
    }
};