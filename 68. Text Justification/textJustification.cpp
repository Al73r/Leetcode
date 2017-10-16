class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int start=0, i, length, n;
        while(start<words.size()){
            i=start+1; length=words[start].size(); n=1;
            while(i<words.size() && length+words[i].size()+1<=maxWidth){
                length += words[i].size() + 1;
                i++; n++;
            }
            string tmp(words[start]);
            int nb, nbb;
            if(n>1 && i<words.size()){
                nb = (maxWidth - length + n - 1) / (n - 1);
                nbb = (maxWidth - length + n - 1) % (n - 1);
                for(int j=start+1; j<i; j++){
                    for(int k=0; k<nb; k++)
                        tmp += ' ';
                    if(j-start<=nbb)
                        tmp += ' ';
                    tmp += words[j];
                }
            }
            else {
                for(int j=start+1; j<i; j++){
                    tmp += ' ';
                    tmp += words[j];
                }
                while(tmp.size()<maxWidth) tmp += ' ';
            }
            ans.push_back(tmp);
            start = i;
        }
        return ans;
    }
};