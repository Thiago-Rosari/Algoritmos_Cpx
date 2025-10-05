#include <stdio.h>
#define TAMANHO 5  // Tamanho fixo do vetor

// Função auxiliar para exibir o vetor
void exibirVetor(int *v)
{
    for (int i = 0; i < TAMANHO; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");
}

// Função de ordenação por seleção (Selection Sort) com exibição passo a passo
void selecao_passo_a_passo(int *v)
{
    int i, j, aux, minimo, pos_minimo;

    printf("\n--- Iniciando o processo de ordenacao (Selection Sort) ---\n");

    for (i = 0; i < TAMANHO - 1; i++)
    {
        minimo = v[i];
        pos_minimo = i;

        printf("\nIteracao %d:\n", i + 1);
        printf("Subvetor a analisar: ");
        for (int k = i; k < TAMANHO; k++)
            printf("%d ", v[k]);
        printf("\n");

        // Encontra o menor valor no subvetor
        for (j = i + 1; j < TAMANHO; j++)
        {
            printf("Comparando %d e %d\n", minimo, v[j]);
            if (minimo > v[j])
            {
                minimo = v[j];
                pos_minimo = j;
                printf("Novo minimo encontrado: %d (posicao %d)\n", minimo, pos_minimo);
            }
        }

        // Realiza a troca, se necessário
        if (pos_minimo != i)
        {
            printf("Trocando %d com %d\n", v[i], v[pos_minimo]);
            aux = v[pos_minimo];
            v[pos_minimo] = v[i];
            v[i] = aux;
        }
        else
        {
            printf("Nenhuma troca necessaria nesta iteracao.\n");
        }

        printf("Vetor apos iteracao %d:\n", i + 1);
        exibirVetor(v);
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

    selecao_passo_a_passo(v);

    printf("\nVetor ordenado final:\n");
    exibirVetor(v);

    printf("\n");
    return 0;

    /*
        O que o código faz:

        1. Percorre o vetor posição a posição (índice i).
        2. Encontra o menor valor no subvetor que vai de i até o final.
        3. Troca o menor elemento encontrado com o da posição i.
        4. Exibe, em cada passo:
            Os elementos sendo comparados;
            O novo mínimo encontrado;
            As trocas realizadas;
            O estado atual do vetor após cada iteração.

        💬 Exemplo de execução

        Entrada:
        5 3 4 1 2

        Saída (resumida):

        Iteracao 1:
        Subvetor a analisar: 5 3 4 1 2
        Comparando 5 e 3
        Novo minimo encontrado: 3 (posicao 1)
        Comparando 3 e 4
        Comparando 3 e 1
        Novo minimo encontrado: 1 (posicao 3)
        Comparando 1 e 2
        Trocando 5 com 1
        Vetor apos iteracao 1:
        1 3 4 5 2

        Iteracao 2:
        Subvetor a analisar: 3 4 5 2
        Comparando 3 e 4
        Comparando 3 e 5
        Comparando 3 e 2
        Novo minimo encontrado: 2 (posicao 4)
        Trocando 3 com 2
        Vetor apos iteracao 2:
        1 2 4 5 3
        ...
    */
}