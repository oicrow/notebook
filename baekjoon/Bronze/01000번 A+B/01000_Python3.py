# Date         : 2022-07-24
# Problem      : No. 01000 A+B (https://www.acmicpc.net/problem/01000)
# Difficulty   : Bronze 5
# Step         : 1
# Language     : Python3
# Source Link  : https://www.acmicpc.net/source/46586154

A, B = input().split()
print(int(A)+int(B))

# A, B = map(int, input().split())
# print(A+B)
# => this will also work

# A = input()
# B = input()
# => this wouldn't work since 2 inputs are in the same line but 2 input() get inputs from 1st & 2nd line, respectively

# A, B = int(input().split())
# => this wouldnt' work since it is a tuple, not two strings
