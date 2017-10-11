class Solution {
public:
    string longestPalindrome(string s) {
        const int MAX_STR = 1005;
        string str;
        for(int i=0; i<s.size(); i++){
            str.append("#");
            str.append(s, i, 1);
        }
        str.append("#");
        
        int pos=0, MaxRight=0, RL[MAX_STR*2+1]={0};
        for(int i=0; i<str.size(); i++){
            int j;
            if(i<MaxRight){
                j=min(RL[2*pos-i], MaxRight-i);
            }
            else{
                j=1;
            }
            while(i+j<str.size() && i-j>=0 && str[i-j]==str[i+j]){
                j++;
            }
            RL[i]=j;
            if(i+j-1>MaxRight){
                pos = i;
                MaxRight = i+j-1;
            }
        }
        int maxi=0, maxRL=0;
        for(int i=0; i<str.size(); i++){
            if(RL[i]>maxRL){
                maxRL = RL[i];
                maxi = i;
            }
        }
        return s.substr((maxi-maxRL+1)/2, maxRL-1);
    }
};