
class Solution {
public:
    bool isPalindrome(string s) {
        int i=0, j=s.size()-1;
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        while(i<j){
            if(!::isalnum(s[i])) i++;
            else if(!::isalnum(s[j])) j--;
            else if(s[i]!=s[j]) return false;
            else {i++; j--;}
        }
        return true;
    }
};