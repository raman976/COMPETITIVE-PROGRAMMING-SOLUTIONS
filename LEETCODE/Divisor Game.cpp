// 1025. Divisor Game
// Easy
// Topics
// premium lock iconCompanies
// Hint

// Alice and Bob take turns playing a game, with Alice starting first.

// Initially, there is a number n on the chalkboard. On each player's turn, that player makes a move consisting of:

//     Choosing any integer x with 0 < x < n and n % x == 0.
//     Replacing the number n on the chalkboard with n - x.

// Also, if a player cannot make a move, they lose the game.

// Return true if and only if Alice wins the game, assuming both players play optimally.

 

// Example 1:

// Input: n = 2
// Output: true
// Explanation: Alice chooses 1, and Bob has no more moves.

// Example 2:

// Input: n = 3
// Output: false
// Explanation: Alice chooses 1, Bob chooses 1, and Alice has no more moves.

 

// Constraints:

//     1 <= n <= 1000

 
// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 3,51,977/495.2K
// Acceptance Rate
// 71.1%



class Solution {
public:
    bool divisorGame(int n) {
        return n % 2 == 0;
    }
};
