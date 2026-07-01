class MyHashSet {
public:

    vector<int> hashset;
    MyHashSet() {
        
    }
    
    void add(int key) {
        auto pt = find(hashset.begin(), hashset.end(), key);
        if(pt == hashset.end()) {
            hashset.push_back(key);
        }
    }
    
    void remove(int key) {
        auto pt = find(hashset.begin(), hashset.end(), key);
        if(pt != hashset.end()) {
            hashset.erase(pt);
        }
    }
    
    bool contains(int key) {
        auto pt = find(hashset.begin(), hashset.end(), key);
        return pt != hashset.end();
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */