###############################################################
###############################################################
'''
1436. Destination City
Solved
Easy
Topics
Companies
Hint

You are given the array paths, where paths[i] = [cityAi, cityBi] means there exists a direct path going from cityAi to cityBi. Return the destination city, that is, the city without any path outgoing to another city.

It is guaranteed that the graph of paths forms a line without any loop, therefore, there will be exactly one destination city.

 

Example 1:

Input: paths = [["London","New York"],["New York","Lima"],["Lima","Sao Paulo"]]
Output: "Sao Paulo" 
Explanation: Starting at "London" city you will reach "Sao Paulo" city which is the destination city. Your trip consist of: "London" -> "New York" -> "Lima" -> "Sao Paulo".

Example 2:

Input: paths = [["B","C"],["D","B"],["C","A"]]
Output: "A"
Explanation: All possible trips are: 
"D" -> "B" -> "C" -> "A". 
"B" -> "C" -> "A". 
"C" -> "A". 
"A". 
Clearly the destination city is "A".

Example 3:

Input: paths = [["A","Z"]]
Output: "Z"

 

Constraints:

    1 <= paths.length <= 100
    paths[i].length == 2
    1 <= cityAi.length, cityBi.length <= 10
    cityAi != cityBi
    All strings consist of lowercase and uppercase English letters and the space character.


'''
###############################################################
###############################################################

class Solution:
    def destCity(self, paths: List[List[str]]) -> str:
        dictn={}
        arr=[]
        for i in (paths):
            for j in i:
                if j in dictn:
                    dictn[j]+=1
                else:
                    dictn[j]=1
        for i in dictn:
            if dictn[i]==1:
                arr.append(i)
        print(arr)
        a=arr[0]
        b=arr[1]
        for i in paths:
            if( a in i):
                if i.index(a)!=0:
                    return a
            if (b in i):
                if i.index(b)!=0:
                    return b