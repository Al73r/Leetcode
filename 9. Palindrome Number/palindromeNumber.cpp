class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        int sum=0, y = x;
        while(x>0)
        {
            sum = sum*10+x%10;
            x = x/10;
        }
        return y == sum;        
    }
};