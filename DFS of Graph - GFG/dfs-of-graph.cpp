//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
     vector<int>ans;
    void dfs(vector<int>adj[],int s,bool visited[]){
        visited[s]=true;
        ans.push_back(s);
        for(int u:adj[s]){
            if(visited[u]==false)
                dfs(adj,u,visited);
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        bool visited[V];
        for(int i=0;i<V;i++)
            visited[i]=false;
        for(int i=0;i<V;i++){
            if(visited[i]==false){
                dfs(adj,i,visited);
            }
        }
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends