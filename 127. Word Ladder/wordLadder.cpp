class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if(dict.find(endWord)==dict.end()) return 0;
        unordered_set<string> current, visited;
        current.insert(beginWord);
        int cnt=1;
        while(!current.empty()) {
            unordered_set<string> next;
            unordered_set<string> next_visited(visited);
            for(auto word: current){
                if(word==endWord)
                    return cnt;
                auto parent=word;
                for(int i=0; i<word.size(); i++) {
                    for(char ch='a'; ch<='z'; ch++) {
                        swap(word[i], ch);
                        if(dict.find(word)!=dict.end() && visited.find(word)==visited.end()) {
                            next_visited.insert(word);
                            next.insert(word);
                        }
                        swap(word[i],ch);
                    }
                }
            }
            cnt++;
            current = next;
            visited = next_visited;
        }
        return 0;
    }
};