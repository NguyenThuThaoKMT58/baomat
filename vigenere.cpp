#include <bits/stdc++.h>
using namespace std;
string vigenere_encrypt(const string &pt, const string &key){
    string k; for(char c: key) if(isalpha(c)) k.push_back(toupper(c));
    string out=pt; int ki=0;
    for(size_t i=0;i<pt.size();++i){ char c=pt[i]; if(isalpha(c)){ bool up=isupper(c); char base = up? 'A':'a'; int p=c-base; int shift=(k[ki % k.size()] - 'A'); out[i] = char((p+shift)%26 + base); ki++; } else out[i]=c; }
    return out;
}
string vigenere_decrypt(const string &ct, const string &key){
    string k; for(char c: key) if(isalpha(c)) k.push_back(toupper(c));
    string out=ct; int ki=0;
    for(size_t i=0;i<ct.size();++i){ char c=ct[i]; if(isalpha(c)){ bool up=isupper(c); char base = up? 'A':'a'; int shift=(k[ki % k.size()] - 'A'); int p = ((c-base) - shift + 26) % 26; out[i] = char(p + base); ki++; } else out[i]=c; }
    return out;
}
int main(){ string t; cout<<"Text: "; getline(cin,t); string key; cout<<"Key: "; getline(cin,key); cout<<"Enc: "<<vigenere_encrypt(t,key)<<"\n"; cout<<"Dec: "<<vigenere_decrypt(vigenere_encrypt(t,key),key)<<"\n"; }
