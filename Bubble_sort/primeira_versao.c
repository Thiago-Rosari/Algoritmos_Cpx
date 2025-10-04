#include <stdio.h>
#define TAMANHO 5  // Define o tamanho do vetor

// Função de ordenação Bolha (Bubble Sort)
void bolha(int *v)
{
    int troca = 1;
    int i = 0;
    int aux;

    while (troca)
    {
        troca = 0; // Assume que não haverá trocas nesta passagem
        while (i < TAMANHO - 1)
        {
            if (v[i] > v[i + 1])
            {
                aux = v[i];
                v[i] = v[i + 1];
                v[i + 1] = aux;
                troca = 1; // Marca que houve troca
            }
            i++;
        }
        i = 0; // Reinicia o índice para nova varredura
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

    // Chama a função de ordenação
    bolha(v);

    // Exibe o vetor ordenado
    printf("\nVetor ordenado:\n");
    for (i = 0; i < TAMANHO; i++)
    {
        printf("%d ", v[i]);
    }

    printf("\n");
    return 0;


    /*
        Explicando o funcionamento:

#define TAMANHO 5: define o tamanho fixo do vetor (você pode alterar).

A função bolha() percorre o vetor várias vezes, trocando os elementos fora de ordem.

O processo repete enquanto houver trocas (troca == 1).

O main() lê os valores, chama a função e exibe o vetor já ordenado.
    */
}