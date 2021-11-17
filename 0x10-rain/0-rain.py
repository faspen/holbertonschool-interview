#!/usr/bin/python3
"""Rain interview question"""


def rain(walls):
    """Calculate the amount of water between each wall"""
    if not isinstance(walls, list) or walls is []:
        return 0
    for i in walls:
        if i < 0:
            return 0

    water = 0

    for num, height in enumerate(walls):
        left_val = max(walls[:num + 1])
        right_val = max(walls[num:])
        diff = min(left_val, right_val)
        water += max(diff - height, 0)
    return water
