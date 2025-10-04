#include <stdio.h>
#define TAMANHO 5  // Define o tamanho do vetor

// Função de ordenação Bolha (versão otimizada)
void bolha_otimizada(int *v)
{
    int i, j, aux;
    int troca;

    // O loop externo controla quantas passadas o vetor recebe
    for (i = 0; i < TAMANHO - 1; i++)
    {
        troca = 0; // Começa assumindo que não haverá trocas

        // O loop interno vai até TAMANHO - i - 1,
        // pois o maior elemento já foi colocado no fim a cada iteração
        for (j = 0; j < TAMANHO - i - 1; j++)
        {
            if (v[j] > v[j + 1])
            {
                aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
                troca = 1; // Marca que houve troca
            }
        }

        // Se nenhuma troca ocorreu, o vetor já está ordenado — pode parar
        if (troca == 0)
            break;
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

    bolha_otimizada(v);

    printf("\nVetor ordenado:\n");
    for (i = 0; i < TAMANHO; i++)
    {
        printf("%d ", v[i]);
    }

    printf("\n");
    return 0;
}