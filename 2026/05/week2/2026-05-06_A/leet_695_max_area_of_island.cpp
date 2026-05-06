#include <vector>
#include <queue>
using namespace std;

class Solution {
    public:
    int maxAreaOfIsland(vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();

        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, -1, 0, 1};

        int result{0};

        for(int i{0};i < n;i++){
            for(int j{0};j < m;j++){
                if(!grid[i][j]) continue;
                
                queue<pair<int, int>> q;
                q.push({i, j});
                grid[i][j] = 0;

                int oneArea{0};
                while(!q.empty()){
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();

                    oneArea++;

                    for(int dir{0};dir < 4;dir++){
                        int new_x = x + dx[dir];
                        int new_y = y + dy[dir];

                        if(new_x < 0 || new_x >= n || new_y < 0 || new_y >= m) continue;
                        if(!grid[new_x][new_y]) continue;

                        grid[new_x][new_y] = 0;
                        q.push({new_x, new_y});

                    }
                }
                result = max(result, oneArea);
            }
        }
        return result;
    }
}