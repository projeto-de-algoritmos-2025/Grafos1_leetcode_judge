// Autor: Leonardo Fernandes - 200067036
// Leetcode Medium :: 785. Is Graph Bipartite?
// https://leetcode.com/problems/is-graph-bipartite/description/

#include <vector>
#include <queue>

using namespace std;

class Solution {
    public:
        bool isBipartite(vector<vector<int>>& graph) {
            int n = graph.size();
            vector<int> cor(n, -1);
            queue<int> fila;

            for(int i = 0; i < n; i++) {
                if(cor[i] != -1) continue;

                fila.push(i);
                cor[i] = 0;

                while (!fila.empty()) {
                    int u = fila.front();
                    fila.pop();
                    
                    for(int adj : graph[u]){
                        if(cor[adj] == -1){
                            cor[adj] = 1 - cor[u];
                            fila.push(adj);
                        } else if(cor[adj] == cor[u])
                            return false;
                    }
                } 
            }

            return true;
        }
    };