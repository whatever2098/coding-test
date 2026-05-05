/*전체 격자를 돌다가 '1'을 만나면 새로운 섬을 발견한 것이므로 islandCount++ 한다.
그리고 BFS로 그 섬에 연결된 모든 '1'을 '0'으로 바꿔서 다시 세지 않게 만든다.
1. 전체 격자를 순회한다.
2. '1'을 만나면 새로운 섬이므로 islandCount++ 한다.
3. BFS로 그 섬에 연결된 모든 '1'을 '0'으로 바꾼다.
4. 이렇게 하면 같은 섬을 다시 세지 않는다.*/

//grid 자체를 바꾸는 방식

#include <vector>
#include <queue>
#include <utility>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, -1, 0, 1};

        int islandCount = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    //이 코드에서는 이미 방문한 육지는 BFS 과정에서 '0'으로 바꿔버린다.
                    //그래서 순회 중에 남아 있는 '1'은 무조건 아직 방문하지 않은 새로운 섬의 시작점이다.
                    islandCount++;

                    //섬에 연결된 모든 육지를 찾아야 -> BFS 시작 
                    queue<pair<int, int>> q;
                    q.push({i, j});  //앞으로 탐색할 좌표 넣기
                    grid[i][j] = '0'; //방문 처리

                    while (!q.empty()) {
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();

                        for (int dir = 0; dir < 4; dir++) {
                            int nx = x + dx[dir];
                            int ny = y + dy[dir];

                            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                            if (grid[nx][ny] == '0') continue;

                            grid[nx][ny] = '0'; //방문 처리
                            q.push({nx, ny});  //이 칸을 기준으로 다시 상하좌우를 탐색해야 하므로 큐에 넣는다.
                        }
                    }
                    //이 반복문이 끝났다는 것은: 처음 발견한 섬과 상하좌우로 연결된 모든 육지를 전부 '0'으로 바꿨다.는 뜻으로, 
                    //섬 하나를 완전히 처리한 것.
                }
            }
        }

        return islandCount;
    }
};