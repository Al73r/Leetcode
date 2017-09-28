class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        int wl=words[0].size(), sl=s.size(), n=words.size();
        unordered_map<string, int> dict;
        for(int i=0; i<n; i++)
            dict[words[i]]++;
        
        unordered_map<string, int> times;
        int left=0, count=0;
        
        while(left+n*wl<=sl){
            //fill 
            if(count==0){ 
                for(int i=left; i<sl && count<n; i+=wl){
                    string str = s.substr(i, wl);
                    if(dict.count(str)){
                        times[str]++;
                        count++;
                    }
                    else{
                        times.clear();
                        count=0;
                    }
                }
                if(count<n) return ans;
            }

            //vaild?
            bool valid=true; 
            for(int i=0; i<n; i++){
                if(dict[words[i]]!=times[words[i]]) {
                    valid=false;
                    break;
                }
            }
            if(valid){
                ans.push_back(left);
            }

            //next
            string str = s.substr(left, wl); 
            times[str]--;
            str = s.substr(left+wl*n, wl);
            if(dict.count(str)){
                times[str]++;
            }
            else{
                times.clear();
                count=0;
                left += (wl+1)*n;
            }
        }
        return ans;
    }
};