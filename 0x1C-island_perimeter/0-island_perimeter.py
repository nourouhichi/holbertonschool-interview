#!/usr/bin/python3
"""island perimeter calculator"""


def island_perimeter(grid):
    """Calculate perimeter of the island (grid)
    """
    sm, limit = (0, 0)
    grid_len, col = (len(grid), len(grid[0]))
    for i in range(grid_len):
        sm += sum(grid[i])
        for j in range(col):
            if grid[i][j] :
                if j > 0 and grid[i][j - 1] == 1:
                    limit += 1
                if i > 0 and grid[i - 1][j] == 1:
                    limit += 1
    return sm * 4 - limit * 2
