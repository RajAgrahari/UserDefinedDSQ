//https://leetcode.com/problems/shuffle-an-array/description/
class Solution {
public:
   vector<int> ori;
   vector<int> ran;
   private: int randRange(int min, int max) {
        return (min + rand()%(max-min));
    }

    void swapAt(int i, int j) 
    {
        int temp = ran[i];
        ran[i] = ran[j];
        ran[j] = temp;
    }
    public:Solution(vector<int>& nums) {
        ori = nums;
        ran = nums;
    }
    
    vector<int> reset() {
        ran = ori;
        return ran;
    }
    
    vector<int> shuffle() {
        for(int i=0;i<ran.size();i++)
        {
            swapAt(i,randRange(i,ran.size()));
        }
        return ran;
    }
    
};
