class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        int wl=words[0].size(), sl=s.size(), n=words.size();
        unordered_map<string, int> dict;
        for(int i=0; i<n; i++)
            dict[words[i]]++;
        
        for(int group=0; group<wl; group++){
            unordered_map<string, int> times;
            for(int count=0, left=group; left+n*wl<=sl; left+=wl){
                for(int i=left+count*wl; count<n && i+wl<=sl; i+=wl){
                    string str = s.substr(i, wl);
                    times[str]++;
                    count++;
                }
                if(count<n)
                    return ans;
                
                bool valid=true; 
                for(int i=0; i<n; i++){
                    if(times.count(words[i])==0 || dict[words[i]]!=times[words[i]]) {
                        valid=false;
                        break;
                    }
                }
                if(valid){
                    ans.push_back(left);
                }
                string str=s.substr(left, wl);
                times[str]--;
                count--;
                
            }
        }
        return ans;
    }
};