/*
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]

Input: list1 = [], list2 = []
Output: []

Input: list1 = [], list2 = [0]
Output: [0]
*/

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
public: // as we merged the sorted arrays we can use that type of login here
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy; // we will make a new linked list , dummy is the head of the new linked list
        ListNode* temp = &dummy; // temp is the pointer to the dummy linked list, so we don't lost out head.

        while((list1 != nullptr) && (list2 != nullptr)) { // until both becomes null we will iterate through the linked list
            if(list1->val < list2->val) { // we have to make the merged list sorted so we can say 
            // when value of the first is less-then then we will insert it to the dummy 
                temp->next = list1;
                list1 = list1->next; //stepping up after storing the node into ans list
            }
            else {
                temp->next = list2;
                list2 = list2->next; //stepping up after storing the node into ans list
            }
            temp = temp->next;
        }

        if (list1 != nullptr) { // after the loop is over one node will be remaining and so we have to store it into ans list
            temp->next = list1;
        } else {
            temp->next = list2;
        }

        return dummy.next;
    }
};