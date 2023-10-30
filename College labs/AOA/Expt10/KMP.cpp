#include <bits/stdc++.h>
using namespace std;

void computeLPSArray(string pat, int M, int lps[])
{
    // length of the previous longest prefix suffix
    int len = 0;
  
    lps[0] = 0; // lps[0] is always 0
    lps[1] = 0; // lps[0] is always 0
  
    // the loop calculates lps[i] for i = 1 to M-1
    int i = 2;
    while (i <= M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else // (pat[i] != pat[len])
        {
            // This is tricky. Consider the example.
            // AAACAAAA and i = 7. The idea is similar
            // to search step.
            if (len != 0) {
                len = lps[len - 1];
  
                // Also, note that we do not increment
                // i here
            }
            else // if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}
int kmp(string txt, string pat, int m, int n){
    int lps[m+1];
    computeLPSArray(pat,n,lps);
    for(int i=0;i<=n;i++) cout<<lps[i]<<" ";

    return 0;
}


int main()
{
	string str1, str2;
	// cout << "Enter string 1 :";
	// cin >> str1;
	// cout << "Enter string 2 :";
	// cin >> str2;
    str1="abcdabc";str2="aaabcbc";
	int m = str1.length();
	int n = str2.length();
	printf("\n\nLength of LCS is : %d\n", kmp(str1, str2, m, n));
	return 0;
}
