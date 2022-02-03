#!/usr/bin/python3
"""make change"""


def makeChange(coins, total):
    """make change function"""
    coins.sort()
    reste = total
    times = 0
    while coins != []:
        times += reste // coins[-1]
        reste = reste % coins[-1]
        if reste == 0:
            return times
        coins.pop()
    return -1
