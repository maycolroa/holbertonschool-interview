#!/usr/bin/python3
"""0. Rotate 2D Matrix"""


def rotate_2d_matrix(matrix):
    """Rotate it 90 degrees clockwise"""
    k = len(matrix)

    for j in range(int(k / 2)):
        y = (k - j - 1)
        for col in range(j, y):
            x = (k - 1 - col)
            tmp = matrix[j][col]
            matrix[j][col] = matrix[x][j]
            matrix[x][j] = matrix[y][x]
            matrix[y][x] = matrix[col][y]
            matrix[col][y] = tmp
