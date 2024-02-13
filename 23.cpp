#include <iostream>
#include <iterator>
#include <map>
#include <utility>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
   public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return nullptr;
        if (lists[0] == nullptr) return nullptr;
        multimap<int, ListNode*> front;
        ListNode* res_st;
        ListNode* res_end;

        for (auto L : lists) {
            if (L != nullptr)
                front.insert(pair<int, ListNode*>(L->val, L));
        }
        res_st = new ListNode();  //dummy
        res_end = res_st;

        while (front.size()) {
            auto itr = front.begin();
            auto nx = itr->second->next;
            if (nx) {
                cout << nx->val;
                front.insert({nx->val, nx});
            }
            res_end->next = itr->second;
            res_end = itr->second;
            front.erase(itr);
        }

        return res_st->next;
    }
};