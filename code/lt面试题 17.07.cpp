// https://leetcode-cn.com/problems/baby-names-lcci/
// baby names lcci
class Solution {
public:
    vector<string> trulyMostPopular(vector<string>& names, vector<string>& synonyms) {
        size_t size = names.size();
        for(int i = 0 ; i <size; i++)
        {
            auto [name, num] = parse_name(names[i]);
          //  cout << name <<" " << num << endl;
            add(name, num);
        }

        size = synonyms.size();

        for(int i = 0; i < size; i++)
        {
            auto [name1, name2] = parse_relation(synonyms[i]);
           // cout << name1 << " " << name2 << endl;
            merge(name1, name2);
        }

        vector<string> res;

        for(auto [cur, parent] : union_set)
        {
            if(cur == parent)
                res.push_back(cur + "(" + to_string(nums[cur]) + ")");
        }

        return res;
    }


    void add(const string& name, int num)
    {
        union_set[name] = name;
        nums[name] = num;
    }

    string parent(const string& name)
    {
        return union_set[name] == name ? name : parent(union_set[name]);
    }

    bool merge(const string& n1, const string& n2)
    {
        if(union_set.count(n1) == 0 || union_set.count(n2) == 0)
            return false;

        string p1 = parent(n1);
        string p2 = parent(n2);
        if(p1 == p2)
            return false;
    
        if(p1 > p2){
            union_set[p1] = p2;
            nums[p2] += nums[p1];
        }
        else{
            union_set[p2] = p1;
            nums[p1] += nums[p2];
        }

        return true;
    }

    pair<string, int> parse_name(const string& num)
    {
        int pos = 0, size = num.size();
        while(num[pos] != '(')
            pos++;
        return {num.substr(0, pos), stoi(num.substr(pos + 1, size - pos - 2))};
    }

    pair<string, string> parse_relation(const string& s)
    {
        int pos = 0, size = s.size();
        while(s[pos] != ','){
            pos++;
           // cout << s[pos] << endl;
        }
      //  cout << pos << endl;
        return {s.substr(1, pos - 1), s.substr(pos + 1, size - pos - 2)};
    }


private:
    unordered_map<string, string> union_set;
    unordered_map<string, int> nums;
};