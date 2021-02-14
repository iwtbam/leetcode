// https://leetcode-cn.com/problems/text-justification/
// text justification
class Solution {
	public:
		vector<string> fullJustify(vector<string>& words, int maxWidth) {
			size_t size = words.size();
			int line = 0, start = 0;
			vector<string> res = {};
			for(int i = 0; i < size; i++){
                
				if(line + words[i].size() + i - start > maxWidth){
					string item = generate(words,  line, maxWidth - line, start, i);
					start = i;
					line = 0;
					res.push_back(item);
				};
				line = line + words[i].size();
				
			}

			string item = words[start];
            for(int i = start + 1; i < size; i++){
                item = item + " " + words[i];
            }
            if(item.size() < maxWidth){
                item = item + string(maxWidth - item.size(), ' ');
            }
			res.push_back(item);
			return res;
		}

		string generate(const vector<string>& words, int width, int space, int start, int end) {
			string res = words[start];
			int count = end - start - 1;
			if(count == 0){
				return res + string(space, ' ');
			}
			int s = space / count, r = space % count;
			for(int i = start + 1;  i < end; i++){
				if(r > 0){
					res = res + string(s + 1, ' ') + words[i];
					r--;
				}else{
					res = res + string(s, ' ') + words[i];
				}
			}
			return res;
		}
		
};