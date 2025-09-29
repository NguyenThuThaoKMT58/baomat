#include <bits/stdc++.h>
using namespace std;
string columnar_encrypt(string pt, const vector<int>& key){
    int m = key.size();
    while(pt.size() % m) pt.push_back('X');
    int rows = pt.size()/m;
    vector<string> mat(rows, string(m,' '));
    int idx=0;
    for(int r=0;r<rows;r++) for(int c=0;c<m;c++) mat[r][c]=pt[idx++];
    string ct;
    for(int order=1; order<=m; ++order) for(int c=0;c<m;c++) if(key[c]==order) for(int r=0;r<rows;r++) ct.push_back(mat[r][c]);
    return ct;
}
string columnar_decrypt(string ct, const vector<int>& key){
    int m = key.size();
    int rows = ct.size() / m;
    vector<string> mat(rows, string(m,' '));
    int idx=0;
    for(int order=1; order<=m; ++order) for(int c=0;c<m;c++) if(key[c]==order) for(int r=0;r<rows;r++) mat[r][c]=ct[idx++];
    string pt;
    for(int r=0;r<rows;r++) for(int c=0;c<m;c++) pt.push_back(mat[r][c]);
    return pt;
}
int main(){ string pt; cout<<"Plain: "; getline(cin,pt); cout<<"Nhap key as numbers separated by space (e.g. 3 1 4 2): "; string line; getline(cin,line); if(line.empty()) getline(cin,line); stringstream ss(line); vector<int> key; int x; while(ss>>x) key.push_back(x); string ct = columnar_encrypt(pt,key); cout<<"Encrypted: "<<ct<<"\n"; cout<<"Decrypted: "<<columnar_decrypt(ct,key)<<"\n"; }
