//https://leetcode.com/problems/smallest-number-in-infinite-set/description/
class SmallestInfiniteSet {
public:
    int cnt[1001];
    SmallestInfiniteSet() 
    {
       for(int i=1;i<=1000;i++)
        {
            cnt[i]=1;
        }
    }
    
    int popSmallest() 
    {
        for(int i=1;i<=1000;i++)
        {
            if(cnt[i]==1)
            {
                cnt[i] = 0;
                return i;
            }
        }
        return -1;
    }
    void addBack(int num) 
    {
        cnt[num]=1;
    }
};
