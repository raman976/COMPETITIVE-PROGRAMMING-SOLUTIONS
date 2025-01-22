################################
'''
################################
A. Word Capitalization
time limit per test
2 seconds
memory limit per test
256 megabytes

Capitalization is writing a word with its first letter as a capital letter. Your task is to capitalize the given word.

Note, that during capitalization all the letters except the first one remains unchanged.
Input

A single line contains a non-empty word. This word consists of lowercase and uppercase English letters. The length of the word will not exceed 103.
Output

Output the given word after capitalization.
Examples
Input
Copy

ApPLe

Output
Copy

ApPLe

Input
Copy

konjac

Output
Copy

Konjac

################################
'''
################################


s=input()
s=list(s)
s[0]=s[0].upper()
k="".join(s)
print(k)

