#!/usr/bin/python3
"""Validate utf8"""


def validUTF8(data):
    """Utf8 validator"""
    val = False
    trav = 0

    for i in data:
        byte = format(i, '#010b')[-8:]
        if trav == 0:
            if byte[0] == '1':
                trav = len(byte.split('0')[0])
            if trav > 4 or trav == 1:
                return False
            if trav == 0:
                continue
        else:
            if not byte.startswith('10'):
                return False
        trav = trav - 1
    if trav == 0:
        return True
    return val
