// leetcode 3217. Delete Nodes From Linked List Present in Array
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
#include <iostream>
#include <vector>
#include <unordered_set>
#include <list>
using namespace std;
class Solution
{
public:
    ListNode *modifiedList(vector<int> &nums, ListNode *head)
    {
        unordered_set<int> toDelete(nums.begin(), nums.end());
        ListNode dummy(0, head);
        ListNode *prev = &dummy;
        while (prev->next)
        {
            if (toDelete.count(prev->next->val))
            {
                prev->next = prev->next->next;
            }
            else
            {
                prev = prev->next;
            }
        }
        return dummy.next;
    }
};
int main()
{
    return 0;
}