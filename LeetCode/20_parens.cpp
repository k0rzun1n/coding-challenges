#include "LeetCode.h"
unordered_map<char, char> cb{
    {'(', ')'},
    {'[', ']'},
    {'{', '}'}};
class Solution {
   public:
    bool isValid(string s) {
        stack<char> t;
        for (char c : s)
            if (!t.empty() && cb[t.top()] == c)
                t.pop();
            else
                t.push(c);

        return t.empty();
    }

    bool isValid2(string s) {
        vector<char> zt(26);
        int top = -1;
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            if (top != -1 && cb[zt[top]] == c) {
                top--;
            } else {
                zt[++top] = c;
            }
        }
        return top == -1;
    };
};
int main() {
    Solution q;
    cout << endl
         << q.isValid2("([{}]{}{}{}[])");
    return 0;
}