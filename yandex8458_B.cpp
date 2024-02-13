#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::string;
using namespace std;

int main() {
    int n;
    cin >> n;

    int val;
    int best = 0;
    int cur = 0;
    for (int i = 0; i < n; i++) {
        cin >> val;
        if (val == 1) {
            cur++;
            if (cur > best) best = cur;
        } else {
            cur = 0;
        }
    }

    cout << best;

    return 0;
}