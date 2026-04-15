# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        fast = head
        slow = head

        while fast != None and fast.next != None:
            slow = slow.next
            fast = fast.next.next

        list2 = slow.next
        slow.next = None
        curr = list2
        prev =None
        while curr:
            next_node = curr.next
            curr.next = prev
            prev = curr
            curr = next_node
        list2 = prev
        first = head
        while list2:
            tmp1 = first.next
            tmp2 = list2.next

            first.next = list2
            list2.next = tmp1

            first = tmp1
            list2 = tmp2