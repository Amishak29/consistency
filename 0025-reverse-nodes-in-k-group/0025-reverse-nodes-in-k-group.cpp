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

        // Renaming variables for better clarity
        ListNode *curr = head, *prevpointer = nullptr, *nextptr = nullptr;
        int count = 0;

        // Reverse the first k nodes
        while (count < k and curr)
        {
            nextptr = curr->next;       // Save the next node
            curr->next = prevpointer;   // Reverse the current node's pointer
            prevpointer = curr;         // Move prevpointer to current node
            curr = nextptr;             // Move to the next node in the original list
            count++;
        }

        // Recursively reverse the remaining list and connect
        if (curr)
        {
            head->next = reverseg(len - k, curr, k);
        }
        
        return prevpointer;  // Return the new head after reversing
    }

    ListNode* reverseKGroup(ListNode *head, int k)
    {
        int len = length(head);
        return reverseg(len, head, k);
    }
};
