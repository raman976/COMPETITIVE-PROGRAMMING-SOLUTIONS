// A. Game With Sticks
// time limit per test
// 1 second
// memory limit per test
// 256 megabytes

// After winning gold and silver in IOI 2014, Akshat and Malvika want to have some fun. Now they are playing a game on a grid made of n horizontal and m vertical sticks.

// An intersection point is any point on the grid which is formed by the intersection of one horizontal stick and one vertical stick.

// In the grid shown below, n = 3 and m = 3. There are n + m = 6 sticks in total (horizontal sticks are shown in red and vertical sticks are shown in green). There are n·m = 9 intersection points, numbered from 1 to 9.

// The rules of the game are very simple. The players move in turns. Akshat won gold, so he makes the first move. During his/her move, a player must choose any remaining intersection point and remove from the grid all sticks which pass through this point. A player will lose the game if he/she cannot make a move (i.e. there are no intersection points remaining on the grid at his/her move).

// Assume that both players play optimally. Who will win the game?
// Input

// The first line of input contains two space-separated integers, n and m (1 ≤ n, m ≤ 100).
// Output

// Print a single line containing "Akshat" or "Malvika" (without the quotes), depending on the winner of the game.
// Examples
// Input
// Copy

// 2 2

// Output
// Copy

// Malvika

// Input
// Copy

// 2 3

// Output
// Copy

// Malvika

// Input
// Copy

// 3 3

// Output
// Copy

// Akshat

// Note

// Explanation of the first sample:

// The grid has four intersection points, numbered from 1 to 4.

// If Akshat chooses intersection point 1, then he will remove two sticks (1 - 2 and 1 - 3). The resulting grid will look like this.

// Now there is only one remaining intersection point (i.e. 4). Malvika must choose it and remove both remaining sticks. After her move the grid will be empty.

// In the empty grid, Akshat cannot make any move, hence he will lose.

// Since all 4 intersection points of the grid are equivalent, Akshat will lose no matter which one he picks.



#include <iostream>
using namespace std;int main() {
    int n, m;
    cin >> n >> m;    int moves = min(n, m);    if (moves % 2 == 1)
        cout << "Akshat" << endl;
    else
        cout << "Malvika" << endl;    return 0;
}