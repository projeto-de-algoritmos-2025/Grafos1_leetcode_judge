// Autor: Leonardo Fernandes - 200067036
// Leetcode Hard :: 2360. Longest Cycle in a Graph
// https://leetcode.com/problems/longest-cycle-in-a-graph/description/
#include <vector>
#include <unordered_set>

class Solution {
    public:
        int longestCycle(std::vector<int>& edges) {
           int n = edges.size(); // n = tamanho do vetor, vetor que mostra que o edges[i] = 0, ou seja, que o nó i conecta ao nó 0
           std::vector<bool> visitados(n, false); // vetor que marca se um no ja foi visitado
           int res = -1; // resposta inicializada em -1 caso nao encontre um ciclo

           for(int i = 0; i < n; i++){
                if(visitados[i]) continue; // se o no nao foi visitado continue

                std::unordered_set<int> caminho; // set de caminho
                int no_atual = i;

                while(true){
                    if(no_atual == -1 || visitados[no_atual]) break;

                    if(caminho.count(no_atual)){ // se existir algum no igual o no_atual dentro do caminho
                        int tam = 1; // inicia o contador do caminho
                        int no = edges[no_atual]; // armazena o no
                        while (no != no_atual){ // enquanto os n no's seguintes forem diferentes ao no atual
                            tam++; // +1 no caminho
                            no = edges[no]; // percorre o grafo
                        }

                        res = std::max(res, tam); // pega o maior valor entre o maior caminho e o que foi analisado agora
                        break;
                    }

                    caminho.insert(no_atual);
                    no_atual = edges[no_atual];
                }

                for(int no : caminho){
                    visitados[no] = true;
                }
           }

           return res;
        }
    };