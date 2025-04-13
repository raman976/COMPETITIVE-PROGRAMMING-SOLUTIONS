#####################################################################################################
#####################################################################################################
'''
A. Reconnaissance 2
time limit per test
2 seconds
memory limit per test
256 megabytes

n soldiers stand in a circle. For each soldier his height ai is known. A reconnaissance unit can be made of such two neighbouring soldiers, whose heights difference is minimal, i.e. |ai - aj| is minimal. So each of them will be less noticeable with the other. Output any pair of soldiers that can form a reconnaissance unit.
Input

The first line contains integer n (2 ≤ n ≤ 100) — amount of soldiers. Then follow the heights of the soldiers in their order in the circle — n space-separated integers a1, a2, ..., an (1 ≤ ai ≤ 1000). The soldier heights are given in clockwise or counterclockwise direction.
Output

Output two integers — indexes of neighbouring soldiers, who should form a reconnaissance unit. If there are many optimum solutions, output any of them. Remember, that the soldiers stand in a circle.
Examples
Input
Copy

5
10 12 13 15 10

Output
Copy

5 1

Input
Copy

4
10 20 30 40

Output
Copy

1 2
'''
#####################################################################################################
#####################################################################################################
n=int(input())
l=list(map(int,input().split()))
m=float('inf')
ind=[-1,-1]
for i in range(n-1):
    a=abs(l[i+1]-l[i])
    if a<m:
        m=a 
        ind[0]=i 
        ind[1]=i+1 
if abs(l[0]-l[-1])<m:
    ind[0]=n-1 
    ind[1]=0 
print(ind[0]+1,ind[1]+1)