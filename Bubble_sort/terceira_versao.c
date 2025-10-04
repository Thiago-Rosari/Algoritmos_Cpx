#include <stdio.h>
#define TAMANHO 5  // Tamanho fixo do vetor (pode alterar se quiser)

// Função para exibir o vetor
void exibirVetor(int *v)
{
    for (int i = 0; i < TAMANHO; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");
}

// Função de ordenação Bolha (versão passo a passo)
void bolha_passo_a_passo(int *v)
{
    int i, j, aux, troca;

    printf("\n--- Iniciando o processo de ordenacao ---\n");

    for (i = 0; i < TAMANHO - 1; i++)
    {
        troca = 0;
        printf("\nPassada %d:\n", i + 1);

        for (j = 0; j < TAMANHO - i - 1; j++)
        {
            printf("Comparando %d e %d -> ", v[j], v[j + 1]);

            if (v[j] > v[j + 1])
            {
                // Faz a troca
                aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
                troca = 1;
                printf("trocou -> ");
            }
            else
            {
                printf("ok -> ");
            }

            // Mostra o vetor após cada comparação
            exibirVetor(v);
        }

        if (troca == 0)
        {
            printf("Nenhuma troca realizada nesta passada. Vetor ja ordenado!\n");
            break;
        }
    }

    printf("\n--- Fim da ordenacao ---\n");
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

    printf("\nVetor original:\n");
    exibirVetor(v);

    bolha_passo_a_passo(v);

    printf("\nVetor ordenado final:\n");
    exibirVetor(v);

    printf("\n");
    return 0;
}