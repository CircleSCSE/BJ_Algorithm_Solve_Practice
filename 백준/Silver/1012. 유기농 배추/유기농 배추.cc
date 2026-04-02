#include <iostream>
#include <vector>

using namespace std;

int m, n;


void dfs(int r, int c, vector<vector<int>> &ground, vector<vector<bool>> &visited) {
    visited[r][c] = true;

    if(r + 1 < m && !visited[r + 1][c] &&  ground[r + 1][c] == 1) dfs(r + 1, c, ground, visited);
    if(r - 1 >= 0 && !visited[r - 1][c] &&  ground[r - 1][c] == 1) dfs(r - 1, c, ground, visited);
    if(c + 1 < n && !visited[r][c + 1] &&  ground[r][c + 1] == 1) dfs(r, c + 1, ground, visited);
    if(c - 1 >= 0 && !visited[r][c - 1] &&  ground[r][c - 1] == 1) dfs(r, c - 1, ground, visited);

}

int main() {
    int t, k;

    cin >> t;


    for (int i = 0; i < t; i ++) {
        cin >> m >> n >> k; // m이 가로, n이 세로

        vector<vector<int>> ground(m, vector<int>(n, 0));
        vector<vector<bool>> visited(m, vector<bool>(n, 0));
        
        ground.assign(m, vector<int>(n, 0));
        visited.assign(m, vector<bool>(n, false));


        int row, col;

        for (int j = 0; j < k; j ++) { 
            cin >> row >> col;
            ground[row][col] = 1; // 인덱스는 0부터 시작한다. 그래서 1을 빼야 함.
        }

        int count = 0;


        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (ground[i][j] == 1 && !visited[i][j]) {
                    dfs(i, j, ground, visited);
                    count ++;
                }
            }
        }

        cout << count << endl;

    }

    return 0;
}   