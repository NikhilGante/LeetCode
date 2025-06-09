#include <bits/stdc++.h>
using namespace std;

class TimeMap {
    public:
        unordered_map<string, vector<pair<string, int>>> mp;
        TimeMap() {
        }
        
        void set(string key, string value, int timestamp) {
            mp[key].push_back({value, timestamp});
        }
        
        string get(string key, int timestamp) {
            vector<pair<string, int>>& arr = mp[key];
            string str;
            int l = 0, r = arr.size() - 1;
            while(l <= r){
                int mid = l + (r - l)/2;
                int cur_time = arr[mid].second;
                if(cur_time > timestamp)    r = mid - 1;
                else if(cur_time < timestamp){
                    str = arr[mid].first;
                    l = mid + 1;
                }
                else return arr[mid].first;
            }
            return str;
        }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */