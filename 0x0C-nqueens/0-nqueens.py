#!/usr/bin/python3
"""NQueens problem"""


import sys


def print_board(board):
    """Print the nqueens board"""
    chess = []
    for i in board:
        for j in i:
            if j == 1:
                chess.append([board.index(i), i.index(j)])
    print(chess)


def is_safe(board, row, column, value):
    """Check if current board is safe"""
    for i in range(column):
        if board[row][i] + board[row][i + 1] != 0:
            return False
    for i, j in zip(range(row, -1, -1), range(column, -1, -1)):
        if board[i][j] == 1:
            return False
    for i, j in zip(range(row, value, 1), range(column, -1, -1)):
        if board[i][j] == 1:
            return False
    return True


def nqueens(board, column, value):
    """nqueens recursive function"""
    if column >= value:
        print_board(board)
    for i in range(value):
        if is_safe(board, i, column, value):
            board[i][column] = 1
            if nqueens(board, column + 1, value):
                return True
            board[i][column] = 0
    return False


if __name__ == "__main__":
    """Main function for nqueens"""
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        exit(1)
    if sys.argv[1].isnumeric():
        n = int(sys.argv[1])
    else:
        print("N must be a number")
        exit(1)
    if n < 4:
        print("N must be at least 4")
        exit(1)
    board = [[0 for i in range(n)] for j in range(n)]
    nqueens(board, 0, n)
