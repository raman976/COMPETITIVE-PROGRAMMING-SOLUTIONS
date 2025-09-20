// A. Furniture Store
// time limit per test
// 2 seconds
// memory limit per test
// 256 megabytes

// On the website of a company that manufactures and sells furniture, customers can order n
// different models of sofas, numbered from 1 to n. Each sofa has a unique price; the price of the i-th sofa is denoted by ai

// .

// Every customer who visits the website has their own budget m
// , which they are willing to spend on a sofa. When they look through the list of sofa models, they search for the first sofa that costs no more than m

// and orders it. If there are no such sofas, then the client leaves the website without ordering anything.

// The company aims to identify which sofas will never be ordered. Your task is to determine the models such that there is no such budget m

// that a customer will order this particular model.
// Input

// The first line contains a single integer t
// (1≤t≤1000

// ) — the number of test cases.

// The first line of each test case contains a single integer n
// (1≤n≤100

// ).

// The second line contains n
// distinct integers a1,a2,…,an (1≤ai≤100

// ).
// Output

// For each test case, provide the answer in this format: on the first line, print a single integer k
//  — the number of models that cannot be ordered. On the second line, print exactly k

// integers in ascending order, representing the indices of the models that cannot be ordered.
// Example
// Input
// Copy

// 4
// 3
// 1 2 3
// 4
// 4 6 2 1
// 1
// 100
// 6
// 7 5 8 4 6 2

// Output
// Copy

// 2
// 2 3
// 1
// 2
// 0

// 2
// 3 5




fun main() = repeat(readln().toInt()) {
  val n = readln().toInt()
  val a = readln().split(" ").map { it.toInt() }
  val p = a.runningReduce { x, y -> minOf(x, y) }
  val ans = (1..n).filter { i -> a[i - 1] != p[i - 1] }
  println(ans.size)
  println(ans.joinToString(" "))    
}