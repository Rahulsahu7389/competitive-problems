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
    
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL){
            return head;
        }
        ListNode * p1 = head;
        ListNode * p2 = p1->next;//to keep track of the 
        while(p1!=NULL && p2!=NULL){
            if(p2->val == val){
                p1->next = p2->next;
                p2 = p1->next;
            }
            else{
                p1 = p1->next;
                p2 = p2->next;
            }
        }
        if(head->val==val){
            head = head->next;
        }
        return head;
        
    }
};

// ####recursive code
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
    void recur(ListNode* p1, ListNode* p2 , int val){
        if(p1 == NULL || p2 == NULL){
            return;
        }
        if(p2->val == val){
            p1->next = p2->next;
            recur(p1,p1->next,val);
            // p2 = p1->next;
        }
        else{
            recur(p1->next,p2->next,val);
            // p1 = p1->next;
            // p2 = p2->next;
        }
    }
    
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL){
            return head;
        }
        ListNode * p1 = head;
        ListNode * p2 = p1->next;//to keep track of the 
        // while(p1!=NULL && p2!=NULL){
        //     if(p2->val == val){
        //         p1->next = p2->next;
        //         p2 = p1->next;
        //     }
        //     else{
        //         p1 = p1->next;
        //         p2 = p2->next;
        //     }
        // }
        recur(p1,p2,val);
        if(head->val==val){
            head = head->next;
        }
        return head;
        
    }
};