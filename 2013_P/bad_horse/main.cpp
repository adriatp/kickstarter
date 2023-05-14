#include <bits/stdc++.h>
using namespace std;


bool color_graph_rec(map<string,set<string>> &graph, map<string,int> &colored, string node_to_pint, int color) {
    set<string> next_nodes_to_pint;
    if (colored[node_to_pint] != 0 && colored[node_to_pint] != color) return false;
    if (colored[node_to_pint] == 0) {
        colored[node_to_pint] = color; 
        next_nodes_to_pint.insert(graph[node_to_pint].begin(), graph[node_to_pint].end());
    }
    color *= -1;
    for (const auto &element : next_nodes_to_pint)
        if (!color_graph_rec(graph,colored,{element},color)) return false;
    return true;
}

bool color_graph(map<string,set<string>> &graph, map<string,int> &colored, set<string> nodes) {
    for ( const auto &element : nodes ) {
        if (colored[element] == 0 && !color_graph_rec(graph,colored,element,1))
            return false;
    }
    return true;
}

int main() {
    int n, m, j;
    string s, s1, s2;
    vector<int> responses;
    map<string,set<string>> graph;
    map<string,int> colored;
    set<string> intersect;
    set<string> nodes;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> m;
        getline(cin, s);
        for (j=0; j<m; j++) {
            getline(cin, s);
            s1 = s.substr(0, s.find(" "));
            s2 = s.substr(s.find(" ")+1, s.size());
            if (!graph.count(s1)) graph.insert({s1, set<string>()});
            if (!graph.count(s2)) graph.insert({s2, set<string>()});
            set_intersection(graph[s1].begin(), graph[s1].end(), graph[s2].begin(), graph[s2].end(), inserter(intersect, intersect.begin()));
            if (intersect.size() > 0) break;
            graph[s1].insert(s2);
            graph[s2].insert(s1);
        }
        if (intersect.size() == 0) {
            for ( const auto &pair : graph ) {
                nodes.insert({pair.first}); 
                colored.insert({pair.first, 0}); 
            }
            responses.push_back(color_graph(graph,colored,nodes));
        }
        else {
            for(j; j<m-1; j++) getline(cin, s);
            responses.push_back(false);
        }
        intersect.clear();
        colored.clear();
        nodes.clear();
        graph.clear();
    }
    for (int i = 0; i < responses.size(); i++)
        cout << "Case #" << (i+1) << ": " << (responses[i] ? "Yes" : "No") << endl;   
    return 0;
}
