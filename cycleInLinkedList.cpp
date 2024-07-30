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

//below is modified version of floyd's cycle detection algorithm
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == nullptr) return false; //checking if head is null then return false that cycle don't exits
        //making two pointers where one go fast and second go slow (one goes two steps and other goes one step)
        ListNode* tortoise = head;
        ListNode* hare = head->next;

        while(hare) {
            if(hare == tortoise) return true; //checking if both are at same position then cycle is present 
            // then we will return true that cycle is present
            hare = hare->next; // if condition is false then we will increase hare by one step
            if(hare!=nullptr) hare = hare->next; // now we will check if next step is null or not then we will go further
            tortoise = tortoise->next; // as usual we will step up tortoise by one
        }
        return false; //if hare becomes null then loop will end and no cycle detected so we will return false
    }
};