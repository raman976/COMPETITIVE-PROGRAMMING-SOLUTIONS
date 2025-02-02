####################################################
####################################################
'''
884. Uncommon Words from Two Sentences
Solved
Easy
Topics
Companies

A sentence is a string of single-space separated words where each word consists only of lowercase letters.

A word is uncommon if it appears exactly once in one of the sentences, and does not appear in the other sentence.

Given two sentences s1 and s2, return a list of all the uncommon words. You may return the answer in any order.

 

Example 1:

Input: s1 = "this apple is sweet", s2 = "this apple is sour"

Output: ["sweet","sour"]

Explanation:

The word "sweet" appears only in s1, while the word "sour" appears only in s2.

Example 2:

Input: s1 = "apple apple", s2 = "banana"

Output: ["banana"]

 

Constraints:

    1 <= s1.length, s2.length <= 200
    s1 and s2 consist of lowercase English letters and spaces.
    s1 and s2 do not have leading or trailing spaces.
    All the words in s1 and s2 are separated by a single space.


'''
####################################################
####################################################

class Solution:
    def uncommonFromSentences(self, s1: str, s2: str) -> List[str]:
        ans=[]
        dicts1={}
        dicts2={}
        p=list(s1.split())
        print(p)
        for i in p:
            print(i)
            if i in dicts1:
                dicts1[i]+=1
            else:
                dicts1[i]=1
        q=list(s2.split())
        for i in q:
            if i in dicts2:
                dicts2[i]+=1
            else:
                dicts2[i]=1
        for i in dicts1:
            if dicts1[i]==1 and i not in dicts2:
                ans.append(i)
        for i in dicts2:
            if dicts2[i]==1 and i not in dicts1:
                ans.append(i)
        return ans
        