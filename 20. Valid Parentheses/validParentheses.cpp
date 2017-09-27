class Solution {
public:
    bool isValid(string s) {
        stack<int> Stack;
        map<char, char> Map={{'(',')'}, {'{','}'}, {'[',']'}};
        for(auto ch: s){
            if(ch=='('||ch=='{'||ch=='[')
                Stack.push(ch);
            else{
                if((!Stack.empty())&&Map[Stack.top()]==ch)
                    Stack.pop();
                else
                    return false;
            }
        }
        if(Stack.empty())
            return true;
        else
            return false;
    }
};