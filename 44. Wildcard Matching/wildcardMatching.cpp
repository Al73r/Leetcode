class Solution {
public:
    bool isMatch(string s, string p) {
        if(p.empty()) return s.empty();
        const char *pc=p.c_str();
        vector<pair<int, int>> strinfo; //(start pos, size)
        int i=0;
        while(i<p.size()){//get strinfo
            if(p[i]=='*'){
                while(i<p.size() && p[i]=='*')
                    i++;
            }
            int count = 0, pos = i;
            while(i<p.size() && p[i]!='*'){
                i++; count++;
            }
            strinfo.push_back(make_pair(pos, count));
        }
        int j=0, pos=0, rlt;
        if(strinfo[j].first==0){//start
            rlt = myfind(s, pc+strinfo[j].first, pos, strinfo[j].second);
            if(rlt==string::npos || rlt!=0) return false;
            pos = rlt + strinfo[j].second;
            j++;
        }
        if(j==strinfo.size()) return pos==s.size();
        while(j<strinfo.size()){//mid
            rlt = myfind(s, pc+strinfo[j].first, pos, strinfo[j].second);
            if(rlt==string::npos) return false;
            pos = rlt + strinfo[j].second;
            j++;
        }
        if(strinfo[j-1].second==0)//end
            return true;
        if(pos==s.size()) return true;
        rlt=myfind(s, pc+strinfo[j-1].first, s.size()-strinfo[j-1].second, strinfo[j-1].second);
        return rlt!=string::npos;
    }
private:
    int myfind(const string &s, const char* p, int pos, int n){
        if(n==0) return pos;
        int i=pos, j=0;
        while(i<s.size()){
            if(s[i]==p[j] || p[j]=='?'){
                i++; j++;
                if(j==n) return pos;
            }
            else{
                pos++;
                i=pos; j=0;
            }
        }
        return string::npos;
    }
};