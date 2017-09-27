class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty()) return 0;
        int i=0, j=0, start=0;
        while(i<haystack.size()){
            if(haystack[i]==needle[j]){
                i++; j++;
                if(j==needle.size())
                    return i-needle.size();
            }
            else{
                start++;
                i=start;
                j=0;
            }
        }
        return -1;
    }
};