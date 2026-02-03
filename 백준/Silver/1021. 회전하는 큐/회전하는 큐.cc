#include <iostream>
#include <deque>
#include <vector>

using namespace std;

void first_to_end(deque<int> &main_deq_) {
    main_deq_.push_back(main_deq_.front());
    main_deq_.pop_front();
}

void end_to_first(deque<int> &main_deq_) {
    main_deq_.push_front(main_deq_.back());
    main_deq_.pop_back();
}

void find_min(vector<int> orders_, deque<int> &main_deq_) {
    int result = 0;

    for (int pos : orders_) {

        int idx = 0;
        // pos의 값과 일치하는 현재 deque에서의 위치를 파악하는 반복문 필요
        for (int i = 0; i < int(main_deq_.size()); i ++) {
            if (pos == main_deq_[i]) {
                idx = i;
                break;
            }
        }

        if (idx < int(main_deq_.size()) / 2 + 1) {
            // cout << "push left" << endl;
            for (int i = 0; i < idx; i ++) {
                first_to_end(main_deq_);
                result += 1;
            }
            // cout << result << " now" << endl;

        } else {
            // cout << "push right" << endl;
            for (int i = 0; i < int(main_deq_.size()) - idx; i ++) {
                end_to_first(main_deq_);
                result += 1;
            }    
            // cout << result << " now" << endl;
        }

        // cout << main_deq_.front() << endl;
        main_deq_.pop_front();
    }

    cout << result << endl;
}

int main(void) {

    int N = 0, M = 0, box = 0;
    deque<int> main_deq;
    vector<int> orders;

    cin >> N >> M;

    // 뽑아낼 것들 순서대로 넣기
    for (int i = 0; i < M; i++) {
        cin >> box;
        orders.push_back(box - 1);
    }

    // 메인 덱 구성, 위치를 0부터 시작한다고 설정하고 덱 안에 앞에서부터 0부터 차곡차곡 넣기
    for (int i = 0; i < N; i++) {
        main_deq.push_back(i);
    }

    find_min(orders, main_deq);

    return 0;
}