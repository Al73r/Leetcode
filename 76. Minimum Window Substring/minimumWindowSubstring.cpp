class Solution {
public:
    string minWindow(string s, string t) {
        const int ASCII_MAX=256;
        int appeared[ASCII_MAX];
        int expected[ASCII_MAX];
        fill(appeared, appeared+ASCII_MAX, 0);
        fill(expected, expected+ASCII_MAX, 0);
        int wnd_min=INT_MAX, ans_start=0, ans_end=0;
        for(int i=0; i<t.size(); i++)
            expected[t[i]]++;
        int wnd_end, wnd_start=0, n_apd=0;
        for(wnd_end=0; wnd_end<s.size(); wnd_end++){
            if(expected[s[wnd_end]]>0){
                appeared[s[wnd_end]]++;
                if(appeared[s[wnd_end]]<=expected[s[wnd_end]])
                    n_apd++;
            }
            if(n_apd==t.size()){
                while(appeared[s[wnd_start]]>expected[s[wnd_start]] || expected[s[wnd_start]]==0){
                    if(expected[s[wnd_start]]>0) appeared[s[wnd_start]]--;
                    wnd_start++;
                }
                if(wnd_min>wnd_end-wnd_start+1){
                    wnd_min = wnd_end - wnd_start + 1;
                    ans_start = wnd_start; 
                    ans_end = wnd_start;
                }
            }
        }
        if(wnd_min==INT_MAX) return "";
        else return s.substr(ans_start, wnd_min);
    }
};