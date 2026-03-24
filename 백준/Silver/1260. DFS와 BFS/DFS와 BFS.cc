#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

vector<int> adj[1001];
bool visited[1001];

void dfs(int now) {
    visited[now] = true;
    cout << now << " ";
    
    for (size_t i = 0; i < adj[now].size(); i ++) {
        int next_node = adj[now][i];

        if (!visited[next_node]) {
            dfs(next_node);
        }
    }
}

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    // 내 기억에 자료구조 수업 때 큐로 BFS를 하는 경우, 다음에 방문할 노드를 큐에 넣어서 큐가 FIFO 니까 들어간 순서대로 처리된다는 이유로 큐를 썼던 것 같다.
    while(!q.empty()) { // 비어있지 않은 동안 -> 루프한다. ( 이산 수학의 논리식이 이 코드 이해에 도움이 된다. )
        int now = q.front();
        q.pop();

        cout << now << " ";

        for (size_t i = 0; i < adj[now].size(); i ++) {
            int next_node = adj[now][i];

            if (!visited[next_node]) {

                visited[next_node] = true;
                q.push(next_node);
            }
        }
    }
}

int main(void) {
    int n, m, v;

    cin >> n >> m >> v;

    int a, b;

    for (int i = 0; i < m; i ++) {
        cin >> a >> b;
        
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i <= n; i ++) {
        sort(adj[i].begin(), adj[i].end());
    }

    memset(visited, false, sizeof(visited));
    dfs(v);
    cout << "\n";

    memset(visited, false, sizeof(visited));
    bfs(v);
    cout << "\n";


    return 0;
}