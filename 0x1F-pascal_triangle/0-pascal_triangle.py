#!/usr/bin/python3
"""Pascal's triangle"""


def pascal_triangle(n):
    """Create a pascal triangle"""
    triangle = []
    if n <= 0:
        return triangle
    
    for i in range(1, n + 1):
        dim = 1
        row = []
        for j in range(1, i + 1):
            row.append(dim)
            dim = dim * (i - j) // j
        triangle.append(row)
    return triangle