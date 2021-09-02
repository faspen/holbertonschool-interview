#!/usr/bin/python3
"""Log parsing"""


import sys


def print_info(dictionary, complete_size):
    """Print the stufffffff"""
    print("File size: {}".format(complete_size))

    for k, v in sorted(dictionary.items()):
        if v != 0:
            print("{}: {}".format(k, v))


complete_size = 0
count = 0
status = 0
dictionary = {"200": 0,
              "301": 0,
              "400": 0,
              "401": 0,
              "403": 0,
              "404": 0,
              "405": 0,
              "500": 0}

try:
    for i in sys.stdin:
        line = i.split()
        line = line[::-1]

        if len(line) > 2:
            count += 1

            if count <= 10:
                complete_size += int(line[0])
                status = line[1]

                if status in dictionary.keys():
                    dictionary[status] += 1

            if count == 10:
                print_info(dictionary, complete_size)
                count = 0
finally:
    print_info(dictionary, complete_size)
