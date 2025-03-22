##########################################################################
##########################################################################
'''
819. Most Common Word
Solved
Easy
Topics
Companies

Given a string paragraph and a string array of the banned words banned, return the most frequent word that is not banned. It is guaranteed there is at least one word that is not banned, and that the answer is unique.

The words in paragraph are case-insensitive and the answer should be returned in lowercase.

 

Example 1:

Input: paragraph = "Bob hit a ball, the hit BALL flew far after it was hit.", banned = ["hit"]
Output: "ball"
Explanation: 
"hit" occurs 3 times, but it is a banned word.
"ball" occurs twice (and no other word does), so it is the most frequent non-banned word in the paragraph. 
Note that words in the paragraph are not case sensitive,
that punctuation is ignored (even if adjacent to words, such as "ball,"), 
and that "hit" isn't the answer even though it occurs more because it is banned.

Example 2:

Input: paragraph = "a.", banned = []
Output: "a"

 

Constraints:

    1 <= paragraph.length <= 1000
    paragraph consists of English letters, space ' ', or one of the symbols: "!?',;.".
    0 <= banned.length <= 100
    1 <= banned[i].length <= 10
    banned[i] consists of only lowercase English letters.
'''
##########################################################################
'''
link to the problem=====>(https://leetcode.com/problems/most-common-word/)
'''
##########################################################################
class Solution:
    def mostCommonWord(self, paragraph: str, banned: List[str]) -> str:
        l=[]
        a=paragraph.replace(", "," ")
        a=a.replace(","," ")
        a=a.replace(".","")
        a=a.replace("!","")
        a=a.replace("?","")
        a=a.replace("'","")
        a=a.replace(";","")
        p=a.split(" ")
        for i in range(len(p)):
            p[i]=p[i].lower()
        dictn={}
        for i in p:
            if i not in dictn:
                dictn[i]=1
            else:
                dictn[i]+=1
        def custom_sort(items):
            return items[1]
        u=sorted(dictn.items(),key=custom_sort,reverse=True)
        for i in u:
            if i[0] not in banned:
                return i[0]