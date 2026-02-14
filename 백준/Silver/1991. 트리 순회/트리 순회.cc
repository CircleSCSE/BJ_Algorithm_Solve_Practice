#include <iostream>
#include <vector>

using namespace std;


// 26이라는 숫자를 굳이 넣는 이유 : 일단 빈 vector이더라도 인덱스를 넣어서 인식하려면, 할당은 미리 해놔야한다. 안 그러면 Segmentation error뜬다.
// adj라는 벡터 안에 벡터가 26개 있다는 뜻이다.
vector<vector<int>> adj(26);

// 문자를 숫자로 변환함.
int char_to_int(char c) {
    if (c == '.') return -1;
    return c - 'A'; 
}

char int_to_char(int i) {
    return i + 'A';
}

// 전위 순회는 root -> left -> right로 순회함
void preorder(int curr) {
    if (curr == -1) return;

    cout << int_to_char(curr); 
    preorder(adj[curr][0]); // 각 알파벳의 인덱스 0번을 왼쪽 자식, 1을 오른쪽 자식으로 통일
    preorder(adj[curr][1]);
}

// 중위 순회는 left -> root -> right
void inorder(int curr) {
    if (curr == -1) return;

    inorder(adj[curr][0]); 
    cout << int_to_char(curr); 
    inorder(adj[curr][1]);
}

// 후위 순회는 left -> right -> root
void postorder(int curr) {
    if (curr == -1) return;

    postorder(adj[curr][0]); 
    postorder(adj[curr][1]);
    cout << int_to_char(curr); 
}

int main(void) {
    int n;
    cin >> n;

    // 트리 구축 반복문 

    for (int i = 0; i < n; i++) { // i = 0, i < n 으로 돌리면 n번 돌아간다. 이 형태를 기억해라.
        char p, l, r;

        cin >> p >> l >> r;

        int p_int = char_to_int(p);
        adj[p_int].push_back(char_to_int(l));
        adj[p_int].push_back(char_to_int(r));
    }

    preorder(0); // 0 이 A 에 해당되는 숫자임.
    cout << endl;
    inorder(0);
    cout << endl;
    postorder(0);
    cout << endl;

    return 0; 
}