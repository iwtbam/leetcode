// https://leetcode-cn.com/problems/animal-shelter-lcci/
// animal shelter lcci
class AnimalShelf {
public:
    AnimalShelf() {
        time = 0;
    }
    
    void enqueue(vector<int> animal) {

        if(animal[1] == 0){
            q1.push({time, animal[0]});
        }else{
            q2.push({time, animal[0]});
        }
        time++;
    }
    
    vector<int> dequeueAny() {
        if(q1.size() == 0 && q2.size() == 0)
            return {-1, -1};
        pair<int, int> r;
        
        if(q1.size() == 0){
            return dequeueDog();
        }
        
        if(q2.size() == 0){
           return dequeueCat();
        }
        
        auto f1 = q1.front();
        auto f2 = q2.front();

        if(f1.first < f2.first){
            return dequeueCat();
        }

        return dequeueDog();    
    }
    
    vector<int> dequeueDog() {
        if(q2.size() == 0){
            return {-1, -1};
        }
        auto f = q2.front();
        q2.pop();
        return {f.second, 1};
    }
    
    vector<int> dequeueCat() {
        if(q1.size() == 0){
            return {-1, -1};
        }
        auto f = q1.front();
        q1.pop();
        return {f.second, 0};
    }
    queue<pair<int, int>> q1;
    queue<pair<int, int>> q2;
    int time = 0;
};

/**
 * Your AnimalShelf object will be instantiated and called as such:
 * AnimalShelf* obj = new AnimalShelf();
 * obj->enqueue(animal);
 * vector<int> param_2 = obj->dequeueAny();
 * vector<int> param_3 = obj->dequeueDog();
 * vector<int> param_4 = obj->dequeueCat();
 */