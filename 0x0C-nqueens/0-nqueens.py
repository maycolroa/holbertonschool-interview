#!/usr/bin/python3
"""import modules"""
import sys


global N


def printSolution(board):
    """printsolution"""
    q_pos = []
    q_list = []
    for i in range(N):
        for j in range(N):
            if board[i][j] == 1:
                q_pos.append(i)
                q_pos.append(j)
                q_list.append(list(q_pos))
                q_pos.clear()
    print(q_list)


def isSafe(board, row, col):
    """isSafe"""
    for i in range(col):
        if board[row][i] == 1:
            return False
    for i, j in zip(range(row, -1, -1), range(col, -1, -1)):
        if board[i][j] == 1:
            return False
    for i, j in zip(range(row, N, 1), range(col, -1, -1)):
        if board[i][j] == 1:
            return False
    return True


def solveNQUtil(board, col):
    """solveNQUtl"""
    if col >= N:
        return True
    for i in range(N):
        if isSafe(board, i, col):
            board[i][col] = 1
            if solveNQUtil(board, col + 1) is True:
                printSolution(board)
            board[i][col] = 0
    return False


def create_board(n):
    """create_board"""
    b_list = []
    b_pos = []
    for _ in range(n):
        for _ in range(n):
            b_pos.append(0)
        b_list.append(list(b_pos))
        b_pos.clear()
    return b_list

if len(sys.argv) != 2:
    print("Usage: nqueens N")
    sys.exit(1)

try:
    N = int(sys.argv[1])
except ValueError:
    print("N must be a number")
    sys.exit(1)

if N < 4:
    print("N must be at least 4")
    sys.exit(1)

solveNQUtil(create_board(N), 0)
