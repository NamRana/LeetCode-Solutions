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
        if(!head)   return head;
        unordered_map<Node*, Node*> copy;
        Node* it = head;
        while(it) if(!copy[it]) copy[it] = new Node(it->val), it = it->next;
        it = head;
        while(it) copy[it]->next = it->next ? copy[it->next] : nullptr, copy[it]->random = it->random ? copy[it->random] : nullptr, it = it->next;
        return copy[head];
    }
};