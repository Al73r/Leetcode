class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        const int MAX_CHAR = 256;
        int pos[MAX_CHAR];
        for(int i=0; i<MAX_CHAR; i++){
            pos[i] = -1;
        }
        int i = 0, j = 0;
        int rlt = 0;
        while(j < s.length()){
            if(pos[s[j]] >= i){
                i = pos[s[j]] + 1;
            }
            else{
                if( j-i+1 > rlt){
                    rlt = j-i+1;
                }
            }
            pos[s[j]] = j;
            j++;
        }
        return rlt;
    }
};