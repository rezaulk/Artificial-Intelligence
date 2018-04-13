#include<iostream>
#include<queue>
#include<vector>
#include<stack>
using namespace std;

typedef pair<int,int>par;
int parent[20];
int heuristic[20];
vector<par>adj[20];

class Node
{
public:
    int node,cost,comb_cost,parent;
    Node(int n,int c,int cc,int p)
    {
        node=n;
        cost=c;
        comb_cost=cc;
        parent=p;
    }
};

class Selection
{
public:
    bool operator()(Node lhs, Node rhs)
    {
        if(lhs.comb_cost!=rhs.comb_cost)
            return lhs.comb_cost>rhs.comb_cost;
        return lhs.node>rhs.node;
    }
};

bool astar(int u,int v)
{
    priority_queue<Node,vector<Node>,Selection>q;
    int node,cost,node2,cost2;
    q.push(Node(u,0,heuristic[u],0));
    while(!q.empty())
    {
        node=q.top().node;
        cost=q.top().cost;
        parent[node]=q.top().parent;
        if(node==v)
            return true;
        q.pop();
        for(int i=0; i<adj[node].size(); i++)
        {
            node2=adj[node][i].first;
            cost2=adj[node][i].second;
            q.push(Node(node2,cost+cost2,cost+cost2+heuristic[node2],node));
        }
    }
    return false;
}

int main()
{
    int node,edge,u,v,cost;
    cout<<"Enter Number Of Nodes and Edges :  ";
    cin >>node>>edge;
    cout<<"Enter Node,Edge and Cost       :  "<<endl;

    while(edge--)
    {
        cin>>u>>v>>cost;
        adj[u].push_back(make_pair(v,cost));
    }
    cout<<"Enter Hurestic value For nodes:"<<endl;
    for(int i=1; i<=node; i++)
    {
        cin>>heuristic[i];
    }
    cout<<"Enter the source node and destination node: ";
    cin >>u>>v;
    if(astar(u,v))
    {
        stack<int>st;
        int i=v;
        while(i!=0)
        {
            st.push(i);
            i=parent[i];
        }
        while(!st.empty())
        {
            if(st.top()==v)
                cout<<v<<endl;
            else
                cout<<st.top()<<"   ";
            st.pop();
        }
    }
    else
        cout<<"No path find"<<endl;
    return 0;
}

