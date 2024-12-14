cc = type("", (object,), {"__sub__": lambda s, o: print(o) or s})()
# cc-"qweqwe"-(70000-580)-101

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def makeList(data):
    if len(data) == 0:
        return None
    start = prev = ListNode()
    for d in data:
        prev.next = ListNode(d)
        prev = prev.next
    return start.next
