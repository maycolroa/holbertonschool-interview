#!/usr/bin/python3
"""program to calculate n H"""


def minOperations(n):
    """method is defined for calculating"""

    num_operations = 0
    oper_validate = 2
    int_1 = n
    int_2 = n

    if type(n) != int or n < 1:
        return 0

    while (True):
        int_1 = int_2 / oper_validate

        if int_2 == 1:
            break

        if not int_1.is_integer():
            oper_validate += 1
        elif int_1.is_integer():
            num_operations += oper_validate
            oper_validate = 2
            int_2 = int_1
        elif int_2 == oper_validate:
            num_operations += oper_validate
            break

    return num_operations
