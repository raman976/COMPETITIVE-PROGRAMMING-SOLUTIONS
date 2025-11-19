// D. Batteries
// time limit per test
// 2 seconds
// memory limit per test
// 256 megabytes

// This is an interactive problem. Refer to the Interaction section below for better understanding.

// There are n
// (2≤n≤40) batteries numbered 1,2,…,n. Some of them work while the others don't. Let a be the number of batteries that work. It is guaranteed that a≥2

// .

// You are given n
// but not a

// .

// There is a flashlight which can hold two batteries and it only turns on when both batteries work. The batteries have been shuffled and you don't know which ones work and which ones don't. You can choose two batteries and try them in the flashlight.

// You want to find a pair of batteries that work. However, you are worried about breaking the flashlight, so you want to limit the amount of trials you attempt.

// Therefore, you should find a pair of working batteries using at most ⌊n2a⌋

// trials.

// The interactor is adaptive. This means that whether battery i
// (1≤i≤n) works is not fixed and may change during the interaction. However, it is guaranteed that there exists a configuration of a

// working batteries that is consistent with the information that you have received so far.
// Input

// Each test contains multiple test cases. The first line contains the number of test cases t
// (1≤t≤50

// ). The description of the test cases follows.

// The first line of each test case contains a single integer n
// (2≤n≤40

// ) — the number of batteries.

// It is guaranteed that the sum of n
// over all test cases does not exceed 200

// .
// Interaction

// The interaction for each test case begins with reading the integer n

// .

// To make a query, print a single line with two integers in the following format:

//     uv

// (1≤u,v≤n and u≠v

//     ) — the indices of the batteries you want to test. 

// After that, read a single integer x
//  — indicating whether the flashlight turned on after inserting those 2 batteries. If x=1, the flashlight turned on. Otherwise, if x=0

// , the flashlight did not turn on.

// After finding a pair of batteries that turns the flashlight on, the interaction of the test case is considered successful, and it will terminate. After that, the interaction continues with the next test case.

// After printing each query do not forget to output the end of line and flush∗

// the output. Otherwise, you will get Idleness limit exceeded verdict.

// If, at any interaction step, you read −1

// instead of valid data, your solution must exit immediately. This means that your solution will receive Wrong answer because of an invalid query or any other mistake. Failing to exit can result in an arbitrary verdict because your solution will continue to read from a closed stream.

// Hacks

// Hacks are disabled for this problem.

// ∗

// To flush, use:

//     fflush(stdout) or cout.flush() in C++;
//     sys.stdout.flush() in Python;
//     see the documentation for other languages. 

// Example
// Input
// Copy

// 2
// 3

// 0

// 1
// 10

// 0

// 0

// 1

// Output
// Copy



// 1 2

// 2 3


// 1 2

// 1 3

// 1 4

// Note

// In the first test, there are 3
// batteries. Only batteries 2 and 3 work. Therefore, a=2 and we have to find a pair of batteries that work in ⌊n2a⌋=⌊322⌋=4

// queries.

// The interaction proceeds as follows:
// Participant	Jury	Explanation
// —	3
// 	There are 3
// batteries in this test case
// 1
//   2
// 	0
// 	The solution asks whether batteries 1
// and 2
// turn the flashlight on. The jury responds that they don't.
// 2
//   3
// 	1
// 	The solution asks whether batteries 2
// and 3
// turn the flashlight on. The jury responds that they do. A pair of batteries that work is found, so the interaction of the first test case terminates successfully.

// In the second test case, there are 10
// batteries. Only batteries 1, 4, 6 and 9 work. Therefore, a=4 and we have to find a pair of batteries that work in ⌊n2a⌋=⌊1024⌋=25

// queries.

// The interaction proceeds as follows:
// Participant	Jury	Explanation
// —	10
// 	There are 10
// batteries in this test case.
// 1
//   2
// 	0
// 	The solution asks whether batteries 1
// and 2
// turn the flashlight on. The jury responds that they don't.
// 1
//   3
// 	0
// 	The solution asks whether batteries 1
// and 3
// turn the flashlight on. The jury responds that they don't.
// 1
//   4
// 	1
// 	The solution asks whether batteries 1
// and 4
// turn the flashlight on. The jury responds that they do. A pair of batteries that work is found, so the interaction of the first test case terminates successfully.

// Note that the line breaks in the example input and output are for the sake of clarity, and do not occur in the real interaction.





#include <bits/stdc++.h>

using namespace std;

void main_() {
    
    int n, x;
	cin >> n;
	
	for (int i = 1; i < n; i++)
	    for (int j = 1; j <= n; j++) {
		    
                x = (i+j)%n;
                
                if(x == 0) {
                    x = n;
                }
                
                cout << j << " " << x << endl;
                
                int res;
                cin >> res;
                
                if (res) {
                    return;
                }
        }
}

int main() {
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}