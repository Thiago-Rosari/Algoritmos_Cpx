#include <stdio.h>
#define TAMANHO 5  // Tamanho fixo do vetor

// Função de ordenação por inserção (Insertion Sort)
void insertion(int *v)
{
    int i, j, aux;

    // Começa em 1, pois o primeiro elemento (índice 0) já é considerado "ordenado"
    for (i = 1; i < TAMANHO; i++)
    {
        aux = v[i];     // Elemento a ser inserido
        j = i - 1;

        // Move os elementos maiores que 'aux' uma posição à frente
        while (j >= 0 && v[j] > aux)
        {
            v[j + 1] = v[j];
            j--;
        }

        // Insere o elemento na posição correta
        v[j + 1] = aux;
    }
}

int main()
{
    int v[TAMANHO];
    int i;

    printf("Digite %d numeros inteiros:\n", TAMANHO);
    for (i = 0; i < TAMANHO; i++)
    {
        scanf("%d", &v[i]);
    }

    insertion(v);

    printf("\nVetor ordenado:\n");
    for (i = 0; i < TAMANHO; i++)
    {
        printf("%d ", v[i]);
    }

    printf("\n");
    return 0;

    /*
        Exemplo:
        Entrada:

        5 3 4 1 2


       Execução passo a passo:

        Iteração 1 (i=1): insere 3 → [3, 5, 4, 1, 2]
        Iteração 2 (i=2): insere 4 → [3, 4, 5, 1, 2]
        Iteração 3 (i=3): insere 1 → [1, 3, 4, 5, 2]
        Iteração 4 (i=4): insere 2 → [1, 2, 3, 4, 5]
    */
}