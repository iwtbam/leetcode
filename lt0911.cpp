// https://leetcode-cn.com/problems/online-election/
// online election
class TopVotedCandidate {
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        size_t size = persons.size();
        this->times = times;
        vector<int> votes(size, 0);
        wins.resize(size, 0);
        int count = 0;
        for(int i = 0; i < size; i++){
            votes[persons[i]]++;
            if(votes[persons[i]] >= count){
                count = votes[persons[i]];
                wins[i] = persons[i];
            }else{
                wins[i] = wins[i - 1];
            }
           // cout << wins[i] << " ";
        }
        cout << endl;
    }
    
    int q(int t) {
        int l = 0, r = times.size() - 1;
        while(l < r){
            int mid = (l + r + 1) >> 1;
            if(times[mid] <= t){
                l = mid;
            }else{
                r = mid - 1;
            }
        }

        return wins[l];
    }

private:
    vector<int> wins;
    vector<int> times;
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */