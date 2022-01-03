#!/usr/bin/env python3
"""Rotate 2D Matrix"""


def rotate_2d_matrix(matrix):
    """Rotates a 2d matrix clockwise 90 degrees"""
    mat = len(matrix)
    copy = []
    tmp_row = 0

    for col in range(mat):
        for row in range((mat - 1), -1, -1):
            if col is 0:
                copy.append([])
            copy[tmp_row].append(matrix[row][col])
        tmp_row += 1

    for row in range(mat):
        for col in range(mat):
            matrix[row][col] = copy[row][col]
