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

// Brute force Approach :
// class Solution {
// public:
//     ListNode* removeNthFromEnd(ListNode* head, int n) {
//         ListNode* temp = head ;
//         int count = 0;

//         while(temp != NULL){
//             count ++;
//             temp = temp -> next ;
//         }

//         if(count == n){
//             return head->next;
//         }

//         int res = count - n - 1;

//         temp = head ;
//         while(res != 0){
//             temp = temp -> next ;
//             res -- ;
//         }

//         ListNode* delNode = temp -> next ;
//         temp -> next = temp -> next -> next ;
//         delete delNode;

//         return head ;
//     }
// };

// Optimized Approach : Slow and fast Pointer :

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head ;
        ListNode* slow = head ;

        for(int i = 0 ; i < n ; i++){
            fast = fast -> next ;
        }

        if(fast == NULL){
            return head -> next ;
        }

        while(fast -> next != NULL){
            slow = slow -> next ;
            fast = fast -> next ;
        }

        ListNode* delNode = slow -> next ;
        slow -> next = slow -> next -> next ;
        delete delNode ;

        return head ;
    }
};