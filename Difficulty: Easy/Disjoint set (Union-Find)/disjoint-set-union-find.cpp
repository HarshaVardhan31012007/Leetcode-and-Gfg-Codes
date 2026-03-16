/*Complete the functions below*/
// int find(int par[], int x) {
//     if(par[x]==x) return x;
//     return par[x]=find(par,par[x]);
// }

// void unionSet(int par[], int x, int z) {
//     int u=par[x];
//     int v=par[z];
//     if(u==v) return;
//     if(rank[u]<rank[v]){
//         par[u]=v;
//     }
//     else if(rank[u]>rank[v]){
//         par[v]=u;
//     }
//     else{
//         par[v]=u;
//         rank[u]++;
//     }
// }


int find(int par[], int x) {
    if(par[x]==x) return x;
    return par[x]=find(par,par[x]);
}

void unionSet(int par[], int x, int z) {
    int u=find(par,x);
    int v=find(par,z);
    if(u==v) return;
    par[u]=v;
}

// class DSU{
//     public:
//     vector<int>parent,size; 
//     DSU(int n){
//       parent.resize(n);
//       rank.resize(n,0);
//       for(int i=0;i<n;i++)
//       parent[i]=i;
//     }
// };