#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
int N,M,a,b;
struct node {
    int id;
    node *prev,*next;
    node() {
        prev=NULL;
        next=NULL;
    }
};
node *cars[100010];
int main() {
    fastio;
    cin>>N>>M;
    for(int i=0;i<=N+2;i++) {
        cars[i]=new node();
        cars[i]->id=i;
    }
    for(int i=1;i<=N+2;i++) {
        cars[i]->prev=cars[i-1];
        cars[i]->next=cars[i+1];
    }
    for(int i=0;i<M;i++) {
        int a,b;
        cin>>a>>b;
        if(a==0) {
            cars[b]->prev->next=cars[b]->next;
            cars[b]->next->prev=cars[b]->prev;
        }else {
            if(!cars[b]->prev->prev) continue;
            int pp,p,n;
            pp=cars[b]->prev->prev->id;
            p=cars[b]->prev->id;
            n=cars[b]->next->id;
            cars[pp]->next=cars[b];
            cars[b]->prev=cars[pp];
            cars[b]->next=cars[p];
            cars[p]->next=cars[n];
            cars[n]->prev=cars[p];
            cars[p]->prev=cars[b];
        }
    }
    stack<int> ans;
    int idx=N+1;
    while(cars[idx]->prev!=NULL) {
        if(idx!=N+1) {
            ans.push(cars[idx]->id);
        }
        idx=cars[idx]->prev->id;
    }
    while(!ans.empty()) {
        if(ans.size()==1) {
            cout<<ans.top()<<'\n';
            return 0;
        }
        cout<<ans.top()<<" ";
        ans.pop();
    }
}