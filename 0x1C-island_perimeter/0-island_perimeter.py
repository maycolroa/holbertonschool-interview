#!/usr/bin/python3
"""function"""


def island_perimeter(grid):
    """Returns the perimeter of the island"""

    def edges(matrix):
        """detect number"""
        count = 0
        for row in matrix:
            row = [0] + row + [0]
            for i in range(1, len(row)):
                count += row[i] != row[i-1]
        return count

    tgrid = [[] for _ in range(len(grid[0]))]
    for row in grid:
        for i, item in enumerate(row):
            tgrid[i].append(item)

    return edges(grid) + edges(tgrid)
