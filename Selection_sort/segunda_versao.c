#include <stdio.h>
#include <unistd.h>  // Biblioteca para usar a função sleep() (no Windows, use Sleep())
#define TAMANHO 5    // Tamanho do vetor
#define PAUSA 1      // Tempo de pausa em segundos (ajuste como quiser)

// Função para exibir o vetor
void exibirVetor(int *v)
{
    for (int i = 0; i < TAMANHO; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");
}

// Função de ordenação Selection Sort com exibição passo a passo e pausas
void selecao_animada(int *v)
{
    int i, j, aux, minimo, pos_minimo;

    printf("\n--- Iniciando o processo de ordenacao (Selection Sort Animado) ---\n");

    for (i = 0; i < TAMANHO - 1; i++)
    {
        minimo = v[i];
        pos_minimo = i;

        printf("\nIteracao %d:\n", i + 1);
        printf("Subvetor a analisar: ");
        for (int k = i; k < TAMANHO; k++)
            printf("%d ", v[k]);
        printf("\n");
        sleep(PAUSA);

        // Busca o menor valor no subvetor
        for (j = i + 1; j < TAMANHO; j++)
        {
            printf("Comparando %d e %d...\n", minimo, v[j]);
            sleep(PAUSA);

            if (minimo > v[j])
            {
                minimo = v[j];
                pos_minimo = j;
                printf("Novo minimo encontrado: %d (posicao %d)\n", minimo, pos_minimo);
                sleep(PAUSA);
            }
        }

        // Realiza a troca, se necessário
        if (pos_minimo != i)
        {
            printf("Trocando %d com %d...\n", v[i], v[pos_minimo]);
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
        sleep(PAUSA);
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

    selecao_animada(v);

    printf("\nVetor ordenado final:\n");
    exibirVetor(v);

    printf("\n");
    return 0;
}
