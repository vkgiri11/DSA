// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
/**
we are supposed to find the topological sort of the character
by the input array we decide which character which character comes first
like for eg if we look at {"baa","abcd","abca","cab","cad"} ..

(check for first non similar character)

b comes before a by seeing first character.
now for 2nd and 3rd string of array ,abc are same for both string and then d comes before a
a comes before c from 3rd and 4th string of array.
for 4th and 5th string in array ca is same and b comes before d
now our graph with this would look like

a      b      c      d

[[c], [a, d], [], [a]]
use topological sort on the graph and stack is the result we need
*/
class Solution{
    public:
    void topoSort(int node, vector<int> adj[], vector<int> &vis, 
		stack<int> &st) {
        vis[node] = 1;
        
        for(auto it : adj[node]) {
            if(!vis[it]) topoSort(it, adj, vis, st);
        }
        
        st.push(node);
    }
    string findOrder(string dict[], int N, int K) {
        // Converting the Given Dictionary of String into Graph By
        // comparing each letter in two consecutive Words of the Dict.
        vector<int> adj[K];
        
        for(int i = 0; i < N-1; i++) {
            string s1 = dict[i];
            string s2 = dict[i+1];
            
            for(int j = 0; j < min(s1.length(), s2.length()); j++) {
                if(s1[j] != s2[j]) {
                    adj[s1[j]-'a'].push_back(s2[j]-'a');
                    break;
                }
            }
        }
        
        // DFS Toposort
        stack<int> st;
        vector<int> vis(K, 0);
        
        for(int i = 0; i < K; i++) {
            if(!vis[i]){
                topoSort(i, adj, vis, st);
            }
        }
        
        string ans = "";
        while(!st.empty()) {
            ans += (st.top() + 'a');
            st.pop();
        }
        
        return ans;
    }
};

// { Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends