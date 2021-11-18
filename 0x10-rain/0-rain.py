#!/usr/bin/python3
"""
rain walls
"""


def rain(walls):
    """rain cubes"""
    n = 0
    for i in range(len(walls) - 1):
        if walls[i] != 0:
            for j in range(i + 1, len(walls)):
                if walls[j] != 0:
                    n += (j - i - 1) * min(walls[i], walls[j])
                    break
    return n
