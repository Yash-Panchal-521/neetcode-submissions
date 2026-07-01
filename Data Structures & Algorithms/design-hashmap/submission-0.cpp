class MyHashMap {
   public:
    vector<pair<int, int>> mp;
    MyHashMap() {}

    void put(int key, int value) {
        auto pt = find_if(mp.begin(), mp.end(),
                          [key](const pair<int, int>& p) { return p.first == key; });
        if (pt != mp.end()) {
            pt->second = value;
        } else {
            mp.push_back(make_pair(key, value));
        }
    }

    int get(int key) {
        auto pt = find_if(mp.begin(), mp.end(),
                          [key](const pair<int, int>& p) { return p.first == key; });
        if(pt != mp.end()) {
            return pt->second;
        } else {
            return -1;
        }
    }

    void remove(int key) {
        auto pt = find_if(mp.begin(), mp.end(),
                          [key](const pair<int, int>& p) { return p.first == key; });
        if(pt != mp.end()) {
            mp.erase(pt);
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */