//https://practice.geeksforgeeks.org/problems/queue-operations/1
unordered_map<int,int> mp;
    void insert(queue<int> &q, int k){
        q.push(k);
        mp[k]++;
    }
    
    
    int findFrequency(queue<int> &q, int k)
    {
        return mp[k];
    }
