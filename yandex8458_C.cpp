#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    set<int> nums;

    int val;
    for (int i = 0; i < n; i++) {
        cin >> val;
        if (nums.insert(val).second)
            cout << val<<endl;
    }

    return 0;
}