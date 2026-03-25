#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, m, pack_num, pack_remain, res_sum;

    int pack_min = 1001, seperated_min = 1001;
    int pack, seperated;

    cin >> n >> m;

    pack_num = n / 6; // 6으로 나눈 몫
    pack_remain = n % 6; // 낱개 개수

    for (int i = 0; i < m; i ++) {
        cin >> pack >> seperated;

        if (pack_min > pack) {
            pack_min = pack;
        }
        
        if (seperated_min > seperated) {
            seperated_min = seperated;
        }
    }

    
    int option1;

    if (pack_remain != 0) {
        option1 = (pack_num + 1) * pack_min;  // 패키지만
    } else {
        option1 = pack_num * pack_min;
    }

    if (n < 6) option1 = pack_min;

    int option2 = n * seperated_min;                             // 낱개로만
    int option3 = pack_num * pack_min + pack_remain * seperated_min;  // 섞어서

    res_sum = min({option1, option2, option3});

    cout << res_sum << endl;

    return 0;
}