#!/usr/bin/python3
"""0. UTF-8 Validation"""


def validUTF8(data):
    """validUTF8"""
    j = 0
    for num in data:
        bin_rep = format(num, '#010b')[-8:]
        if j == 0:
            for bit in bin_rep:
                if bit == '0':
                    break
                j += 1
            if j == 0:
                continue
            if j == 1 or j > 4:
                return False
        else:
            if not (bin_rep[0] == '1' and bin_rep[1] == '0'):
                return False
        j -= 1
    return j == 0
