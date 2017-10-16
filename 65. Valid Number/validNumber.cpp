class Solution {
public:
    bool isNumber(string s) {
        bool exp=false, point=false, num=false;
        int i=0, start, end, epos, ppos;
        while(i<s.size() && s[i]==' ') i++;
        if(s[i]=='-' || s[i]=='+') i++;
        start = i;
        while(i<s.size() && s[i]!=' '){
            if(s[i]=='e'){
                if(exp) return false;
                exp = true;
                epos = i;
                if(i+1<s.size() && (s[i+1]=='-' || s[i+1]=='+')) i++;
            }
            else if(s[i]=='.'){
                if(point||exp) return false;
                point =true;
                ppos = i;
            }
            else if(s[i]<'0' || s[i]>'9')
                return false;
            else{
                num = true;
            }
            i++;
        }
        end = i-1;
        if(exp && (
            (start == epos || end == epos) || (epos+1<s.size() && (s[epos+1]=='-' || s[epos+1]=='+') && (epos+1==end))
        )) return false;
        if(!num || (exp && point && ppos==start && ppos==epos-1)) return false;
        while(i<s.size() && s[i]==' ') i++;
        return i==s.size();
    }
};