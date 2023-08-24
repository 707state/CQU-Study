#include <bits/stdc++.h>
using namespace std;  
  
void computeLPSArray(const string& pattern, const string& text, vector<int>& lps) {  
    int len = pattern.size();  
    int i = 0; // index for text[]  
    int j = 0; // index for pattern[]  
    while (i < text.size()) {  
        if (pattern[j] == text[i]) {  
            j++;  
            i++;  
        }  
        if (j == len) {  
            lps[i] = j; // longest prefix suffix  
            j = 0;  
        } else if (i < text.size() && pattern[j] != text[i]) {  
            if (j != 0)  
                j = lps[j - 1]; // longest prefix suffix match  
            else  
                i++;  
        }  
    }  
}  
  
void KMP(const string& text, const string& pattern) {  
    int n = text.size();  
    int m = pattern.size();  
    vector<int> lps(m, 0); // compute lps[] in advance  
    computeLPSArray(pattern, text, lps);  
    int i = 0; // index for text[]  
    int j = 0; // index for pattern[]  
    while (i < n) {  
        if (pattern[j] == text[i]) {  
            j++;  
            i++;  
        }  
        if (j == m) {  
            cout << "Pattern found at index: " << i - j << endl;  
            j = 0;  
        } else if (i < n && pattern[j] != text[i]) {  
            if (j != 0)  
                j = lps[j - 1]; // longest prefix suffix match  
            else  
                i++;  
        }  
    }  
}  