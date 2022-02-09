#include<iostream>
using namespace std;

int main()
{
    char A[] = "zoom";
    char B[] = "zmoo";
    char H[26] = {0};
    string anagram = "Anagram";

    for(int i = 0; A[i] != '\0'; i++)
        H[A[i] - 97]++;

    for(int j = 0; B[j] != '\0'; j++)
        H[B[j] - 97]--;
    
    for(int i = 0; i < 26; i++)
    {
        if(H[i] != 0)
            anagram = "Not Anagram";
    }

    cout << anagram << endl;

    return 0;
}