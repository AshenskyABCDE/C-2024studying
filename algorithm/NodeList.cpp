/// 反转链表1
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head) {
            return head;
        }
        ListNode* dList = new ListNode(0);
        dList->next = head;
        ListNode* prev = head;
        ListNode* cur = prev ->next;
        while(cur) {
            prev->next = cur->next;
            cur->next = dList->next;
            dList->next = cur;
            cur = prev->next;
        }
        return dList->next;
    }
};

// 反转链表2 区间反转
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head ||left == right) {
            return head;
        }
        ListNode* dList = new ListNode(0);
        dList->next = head;
        ListNode* prev = dList;
        for(int i=1; i<left ;i++) {
            prev = prev->next;
        }
        ListNode* pL = prev;
        prev = prev->next;
        ListNode* cur = prev->next;
        for(int i=1 ;i<= right - left ;i++) {
            prev->next = cur ->next;
            cur->next = pL ->next;
            pL->next = cur;
            cur = prev->next;
        }
        return dList->next;
    }
};

/// 合并k个链表
class Solution {
public:
    struct S {
        int val;
        ListNode* p;
        bool operator < (const S& rhs) const {
            return rhs.val < val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<S> q;
        for (auto &tmp : lists) {
            if(tmp) {
                q.push({tmp->val , tmp});
            }
        }
        ListNode *head = nullptr;
        ListNode *tail = nullptr;
        while (q.size()) {
            auto now = q.top();
            q.pop();
            if(!head) {
                head = now.p;
                tail = now.p;
            } else {
                tail->next = now.p;
                tail = tail->next;
            }
            if(now.p -> next) {
                q.push({now.p->next->val, now.p->next});
            }
        }
        return head;
    }
};