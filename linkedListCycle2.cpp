/*
Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.

Do not modify the linked list.

Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle in the linked list, where tail connects to the second node.

Input: head = [1,2], pos = 0
Output: tail connects to node index 0
Explanation: There is a cycle in the linked list, where tail connects to the first node.

Input: head = [1], pos = -1
Output: no cycle
Explanation: There is no cycle in the linked list.
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public: // in this question as we can see we have to find the staring position of the cycle or node which is connected by the last node
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return nullptr; // we will return null if the list is empty or has only one node

        // we are using floyd's cycle detection algorithm or we can say tortoise and hare algorithm 
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) { // until fast pointer becomes null 
            slow = slow->next; // slow will go one step at a time
            fast = fast->next->next; // fast will go two steps at a time  
            if (slow == fast) break; // we will break the loop if the cycle is detected when we will know that , when that slow and fast will
            //meet in the cycle 
        }

        if (fast == nullptr || fast->next == nullptr) return nullptr; // edge case

        slow = head; // now we will initialize the slow at starting of the linked list 
        // and we will increase both by step one until both meet once again 
        // and thats the position where cycle started
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        // we can return fast or slow because both are at the same position and that's the ans...
        return slow;
        // return fast;
    }
};
