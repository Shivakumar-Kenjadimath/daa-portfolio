
#include <iostream>
#include <vector>
using namespace std;

void KMPSearch(string pattern, string text) {
    int M = pattern.length();
    int N = text.length();

    vector<int> lps(M, 0);
    int j = 0;

    computeLPSArray(pattern, M, lps);

    int i = 0;
    while (i < N) {
        if (pattern[j] == text[i]) {
            j++;
            i++;
        }

        if (j == M) {
            cout << "Pattern found at index " << i - j << endl;
            j = lps[j - 1];
        } else if (i < N && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
}

void computeLPSArray(string pattern, int M, vector<int>& lps) {
    int length = 0;
    int i = 1;
    while (i < M) {
        if (pattern[i] == pattern[length]) {
            length++;
            lps[i] = length;
            i++;
        } else {
            if (length != 0) {
                length = lps[length - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

int main() {
    string text ;
    string pattern ;
    cin>>text>>pattern;
    cout<<text<<pattern<<endl;
    KMPSearch(pattern, text);
    return 0;
}
