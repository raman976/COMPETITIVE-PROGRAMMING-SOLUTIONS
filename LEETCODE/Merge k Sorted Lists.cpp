// 23. Merge k Sorted Lists
// Solved
// Hard
// Topics
// premium lock iconCompanies

// You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

// Merge all the linked-lists into one sorted linked-list and return it.

 

// Example 1:

// Input: lists = [[1,4,5],[1,3,4],[2,6]]
// Output: [1,1,2,3,4,4,5,6]
// Explanation: The linked-lists are:
// [
//   1->4->5,
//   1->3->4,
//   2->6
// ]
// merging them into one sorted linked list:
// 1->1->2->3->4->4->5->6

// Example 2:

// Input: lists = []
// Output: []

// Example 3:

// Input: lists = [[]]
// Output: []

 

// Constraints:

//     k == lists.length
//     0 <= k <= 104
//     0 <= lists[i].length <= 500
//     -104 <= lists[i][j] <= 104
//     lists[i] is sorted in ascending order.
//     The sum of lists[i].length will not exceed 104.




#include <queue>
class Solution {
public:
    struct compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;  // min-heap
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        
        // Push first node of each list into heap
        for (auto node : lists) {
            if (node) pq.push(node);
        }

        ListNode dummy(0);  // dummy head
        ListNode* tail = &dummy;

        while (!pq.empty()) {
            ListNode* top = pq.top();
            pq.pop();
            tail->next = top;
            tail = tail->next;

            if (top->next) {
                pq.push(top->next);
            }
        }

        return dummy.next;
    }
};
