#include <bits/stdc++.h>
using namespace std;
string caesar_encrypt(const string &s, int k){
    string out=s;
    k = (k%26+26)%26;
    for(size_t i=0;i<s.size();++i){
        char c=s[i];
        if(isalpha(c)){
            bool upper = isupper(c);
            char base = upper? 'A':'a';
            out[i] = char((c - base + k) % 26 + base);
        } else out[i]=c;
    }
    return out;
}
string caesar_decrypt(const string &s, int k){ return caesar_encrypt(s, -k); }
int main(){ string text; int k; cout<<"Nhap text: "; getline(cin, text); cout<<"Nhap key k (0-25): "; cin>>k; cout<<"Encrypted: "<<caesar_encrypt(text,k)<<"\n"; cout<<"Decrypted: "<<caesar_decrypt(caesar_encrypt(text,k),k)<<"\n"; }
