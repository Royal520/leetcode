#include<bits/stdc++.h>

using namespace std;

long long solve(int n,int m) {
    vector<vector<int>> land(n,vector<int> (m));
    vector<int> row(n);
    vector<int> col(n);
    long long sum=0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin>>land[i][j];
            row[i]+=land[i][j];
        }
        sum+=row[i];
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            col[i]+=land[j][i];
        }
    }
    long long minRow=sum;
    long long sumR=0;
    for (const auto &item: row){
        sumR+=item;
        minRow= min(minRow,abs(sum-2*sumR));
    }
    long long sumC=0;
    long long minC=sum;
    for (const auto &item: col){
        sumC+=item;
        minC= min(minC,abs(sum-2*sumC));
    }
    return min(minC,minRow);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,m;
    cin>>n>>m;

    cout<<solve(n,m);
    return 0;
}