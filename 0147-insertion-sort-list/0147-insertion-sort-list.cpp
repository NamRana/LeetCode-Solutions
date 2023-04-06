class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(!head){return NULL;}
        vector<int>v;
        while(head){
            v.push_back(head->val);
            head=head->next;
        }
        for(int i=1; i<v.size(); i++){
            int j=i;
            while(j && v[j]<v[j-1]){
                swap(v[j], v[j-1]);
                j--;
            }
        }
        ListNode* root=NULL;
        for(int i=v.size()-1; i>=0; i--){
            ListNode* temp=new ListNode;
            temp->val=v[i];
            temp->next=root;
            root=temp;
        }
        return root;
    }
};