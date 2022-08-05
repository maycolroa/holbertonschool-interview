#!/usr/bin/python3
"""0x00. Lockboxes"""

class Solution:
    def solve(self, rooms):
    n = len(rooms)

    ready = [0]
    seen = set()

    while ready:
        u = ready.pop()
        seen.add(u)
        