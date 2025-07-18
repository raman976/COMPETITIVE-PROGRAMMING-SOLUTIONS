// 24. Swap Nodes in Pairs
// Solved
// Medium
// Topics
// premium lock iconCompanies

// Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)

 

// Example 1:

// Input: head = [1,2,3,4]

// Output: [2,1,4,3]

// Explanation:

// Example 2:

// Input: head = []

// Output: []

// Example 3:

// Input: head = [1]

// Output: [1]

// Example 4:

// Input: head = [1,2,3]

// Output: [2,1,3]

 

// Constraints:

//     The number of nodes in the list is in the range [0, 100].
//     0 <= Node.val <= 100




// class Solution {
// public:
//     ListNode* swapPairs(ListNode* head) {
//         // Create a dummy node to simplify edge cases
//         ListNode* dummy = new ListNode(0);
//         dummy->next = head;

//         ListNode* prev = dummy;

//         while (prev->next && prev->next->next) {
//             ListNode* first = prev->next;
//             ListNode* second = first->next;

//             // Perform the swap
//             prev->next = second;
//             first->next = second->next;
//             second->next = first;

//             // Move prev to the end of the swapped pair
//             prev = first;
//         }

//         return dummy->next;
//     }
// };



class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // Create a dummy node to simplify edge cases
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prev = dummy;

        while (prev->next && prev->next->next) {
            ListNode* first = prev->next;
            ListNode* second = first->next;

            // Perform the swap
            prev->next = second;
            first->next = second->next;
            second->next = first;

            // Move prev to the end of the swapped pair
            prev = first;
        }

        return dummy->next;
    }
};
