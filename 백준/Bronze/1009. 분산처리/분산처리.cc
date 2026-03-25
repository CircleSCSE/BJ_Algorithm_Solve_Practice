#include <iostream>
#include <cmath>

using namespace std;

int main() {

    long long data;
    int n, a, b;
    cin >> n;
    
    for (int i = 0; i < n; i ++) {
        data = 1;
        cin >> a >> b;  


        for (int j = 0; j < b; j ++) {
            data *= a;
            data = data % 10; // 아.. 어차피 1의 자리만 필요하니까 10 위로는 날려버리는거구나.
        }

        if (data % 10 == 0) cout << 10 << endl;
        else cout << data % 10 << endl;
    }


    // 마지막 처리 될 번호


    return 0;
}