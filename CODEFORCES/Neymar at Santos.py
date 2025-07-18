# A. Neymar at Santos
# time limit per test
# 1 second
# memory limit per test
# 256 megabytes

# After a long time abroad, Neymar returns to play in his homeland. What few people know is the small sacrifice that had to be made for this to happen...

# Neymar's new contract states that X
# reais will be deducted from the salary of each public school teacher in Brazil for every goal Neymar scores while wearing the Santos jersey, and this money will be redirected to Neymar in its entirety. Note that a teacher cannot receive less than 0

# reais as salary, so there is a limit to how much money can be redirected to Neymar.

# Given that there are P
# public school teachers, each earning a salary of R, that Neymar scored G goals in the month, and that the amount deducted from each teacher per goal is X

# , determine how much money Neymar receives.
# Input

# The input consists of four lines. Each line contains a single integer:

# The first line contains an integer P(1≤P≤108)

# , representing the number of teachers in Brazil.

# The second line contains an integer R(1≤R≤3000)

# , representing how many reais each teacher earns.

# The third line contains an integer G(1≤G≤40)

# , representing how many goals Neymar scored in the month.

# The fourth line contains an integer X(1≤X≤2000)

# , representing how many reais Neymar should receive from each teacher per goal.
# Output

# Your program should print a single line containing a single integer: the amount of money that Neymar deservedly receives from the Brazilian teachers.
# Examples
# Input
# Copy

# 1861118
# 1500
# 10
# 100

# Output
# Copy

# 1861118000

# Input
# Copy

# 1861118
# 1500
# 10
# 200

# Output
# Copy

# 2791677000

# Note

# Note that in the second case, the amount that should be deducted from each teacher's salary is greater than their salary. In this case, unfortunately, it is not possible to divert more than the totality of the teachers' salaries to Neymar :(




P = int(input())
R = int(input())
G = int(input())
X = int(input())
deduction_per_teacher = min(R, G * X)
total_money = P * deduction_per_teacher
print(total_money)