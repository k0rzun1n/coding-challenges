#include "LeetCode.h"

int main() {
    vector<string> q{"qa", "zaz", "qazabc", "qaza"};
    // sort(q.begin(), q.end(), pp);
    sort(q.begin(), q.end(),
         [](const string &a, const string &b) { return a.size() < b.size(); });
    cc, q;
    // string_view
    unordered_map<string_view, int> um;
    string e = "eee";
    string d = "qweee";
    um.insert({e,5});
    string_view w = d.substr(2);
    
    cc,um.find(w)==um.end();

    // int i = 5;
    // i|=(1<<31);
    // // i;
    // cc,bitset<8>(i);
    // cc,i;
    // cc,1<<31;

    return 0;
}
