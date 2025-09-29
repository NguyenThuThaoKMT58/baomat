#include <bits/stdc++.h>
using namespace std;
int modInv(int a,int m){ a = (a%m + m)%m; for(int x=1;x<m;x++) if((a*x)%m==1) return x; return -1; }
string affine_encrypt(const string &s,int a,int b){ string out=s; for(size_t i=0;i<s.size();++i){ char c=s[i]; if(isalpha(c)){ bool up=isupper(c); char base = up? 'A':'a'; int x = c-base; int y = (a*x + b) % 26; out[i] = char(y + base);} else out[i]=c;} return out; }
string affine_decrypt(const string &s,int a,int b){ int inv = modInv(a,26); if(inv==-1) return "Invalid a"; string out=s; for(size_t i=0;i<s.size();++i){ char c=s[i]; if(isalpha(c)){ bool up=isupper(c); char base = up? 'A':'a'; int y = c-base; int x = (inv * ( (y - b + 26) % 26 )) % 26; out[i] = char(x + base);} else out[i]=c;} return out; }
int main(){ string t; int a,b; cout<<"Text: "; getline(cin,t); cout<<"a b: "; cin>>a>>b; cout<<"Enc: "<<affine_encrypt(t,a,b)<<"\n"; cout<<"Dec: "<<affine_decrypt(affine_encrypt(t,a,b),a,b)<<"\n"; }
