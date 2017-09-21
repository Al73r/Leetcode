class Solution {
public:
    int romanToInt(string s) {
        char symbol[]={'I', 'V', 'X', 'L', 'C', 'D', 'M'};
        int radix[]={1,5,10,50,100,500,1000};
        int ans=0, idx=s.size()-1;
        for(int i=0; i<7; i++){
            while(idx>=0 && s[idx]==symbol[i]){
                if(idx>=1 && i>=1 && s[idx-1]==symbol[(i-1)/2*2]){
                    idx -= 2;
                    ans += radix[i] - radix[(i-1)/2*2];
                }
                else{
                    idx--;
                    ans += radix[i];
                }
            }
        }
        return ans;
    }
};