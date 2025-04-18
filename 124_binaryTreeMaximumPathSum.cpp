// Autor: Lívia Rodrigues Reis - 180105051
// Leetcode Hard :: 124. Binary Tree Maximum Path Sum
// https://leetcode.com/problems/binary-tree-maximum-path-sum/description/

#include <climits>  
#include <algorithm> 
using namespace std;

class Solution {
public:
    int maxSum; // Armazena o maior valor de soma encontrado

    // Função principal chamada externamente
    int maxPathSum(TreeNode* root) {
        maxSum = INT_MIN;  // Inicializa com o menor valor possível
        helper(root);      // Chama a função auxiliar para percorrer a árvore
        return maxSum;     // Retorna a maior soma encontrada
    }

private:
    // Função auxiliar recursiva que calcula a maior soma possível passando por cada nó
    int helper(TreeNode* root) {
        if (root == nullptr) return 0;  // Caso base: nó nulo retorna 0

        // Calcula a maior soma da subárvore esquerda (ignora negativos com max(0, ...))
        int left = max(0, helper(root->left));
        // Calcula a maior soma da subárvore direita (também ignorando negativos)
        int right = max(0, helper(root->right));

        // Soma total passando pelo nó atual (esquerda + valor do nó + direita)
        int sum = root->val + left + right;

        // Atualiza a maior soma global se essa for maior
        maxSum = max(maxSum, sum);

        // Retorna o maior caminho possível para continuar subindo na árvore
        return max(left, right) + root->val;
    }
};
