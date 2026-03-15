#include <iostream>
#include <vector>

using namespace std;


int main() {
    int n, a, b;
    cin >> n >> a >> b;

    int count = 0;

    while (a != b) {
        // a = 10 -> 5 -> 3 -> 2, b = 15 -> 8 -> 4 -> 2

        if (count > 50000) break;

        if (a % 2 != 0) { 
            a = (a + 1) / 2;
        } else {
            a = a / 2;
        }

        if (b % 2 != 0) b = (b + 1) / 2;
        else b = b / 2;
        
        count ++;

    }

    cout << count << endl;
    
}