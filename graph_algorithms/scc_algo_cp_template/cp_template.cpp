#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstring>

using namespace std;

// ---------- FAST INPUT/OUTPUT ----------
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

// ---------- TYPEDEFS AND CONSTANTS ----------
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int N = 1e5 + 5; // Adjust size accordingly

// ---------- GLOBAL VARIABLES ----------
vector<int> adj[N];  // Graph
vector<int> radj[N]; // Reverse Graph (Kosaraju)
bool visited[N];
vector<int> sccs[N]; // Stores components in Kosaraju

// ---------- TARJAN VARIABLES ----------
int disc[N], low[N], timer;
bool inStack[N];
stack<int> st;
int scc_count_tarjan;

// ---------- TARJAN'S ALGORITHM ----------
void tarjan_dfs(int u)
{
    disc[u] = low[u] = ++timer;
    st.push(u);
    inStack[u] = true;

    for (int v : adj[u])
    {
        if (!disc[v])
        {
            tarjan_dfs(v);
            low[u] = min(low[u], low[v]);
        }
        else if (inStack[v])
        {
            low[u] = min(low[u], disc[v]);
        }
    }

    if (low[u] == disc[u])
    {
        ++scc_count_tarjan;
        cout << "Tarjan SCC #" << scc_count_tarjan << ": ";
        while (true)
        {
            int v = st.top();
            st.pop();
            inStack[v] = false;
            cout << v << " ";
            if (v == u)
                break;
        }
        cout << "\n";
    }
}

void tarjan(int n)
{
    timer = 0;
    scc_count_tarjan = 0;
    memset(disc, 0, sizeof(disc));
    memset(low, 0, sizeof(low));
    memset(inStack, 0, sizeof(inStack));

    for (int i = 1; i <= n; ++i)
    {
        if (!disc[i])
        {
            tarjan_dfs(i);
        }
    }
}

// ---------- KOSARAJU'S ALGORITHM ----------
vector<int> order;
int scc_count_kosaraju;

void dfs1(int u)
{
    visited[u] = true;
    for (int v : adj[u])
    {
        if (!visited[v])
            dfs1(v);
    }
    order.push_back(u);
}

void dfs2(int u, int comp_id)
{
    visited[u] = true;
    sccs[comp_id].push_back(u);

    for (int v : radj[u])
    {
        if (!visited[v])
            dfs2(v, comp_id);
    }
}

void kosaraju(int n)
{
    memset(visited, 0, sizeof(visited));
    order.clear();

    // 1st pass to get finishing order
    for (int i = 1; i <= n; ++i)
    {
        if (!visited[i])
            dfs1(i);
    }

    memset(visited, 0, sizeof(visited));
    scc_count_kosaraju = 0;

    // 2nd pass on reversed graph
    reverse(order.begin(), order.end());
    for (int u : order)
    {
        if (!visited[u])
        {
            ++scc_count_kosaraju;
            dfs2(u, scc_count_kosaraju);
        }
    }

    // Print SCCs
    for (int i = 1; i <= scc_count_kosaraju; ++i)
    {
        cout << "Kosaraju SCC #" << i << ": ";
        for (int v : sccs[i])
        {
            cout << v << " ";
        }
        cout << "\n";
    }
}

// ---------- CLEAR GRAPH ----------
void clear_graph(int n)
{
    for (int i = 0; i <= n; ++i)
    {
        adj[i].clear();
        radj[i].clear();
        sccs[i].clear();
    }
    while (!st.empty())
        st.pop();
}

// ---------- DRIVER ----------
int main()
{
    fastio;

    int n, m;
    cin >> n >> m; // Number of nodes and edges

    clear_graph(n);

    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        radj[v].push_back(u);
    }

    cout << "====== Tarjan's Algorithm ======\n";
    tarjan(n);

    cout << "\n====== Kosaraju's Algorithm ======\n";
    kosaraju(n);

    return 0;
}
