/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// class Solution {
// public:
//     bool hasCycle(ListNode *head) {
//         if(head == nullptr || head->next == nullptr) {
//             return false;
//         }

//         ListNode* slow = head;
//         ListNode* fast = head;
//         while(fast != nullptr && fast->next != nullptr) {
//             slow = slow->next;
//             fast = fast->next->next;
//             if(slow == fast) {
//                 return true;
//             }
//         }
//         return false;
//     }
// };

//below is modified version of floyd's cycle algorithm
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == nullptr) return false;
        ListNode* tortoise = head;
        ListNode* hare = head->next;

        while(hare) {
            if(hare == tortoise) return true;
            hare = hare->next;
            if(hare!=nullptr) hare = hare->next;
            tortoise = tortoise->next;
        }
        return false;
    }
};