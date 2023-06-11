//https://leetcode.com/problems/snapshot-array/description/
 unordered_map<int,map<int,int>> snaps;
    int s_id=0;
    SnapshotArray(int length) {
       for(int i=0 ; i<length ; i++)
        {
            map<int, int> mp;
            mp[0] = 0;
            snaps[i] = mp;
        }
    }
    
    void set(int index, int val) {
        snaps[index][s_id] = val;
    }
    
    int snap() {
        return s_id++;
    }
    
    int get(int index, int snap_id) 
    {
        auto temp = snaps[index].upper_bound(snap_id); 
        temp--;
        return temp->second;
    }
