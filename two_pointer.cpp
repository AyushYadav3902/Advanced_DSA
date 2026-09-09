#include <iostream>
#include <cctype>
using namespace std;

int main(){
    string S;
    cin >> S;

    string ans = S;

    int i = 0;
    int j = S.length() - 1;
while(i < j){
        if(!isalpha(S[i])){
            i++;
            continue;
        }
        if(!isalpha(S[j])){
            j--;
            continue;
        }
        ans[i] = S[j];
        ans[j] = S[i];
        i++;
        j--;
    }

    cout << ans << endl;

    return 0;
}