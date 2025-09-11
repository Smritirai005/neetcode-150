/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)return nullptr;
        Node* temp=head;
        while(temp!=NULL){
            Node* dummy=new Node(temp->val);
            dummy->next=temp->next;
            temp->next=dummy;
            temp=dummy->next;
        }
        temp=head;
        while(temp!=nullptr){
            if(temp->random){
                temp->next->random=temp->random->next;
            }
            temp=temp->next->next;
        }
        temp=head;
        Node* newHead=head->next;
        while(temp){
            Node* dummy=temp->next;
            temp->next=dummy->next;
            if(dummy->next){
                dummy->next=dummy->next->next;
            }
            temp=temp->next;
        }
        return newHead;

        
        
    }
};