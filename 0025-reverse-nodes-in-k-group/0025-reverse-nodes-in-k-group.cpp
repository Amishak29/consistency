class Solution
{
    public:
        int length(ListNode *head)
        {
            int ans = 0;
            while (head)
            {
                ans++;
                head = head->next;
            }
            return ans;
        }
    ListNode* reverseg(int len, ListNode *head, int k)
    {
        if (len < k)
        {
            return head;
        }

        ListNode *p = head, *q = nullptr, *r = nullptr;
        int count = 0;

        while (count < k and p)
        {
            r = q;
            q = p;
            p = p->next;
            q->next=r;
            count++;
        }
        if (p)
        {
            head->next = reverseg(len - k, p, k);
        }
        return q;
    }
    ListNode* reverseKGroup(ListNode *head, int k)
    {
        int len = length(head);
        return reverseg(len, head, k);
    }
};