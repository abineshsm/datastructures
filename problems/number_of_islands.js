let dfs = function (grid, i, j) {
    if (i < 0 || i >= grid.length || j < 0 || (grid[i] && j >= grid[i].length) || grid[i][j] == 0)
        return 0;
    grid[i][j] = 0;
    dfs(grid, i - 1, j);
    dfs(grid, i + 1, j);
    dfs(grid, i, j + 1);
    dfs(grid, i, j - 1);
    return 1;
}

var numIslands = function (grid) {
    if (grid == null || grid.length == 0)
        return 0;

    let numOfIslands = 0;
    for (i = 0; i < grid.length; i++)
        for (j = 0; j < grid[i].length; j++) {
            if (grid[i][j] == 1)
                numOfIslands += dfs(grid, i, j);
        }

    return numOfIslands;
};

