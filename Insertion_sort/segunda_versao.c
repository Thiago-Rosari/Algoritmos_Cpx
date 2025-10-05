#include <stdio.h>
#define TAMANHO 5  // Define o tamanho do vetor

// Função auxiliar para exibir o vetor
void exibirVetor(int *v)
{
    for (int i = 0; i < TAMANHO; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");
}

// Função de ordenação por inserção (Insertion Sort) com exibição passo a passo
void insertion_passo_a_passo(int *v)
{
    int i, j, aux;

    printf("\n--- Iniciando o processo de ordenacao (Insertion Sort) ---\n");

    for (i = 1; i < TAMANHO; i++)
    {
        aux = v[i];
        j = i - 1;

        printf("\nIteracao %d:\n", i);
        printf("Elemento atual: %d\n", aux);

        // Move elementos maiores que 'aux' uma posição à frente
        while (j >= 0 && v[j] > aux)
        {
            printf("Comparando %d > %d -> move %d para a direita\n", v[j], aux, v[j]);
            v[j + 1] = v[j];
            j--;
            exibirVetor(v); // Mostra o vetor a cada movimento
        }

        // Insere o elemento na posição correta
        v[j + 1] = aux;

        printf("Inserindo %d na posicao %d:\n", aux, j + 1);
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

    insertion_passo_a_passo(v);

    printf("\nVetor ordenado final:\n");
    exibirVetor(v);

    printf("\n");
    return 0;
}