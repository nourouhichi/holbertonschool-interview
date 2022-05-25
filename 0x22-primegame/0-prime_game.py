#!/usr/bin/python3
"""prime game module"""


def isWinner(x, nums):
    """prime game function"""
    if not nums:
        return None
    n = max(nums)
    fl = []
    for _ in range(max(n + 1, 2)):
        fl.append(True)
    for i in range(2, int(pow(n, 0.5)) + 1):
        if not fl[i]:
            continue
        for j in range(i * i, n + 1, i):
            fl[j] = False
    fl[0] = fl[1] = False
    count = 0
    for i in range(len(fl)):
        if fl[i]:
            count += 1
        fl[i] = count
    p1 = 0
    for i in nums:
        p1 += fl[i] % 2 == 1
    if p1 * 2 == len(nums):
        return None
    if p1 * 2 > len(nums):
        return "Maria"
    return "Ben"
