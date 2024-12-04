#include <math.h>

#include <algorithm>
#include <bitset>
#include <cstdint>
#include <ctime>
#include <fstream>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

struct cd {
    template <typename T>
    cd& operator,(const T& v) {
        cout << v << " ";
        return *this;
    }
    template <typename T>
    cd& operator,(const vector<T>& v) {
        cout << "[ ";
        int vs = v.size();
        for (int i = 0; i < vs - 1; i++) cout << v[i] << ", ";

        if (vs) cout << v[vs - 1];

        cout << " ] " << endl;
        return *this;
    }
    template <typename T, typename Y>
    cd& operator,(const pair<T, Y>& v) {
        cout << "[ ";
        cout << v.first << ", ";
        cout << v.second;

        cout << " ] " << endl;
        return *this;
    }
    template <typename T, typename Y>
    cd& operator,(const unordered_map<T, Y>& um) {
        for (auto v : um) {
            cout << "[ ";
            cout << v.first << ", ";
            cout << v.second;
            cout << " ] " << endl;
        }
        return *this;
    }
    template <typename T>
    cd& operator,(const list<T>& v) {
        cout << "[ ";
        for (auto el : v) cout << el << " ";
        cout << "] " << endl;
        return *this;
    }
    // 2d
    template <typename T>
    cd& operator,(const vector<vector<T>>& v) {
        cout << "[ ";
        for (auto iv : v) {
            cout << "[";
            for (auto el : iv) cout << el << " ";
            cout << "] ";
        }
        cout << "] " << endl;
        return *this;
    }

    cd& operator~() {
        cout << endl;
        return *this;
    }
    cd& operator!() {
        cout << endl << "-------------------------" << endl;
        return *this;
    }
    ~cd() { cout << "\n"; }
};
auto cc = cd();

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
};

TreeNode* makeTree(vector<int> data) {
    queue<TreeNode*> qNode;
    auto root = new TreeNode(data[0]);
    qNode.push(root);
    int val;
    bool side = true;  // true l
    for (int i = 1; i < data.size(); i++) {
        TreeNode* n = qNode.front();
        val = data[i];
        // cc,val;
        if (side) {
            if (val != -1001) {
                n->left = new TreeNode(val);
                qNode.push(n->left);
            } else
                n->left = nullptr;
        } else {
            qNode.pop();
            if (val != -1001) {
                n->right = new TreeNode(val);
                qNode.push(n->right);
            } else
                n->right = nullptr;
        }
        side = !side;
    }
    return root;
}

uint32_t countSetBits(uint32_t n) {
    uint32_t count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}
uint32_t bitCount(uint32_t n) {
    n = n - ((n >> 1) & 0x55555555);
    n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
    return ((n + (n >> 4) & 0xF0F0F0F) * 0x1010101) >> 24;
}