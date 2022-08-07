#!/usr/bin/python3
"""box key"""


def canUnlockAll(boxes):
    new_list = [0]
    for i, box in enumerate(boxes):
        if not box:
            continue
        for j in box:
            if j < len(boxes) and j not in new_list and j != i:
                new_list.append(j)
    if len(new_list) == len(boxes):
        return True
    return False
