// Given the head of a linked list, remove the nth node from the end of the list and return its head.

 

// Example 1:


// Input: head = [1,2,3,4,5], n = 2
// Output: [1,2,3,5]
// Example 2:

// Input: head = [1], n = 1
// Output: []
// Example 3:

// Input: head = [1,2], n = 1
// Output: [1]
 

// Constraints:

// The number of nodes in the list is sz.
// 1 <= sz <= 30
// 0 <= Node.val <= 100
// 1 <= n <= sz
 

 /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       if(head->next==NULL) return NULL;//case of 1 node
       ListNode *prev=head;
       ListNode *cur=head;
       while(n)//first move cur
       {
           cur=cur->next;
           n--;
       }
       if(cur==NULL) return head->next;//case of only 2 nodes
       while(cur->next)//move prev so it will make diff of n from last where we want to delet node
       {
           prev=prev->next;
           cur=cur->next;
       }
       prev->next=prev->next->next;//we reached that position from last now delet that node 
        return head;
    }
    
};