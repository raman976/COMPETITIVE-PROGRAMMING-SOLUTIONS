##########################################
"""
##########################################
500. Keyboard Row
Solved
Easy
Topics
Companies

Given an array of strings words, return the words that can be typed using letters of the alphabet on only one row of American keyboard like the image below.

Note that the strings are case-insensitive, both lowercased and uppercased of the same letter are treated as if they are at the same row.

In the American keyboard:

    the first row consists of the characters "qwertyuiop",
    the second row consists of the characters "asdfghjkl", and
    the third row consists of the characters "zxcvbnm".

 

Example 1:

Input: words = ["Hello","Alaska","Dad","Peace"]

Output: ["Alaska","Dad"]

Explanation:

Both "a" and "A" are in the 2nd row of the American keyboard due to case insensitivity.

Example 2:

Input: words = ["omk"]

Output: []

Example 3:

Input: words = ["adsdf","sfd"]

Output: ["adsdf","sfd"]

 

Constraints:

    1 <= words.length <= 20
    1 <= words[i].length <= 100
    words[i] consists of English letters (both lowercase and uppercase). 


##########################################
"""
##########################################



class Solution:
    def findWords(self, words: List[str]) -> List[str]:
        top=['q','w','e','r','t','y','u','i','o','p']
        middle=['a','s','d','f','g','h','j','k','l']
        bottom=['z','x','c','v','b','n','m']
        x=[]
        p=[]
        for i in words:
            p.append(i.lower())
        for i in p:
            a=len(i)
            countt=0
            countm=0
            countb=0
            for j in i:
                if j in top:
                    countt+=1
                elif j in middle:
                    countm+=1
                else:
                    countb+=1
            if countt==a or countm==a or countb==a:
                x.append(words[p.index(i)])
        return x
