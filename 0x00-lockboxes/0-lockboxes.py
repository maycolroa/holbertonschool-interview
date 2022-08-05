#!/usr/bin/python3
"""0x00. Lockboxes"""

def canUnlockAll(boxes):
    unlocked = [0]
    for i, box in enumerate(boxes):
        if not box:
            continue
        