# [2360. Longest Cycle in a Graph](https://leetcode.com/problems/longest-cycle-in-a-graph/description)

Recebe um gráfico direcionado de `n` nós numerados de `0 a n - 1`, onde cada nó tem no máximo uma aresta de saída. Retorna a duração do ciclo mais longo do gráfico . Se não houver ciclo, retorna `-1`.

# Lógica da Solução

Esta solução implementa uma variação eficiente do algoritmo DFS (Depth-First Search) adaptada especificamente para identificar o ciclo mais longo em um grafo direcionado. A abordagem mantém a essência do DFS - percorrer caminhos profundamente antes de explorar vizinhos - mas com otimizações inteligentes para o problema específico de detecção de ciclos.

# Submissão

![alt text](/assets/2360_sub.png)

# [Código](./2360_LongestCycleinaGraph.cpp)