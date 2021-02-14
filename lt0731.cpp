// https://leetcode-cn.com/problems/my-calendar-ii/
// my calendar ii
class MyCalendarTwo {
public:
    MyCalendarTwo() {

    }
    
    bool book(int start, int end) {
        bounds[start]++;
        bounds[end]--;

        int num = 0;
        for(auto &[t, c] : bounds) {
            num += c;
           
            if(num >= 3){
                bounds[start]--;
                bounds[end]++;
                return false;
            }
            
        }

        return true;
    }
private:
    map<int, int> bounds;
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */