#!/usr/bin/python3
"""initialization of algorithm"""


def makeChange(coins, total):
    """function"""

    if total <= 0:
        return 0

    coins.sort(reverse=True)
    stack = total
    i = 0
    j = 0
    while (i < len(coins)):
        if stack == 0:
            return j
        if coins[i] > stack:
            i += 1
        else:
            stack -= coins[i]
            j += 1
    return -1
