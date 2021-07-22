#!/usr/bin/python3
"""Lockboxes"""


def canUnlockAll(boxes):
    """Unlock the boxes"""
    locked = boxes.copy()
    list_of_keys = []
    iterate = 0

    for item in boxes:
        # Handle the first box (always unlocked)
        if iterate == 0:
            # Gather keys
            for k in item:
                if k not in list_of_keys:
                    list_of_keys.append(k)
            locked.remove(item)
        # Every other box
        else:
            if iterate in list_of_keys:
                # Gather keys
                for k in item:
                    if k not in list_of_keys:
                        list_of_keys.append(k)
                for remaining in locked:
                    if iterate in list_of_keys:
                        # Gather keys
                        for k in item:
                            if k not in list_of_keys:
                                list_of_keys.append(k)
                        locked.remove(remaining)
        iterate += 1

    if locked == []:
        # True if nothing
        return True
    if len(boxes) == 1:
        # True if only one box (first box is always unlocked)
        return True
    return False
