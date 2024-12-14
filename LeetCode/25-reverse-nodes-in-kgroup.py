from LeetCodeH import *


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        if k == 1:
            return head
        a = b = head
        c: ListNode = None
        d: ListNode = None
        len_ = 0
        while head:
            head = head.next
            len_ += 1
        for i in range(len_ // k):
            for _ in range(k - 1):
                b = b.next
            if d:
                d.next = b
            b = b.next
            d = a
            for _ in range(k):
                c, a.next = a.next, b
                b, a = a, c

            if not i:
                head = b
            b = c
        return head


if __name__ == "__main__":
    q = Solution()
    data = [0, 1, 2, 3, 4, 5, 6, 7]
    d = makeList(data)
    d = q.reverseKGroup(d, 3)
    while d:
        print(d.val, end=" ")
        d = d.next
