#include <iostream>
#include <cctype>
#include <utility>
using namespace std;

int main() {
    string S;
    cin >> S;

    int left = 0;
    int right = S.length() - 1;

    while (left < right) 
    
        while (left < right && !isalpha(S[left])) {
            left++;
        }

        while (left < right && !isalpha(S[right])) {
            right--;
        }

        if (left < right) {
            swap(S[left], S[right]);

            left++;
            right--;
        }
    }

    cout << S;

    return 0;
}