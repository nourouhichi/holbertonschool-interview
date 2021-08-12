#!/usr/bin/python3
"""
minoperation
"""


def minOperations(n):
    """minoperration"""
    div = 2
    x = 0
    while n > 1:
        while n % div == 0:
            x += div
            n = n / div
        div += 1
    return x
