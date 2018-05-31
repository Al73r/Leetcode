class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        int l=s.size();
        string ans;
        vector<string> result;
        for(int i=1; i<=3; i++){
            if(l-i>9 || l-i<3 || stoi(s.substr(0, i))>255 || (i>1 && s[0]=='0'))
                continue;
            ans+=s.substr(0,i)+".";
            for(int j=1; j<=3; j++){
                if(l-i-j>6 || l-i-j<2 || stoi(s.substr(i, j))>255 || (j>1 && s[i]=='0'))
                    continue;
                ans+=s.substr(i,j)+".";
                for(int k=1; k<=3; k++){
                    if(l-i-j-k>3 || l-i-j-k<1 || stoi(s.substr(i+j,k))>255 || stoi(s.substr(i+j+k,l-i-j-k))>255
                       || (k>1 && s[i+j]=='0') || (l-i-j-k>1 && s[i+j+k]=='0'))
                        continue;
                    ans+=s.substr(i+j,k)+"."+s.substr(i+j+k,l-i-j-k);
                    result.push_back(ans);
                    ans.erase(i+j+2);
                }
                ans.erase(i+1);
            }
            ans.erase(0);
        }
        return result;
    }
};