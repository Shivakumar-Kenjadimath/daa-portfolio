
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define d 256
#define q 101

void rabinKarp(string text, string pattern) {
    int M = pattern.length();
    int N = text.length();
    int i, j;
    int p = 0;
    int t = 0;
    int h = 1;

    for (i = 0; i < M - 1; i++)
        h = (h * d) % q;

    for (i = 0; i < M; i++) {
        p = (p * d + pattern[i]) % q;
        t = (t * d + text[i]) % q;
    }

    for (i = 0; i <= N - M; i++) {
        if (p == t) {
            for (j = 0; j < M; j++) {
                if (text[i + j] != pattern[j])
                    break;
            }
            if (j == M) {
                cout << "Pattern found at index " << i << endl;
            }
        }

        if (i < N - M) {
            t = (d * (t - text[i] * h) + text[i + M]) % q;

            if (t < 0)
                t = (t + q);
        }
    }
}

int main() {
    string text;
    string pattern;
    cin>>text>>pattern;
    cout<<text<<pattern<<endl;
    rabinKarp(text, pattern);
    return 0;
}
