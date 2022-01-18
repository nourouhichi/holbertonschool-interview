#!/usr/bin/python3
"""
Rotate 2D Matrix
"""


def rotate_2d_matrix(matrix):
    """2d matrix rotation"""
    k = len(matrix) - 1
    tmp_mat = []
    for i in matrix:
        tmp_mat.append(list(tuple(i)))
    for i in range(len(matrix)):
        for j in range(len(matrix)):
            tmp_mat[j][k] = matrix[i][j]
        k -= 1
    for i in range(len(matrix)):
        for j in range(len(matrix)):
            matrix[i][j] = tmp_mat[i][j]
