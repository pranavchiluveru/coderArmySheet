class RandomizedSet {
public:
    vector<int> v;
    unordered_map<int,int> mpp;//stores val,index in v
    RandomizedSet() {
       
    }
    
    bool insert(int val) {
        if(mpp.find(val)!=mpp.end())
        {
            return false;
        }
        v.push_back(val);
        int index=v.size()-1;
        mpp[val]=index;
        return true;
    }
    
    bool remove(int val) {
        if(mpp.find(val)==mpp.end())
            return false;
        int index=mpp[val];
        int last_ele=v.back();
        v.pop_back();
        v[index]=last_ele;
        mpp[last_ele]=index;
        mpp.erase(val);
        return true;
    }
    
    int getRandom() {
        int rand_index=rand()%v.size();
        return v[rand_index];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
