// https://leetcode-cn.com/problems/k-similar-strings/
// k similar strings
class Solution {
public:
    int kSimilarity(string A, string B) {
        size = A.size();
        return dfs(A, B, 0, 0);
    }

    int dfs(string& A, const string& B, int pos, int step)
    {

        while(pos < size && A[pos] == B[pos])
            pos++;

        if(pos == A.size())
            return step;

        int min_step = size;

        for(int i = pos + 1; i < size; i++)
        {
            if(A[i] != B[pos])
                continue;
            
            swap(A[i], A[pos]);
            min_step = min(min_step, dfs(A, B, pos + 1, step + 1));
            swap(A[i], A[pos]);
        }
        return min_step;
    }

    int f(const string& s1, const string& s2)
    {
        int error = 0;
        for(int i = 0; i < size; i++)
            error += s1[i] == s2[i] ? 0 : 1;
        return ceil(error / 2.0);
    }

    void swap(char& c1, char& c2){
        char t = c1;
        c1 = c2;
        c2 = t;
    }
private:
    size_t size;
};