def can_divide_fairly(n,candies):
    total=sum(candies)
    if total%2!=0:
        return "NO"
    half_weight=total//2
    ones=candies.count(1)
    count_twos=candies.count(2)
    if half_weight%2==0 and count_twos*2>=half_weight:
        return "YES"
    if ones>0 and ones+count_twos*2>=half_weight:
        return "YES"
    return "NO"

t=int(input())
for i in range(t):
    n=int(input())
    candies=list(map(int,input().split()))
    print(can_divide_fairly(n,candies))
