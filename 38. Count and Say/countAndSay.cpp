class Solution {
public:
    string countAndSay(int n) {
        string input, output="1";
        n--;
        while(n--){
            input = output;
            output.clear();
            int i=0;
            while(i<input.size()){
                int count=1;
                char ch=input[i];
                while(i+1<input.size() && input[i+1]==ch){
                    count++;
                    i++;
                }
                output += count + '0';
                output += ch;
                i++;
            }
        }
        return output;
    }
};