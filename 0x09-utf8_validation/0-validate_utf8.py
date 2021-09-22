#!/usr/bin/python3
"""Validate utf8"""


def validUTF8(data):
    """Utf8 validator"""
    try:
        valid = True
        for i in data:
            i = i & 0xff
            if i >= 192 and i < 244:
                valid = False
            if i >= 224 and i < 240:
                valid = False
            if i >= 240 and i < 248:
                valid = False
            if i >= 128 and i < 192:
                valid = False
            if i > 255:
                valid = False
        return valid
    except Exception as j:
        return False
