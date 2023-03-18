//https://leetcode.com/problems/design-browser-history/description/
class BrowserHistory {
public:
    vector<string> v;
    int i;
    BrowserHistory(string homepage) 
    {
       i=0;
       v.push_back(homepage); 
    }
    
    void visit(string url) {
        if(i<v.size()-1)
        v.erase(v.begin()+i+1,v.end());
        i++;
        v.push_back(url);
    }
    
    string back(int steps) 
    {
        if(steps>i)
        i=0;
        else
        i -= steps;
        return v[i];
    }
    
    string forward(int steps) 
    {
        if(steps > (v.size()-i-1))
        i = v.size()-1;
        else
        i += steps;
        return v[i];
    }
};
