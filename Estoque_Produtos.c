#include <stdio.h>
#include <stdlib.h>
#define TAM 10

// O sistema deve permitir a inserção, leitura, atualização e exclusão de produtos de um estoque.

typedef struct
{
        int idProduto;
        char nome[50];
        int quantidade;
        double preco;
} Produto;

void Cadastrar(Produto *p)
{
        printf("Digite o código de barras do produto: \n");
        scanf("%d", &p->idProduto);

        printf("Digite o nome do produto: \n");
        scanf("%s[\n]50", p->nome);

        printf("\nDigite a quantidade do produto: \n");
        scanf("%d", &p->quantidade);

        printf("Digite o valor do produto: \n");
        scanf("%lf", &p->preco);
}

void imprimir(Produto p[], int *pos)
{

        printf("\nLista de produtos:\n");

        for (int i = 0; i < *pos; i++)
        {
                printf("Código: %d, Nome do Produto: %s, Quant: %d, Valor do Produto: %.2f\n", p[i].idProduto, p[i].nome, p[i].quantidade, p[i].preco);
        }
}

void excluir(Produto p[], int *pos, int *posExcluir)
{
        for (int i = *posExcluir; i < *pos - 1; i++)
        {
                p[i] = p[i + 1];
        }
        (*pos)--;
        printf("Produto excluido com sucesso\n");
}

void salvarEmArquivo(Produto p[], int *pos)
{
        FILE *arq = fopen("arquivo.txt", "w"); // abri ou cria um arq csv e escreve.

        if (arq)
        {
                for (int i = 0; i < *pos; i++)
                {
                        fprintf(arq, "%s,", p[i].idProduto);
                        fprintf(arq, " %s,", p[i].nome);
                        fprintf(arq, " %d,", p[i].quantidade);
                        fprintf(arq, " %.2f\n", p[i].preco);
                }
                fclose(arq); // fecha o arq.
        }
        else
        {
                printf("ERRO: não é possivel abrir o arquivo.");
        }
}

void lerArquivo(Produto p[], int *pos)
{
        FILE *arq = fopen("arquivo.txt", "r"); // abri ou cria um arq txt e escreve.

        if (arq)
        {
                for (int i = 0; i < *pos; i++)
                {
                        fprintf(arq, "%s,", p[i].idProduto);
                        fprintf(arq, " %s,", p[i].nome);
                        fprintf(arq, " %d,", p[i].quantidade);
                        fprintf(arq, " %.2f\n", p[i].preco);
                }
                fclose(arq); // fecha o arq.
        }
        else
        {
                printf("ERRO: não é possivel abrir o arquivo.");
        }
}

int main()
{
        Produto p[TAM];
        int pos = 0, opc, aux;

        do
        {
                printf("\nDigite (-1) para sair\n");
                printf("1 - Cadastro de Produto\n");
                printf("2 - Listagem de Produto\n");
                printf("3 - Atualizar/Excluir Produto\n");
                printf("4 - Salvar em arquivo .csv\n");
                printf("5 - Ler o arquivo de produtos\n");

                printf("Informe a opção desejada:\n");
                scanf("%d", &opc);

                switch (opc)
                {
                case 1:

                        if (pos < 10)
                        {
                                Cadastrar(&p[pos]);
                                pos++;
                        }
                        else
                        {
                                printf("O arquivo esta cheio\n");
                        }
                        break;

                case 2:

                        if (pos != 0)
                        {

                                imprimir(p, &pos);
                        }
                        else
                        {
                                printf("O arquivo esta cheio\n");
                        }
                        break;

                case 3:

                        if (pos != 0)
                        {

                                printf("Qual item deseja excluir ? ");
                                scanf("%d", &aux);

                                if (aux < pos)
                                {

                                        excluir(p, &pos, &aux);
                                }
                                else
                                {
                                        printf("indice invalido\n");
                                }
                        }
                        else
                        {
                                printf("O estacionamento esta vazio\n");
                        }
                        break;

                case 4:
                        salvarEmArquivo(p, &pos);
                        break;

                case 5:
                        lerArquivo(p, &pos);
                        break;
                }
        } while (opc != -1);
}
