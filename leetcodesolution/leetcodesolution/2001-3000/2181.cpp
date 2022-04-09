
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
 class Solution {
 public:
     ListNode* mergeNodes(ListNode* head) {
         ListNode* res = new ListNode(0);
         ListNode* resPtr = res;
         int sum = 0;
         head = head->next;
         while (head != nullptr) {
             if (head->val == 0) {
                 resPtr->next = new ListNode(sum);
                 resPtr = resPtr->next;
                 head = head->next;
                 sum = 0;
             }
             else
             {
                 sum += head->val;
                 head = head->next;
             }
         }
         return res->next ? res->next : nullptr;
     }
 };