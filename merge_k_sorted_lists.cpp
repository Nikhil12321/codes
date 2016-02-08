/*
    I mean, that's really it, keep inserting everything into a heap
    Oh and heap has to be decreasing order. Check the heap's declaration!
*/

ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)
            return NULL;
        int i;
        priority_queue<int, vector<int>, std::greater<int> > p;
        for(i=0; i<lists.size(); i++){
            while(lists[i]!=NULL){
                p.push(lists[i]->val);
                lists[i] = lists[i]->next;
            }
        }
        if(p.size()==0)
            return NULL;
        ListNode * head = new ListNode(p.top());
        p.pop();
        ListNode * prev = head;
        while(p.size()>0){
            ListNode * newN = new ListNode(p.top());
            p.pop();
            prev->next =  newN;
            prev = newN;
        }
        return head;
    }
//https://leetcode.com/problems/merge-k-sorted-lists/