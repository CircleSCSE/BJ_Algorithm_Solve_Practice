#include <iostream>
#include <deque>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

void go_end(deque<string> &qu) {
    string box;
    box = qu.front();

    qu.pop_front();
    qu.push_back(box);
}

void go_front(deque<string> &qu) {
    string box;
    box = qu.back();

    qu.pop_back();
    qu.push_front(box);
}

int direction_select_n_go(deque<string> &qu, string exs_content) {
    int idx = 0;
    int move = 0;
    // cout << qu.size() << " q_size" << endl;

    for (int i = 0; i < int(qu.size()); i++) {
        if (qu[i] == exs_content) {
            idx = i;
            break;
        }
    }

    if (int(qu.size())/2 < idx) {
        // cout << "go left" << endl;
        move = qu.size() - idx;
        // cout << move << endl;

        for (int i = 0; i < move; i++) {
            go_front(qu);
        }
        // cout << qu.front() << " ext" << endl;
        qu.pop_front();

        return move;

    } else {
        // cout << "go right" << endl;
        move = idx;
        // cout << move << endl;

        for (int i = 0; i < move; i++) {
            go_end(qu);
        }
        // cout << qu.front() << " ext" << endl;
        qu.pop_front();

        return move;
    }
}

int main(void) {
    int els, exs;
    int total = 0;
    vector<string> vec_exs;
    deque<string> q_main;
    string input;

    cin >> els >> exs;

    cin.ignore(); // getline은 쓰기 전에 앞에 남은 \n를 지워줘야 한다.
    getline(cin, input);
    stringstream ss(input);
    
    string word;

    while (ss >> word) {
        vec_exs.push_back(word);
    }
    // ------ 여기까지가 추출할 것 순서대로 있는 큐에 원소 넣기 -------

    for (int i = 1;i <= els; i++) { // 조건문은 '선언; 조건; 증감' 으로 짜야한다.
        q_main.push_back(to_string(i));
    }
    // ------ 여기까지가 메인 덱에 원소 넣기 -------

    // 이제, 앞과 뒤로 가는 것 중 더 짧은 것을 파악해서 움직이고 pop 하는 것 반복.


    
    for (string w : vec_exs) {
        total += direction_select_n_go(q_main, w);
    }

    cout << total;

    return 0;
}