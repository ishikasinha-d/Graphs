// a program which takes a graph as an input and outputs whether every node is connected or not
// Graph is undirected and unweighted
// Algorith used: DFS

#include<bits/stdc++.h>
#define fl(i,a,b) for(i=a;i<b;i++)
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
typedef long long int ll;

unordered_map< string, vector<string> > adj;
unordered_map< string , bool > vis;

// Depth First Search function 
int DFS( string src)
{  
    ll count=0;     //to count no. of nodes present in one component
    queue <string> q;
    q.push(src);

    while(!q.empty()){
        auto element = q.front();
        q.pop();

        for( auto x: adj[element]){
                if(!vis[x]){
                    q.push(x);
                    vis[x]=true;
                    count++;
                }
            }

    }
    return count;
}

int main()
{ 
   fast;

// #ifndef ONLINE_JUDGE
// freopen("input.txt","r",stdin);
// freopen("output.txt","w",stdout);
// #endif

//nodes: total no. of nodes in the graph
//edges: total no. of edges in the graph
//nodeA and nodeB are endpoints of each edge

ll nodes, edges;
string nodeA, nodeB;
cin>>nodes>>edges;

//adding edges
for(ll i=0; i<edges; i++ ){
    cin>>nodeA>>nodeB;
    adj[nodeA].push_back(nodeB);
    adj[nodeB].push_back(nodeA);
}

//logic: total no. of nodes must be equal to no. of nodes in one component if the grapgh is connected
if (nodes-DFS(nodeA)==0)
    cout<<"ALL NODES ARE CONNECTED"<<endl;
else 
    cout<<"ALL NODES ARE NOT CONNECTED"<<endl;
return 0;

}