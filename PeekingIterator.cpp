//https://leetcode.com/problems/peeking-iterator/description/
class PeekingIterator : public Iterator {
public:
    queue<int> q;
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	     int i=0;
         while(i<nums.size())
         {
             q.push(nums[i]);
             i++;
         }
	    
	}
	
    
	int peek() 
    {
        return q.front();
        
	}
	
	
	int next() 
    {
	    int temp = q.front();
        q.pop();
        return temp;
       
	}
	
	bool hasNext() const 
    {
	    return !q.empty();
      
	}
};
