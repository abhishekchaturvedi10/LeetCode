class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {

        if (grid[0][1] > 1 && grid[1][0] > 1) return -1;
        
        int rows = grid.size();
        int cols = grid[0].size();
        
        priority_queue<vector<int>,vector<vector<int>>,greater<>> minHeap;
        
        minHeap.push({0, 0, 0});
        
        vector<vector<int>> seen(rows, vector<int>(cols, 0));
        seen[0][0] = 1;
        
        vector<pair<int, int>> moves = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        
        while (!minHeap.empty()) {

            vector<int> curr = minHeap.top();
            int currTime = curr[0];
            int currRow = curr[1];
            int currCol = curr[2];
            
            minHeap.pop();
            
            if (currRow == rows - 1 && currCol == cols - 1) 
                return currTime;
            
            for (auto move : moves) {

                int nextRow = move.first + currRow;
                int nextCol = move.second + currCol;
                
                if (nextRow >= 0 && nextCol >= 0 && nextRow < rows && nextCol < cols && !seen[nextRow][nextCol]) {
                    
                    int waitTime = ((grid[nextRow][nextCol] - currTime) % 2 == 0) ? 1 : 0;
                    int nextTime = max(currTime + 1, grid[nextRow][nextCol] + waitTime);
                    
                    minHeap.push({nextTime, nextRow, nextCol});
                    seen[nextRow][nextCol] = 1;
                }
            }
        }
        return -1;
    }
};