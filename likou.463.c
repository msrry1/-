int islandPerimeter(int** grid, int gridSize, int* gridColSize){
    int i,j,sum = 0;
    for(i = 0;i<gridSize;i++)
    {
        for(j = 0;j<gridColSize[0];j++)
        {
            if(grid[i][j])
            {
                sum += 4;
                if(i > 0)
                {
                    sum -= grid[i-1][j];
                }
                if(i < gridSize-1)
                {
                    sum -= grid[i+1][j];
                }
                if(j > 0)
                {
                    sum -= grid[i][j-1];
                }
                if(j < gridColSize[0]-1)
                {
                    sum -= grid[i][j+1];
                }
            }
        }
    }
    return sum;
}
