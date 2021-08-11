#!/usr/bin/python3
"""Minimum ops"""


def minOperations(n):
    """Return minimum number of operations needed"""
    if n < 2:
        return 0

    ops = 0
    h = 1
    printed = 0

    while h < n:
        if n % h == 0:
            printed = h
            ops += 1
        h += printed
        ops += 1

    if h == n:
        return ops

    return 0
