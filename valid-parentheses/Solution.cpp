// https://leetcode.com/problems/valid-parentheses

class Solution {
public:
    bool isValid(string s)
    {
        stack<char> st;
        map<char, char> mp = {{'{','}'}, {'(',')'}, {'[',']'}};
        for (auto i : s) {
            if (i == '(' or i == '{' or i == '[')
                st.push(i);
            else {
                if (st.empty() or i != mp[st.top()])
                    return false;
                st.pop();
            }
        }
        return st.empty();
    }
};