// Ninjaland is a country in the shape of a 2-Dimensional grid 'GRID', with 'N' rows and 'M' columns. Each point in the grid has some cost associated with it.
// Find a path from top left i.e. (0, 0) to the bottom right i.e. ('N' - 1, 'M' - 1) which minimizes the sum of the cost of all the numbers along the path. You need to tell the minimum sum of that path.
#include <bits/stdc++.h>

 int minPtah(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp) {
  if (i == 0 and j == 0)
    return grid[i][j];

  if (i < 0 or j < 0)
    return 1e9;

  if (dp[i][j] != -1)
    return dp[i][j];

  int up = grid[i][j] + minPtah(i - 1, j, grid, dp);
  int left =  grid[i][j] + minPtah(i, j - 1, grid, dp);
  return dp[i][j] = min(up,left);
}

int minSumPath(vector<vector<int>> &grid) {
  int n = grid.size(), m = grid[0].size();
  vector<vector<int>> dp(n , vector<int>(m, -1));
  return minPtah(n - 1, m - 1, grid, dp);
} 