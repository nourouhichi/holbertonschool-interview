#!/usr/bin/python3
"""module"""


def canUnlockAll(boxes):
    """function"""
    if boxes[0] == []:
        return False
    keys_list = [0]
    for index in range(len(boxes)):
        for j in boxes[index]:
            if j not in keys_list and j < len(boxes) and j is not index:
                keys_list.append(j)
    if len(keys_list) == len(boxes):
        return True
    return False
