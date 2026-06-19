class Solution {
public:
    bool isPerfectSquare(int num) {
        long long low = 1;
        long long high = num; 
        long long mid;
        long long sq;

        while(low<=high)
        {
           mid = low + (high -low)/2;
           sq = mid*mid;
           if(sq==num)
             return true;
           else if(sq>num)
             high = mid-1;
           else
             low = mid + 1;
       
    
        }
          return false;
    }

};