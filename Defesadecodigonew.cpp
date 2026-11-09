#include <stdio.h>

#define MAX 100                 // capacidade maxima do estoque
#define ARQUIVO "estoque.txt"   // arquivo onde os dados ficam salvos

// STRUCT: modela um produto do estoque
typedef struct {
    int codigo;
    int quantidade;
    float preco;
} Produto;

// ---------------------------------------------------------------
// ARQUIVOS
// ---------------------------------------------------------------

// Le os produtos salvos no arquivo e devolve quantos foram lidos.
// Se o arquivo ainda nao existe (primeira execucao), devolve 0.
int carregarProdutos(Produto estoque[]) {
    FILE *arq = fopen(ARQUIVO, "r");
    int total = 0;

    if (arq == NULL) {
        return 0;
    }

    // fscanf devolve 3 quando conseguiu ler os 3 campos de um produto
    while (total < MAX &&
           fscanf(arq, "%d %d %f",
                  &estoque[total].codigo,
                  &estoque[total].quantidade,
                  &estoque[total].preco) == 3) {
        total++;
    }

    fclose(arq);
    return total;
}

// Grava todos os produtos do vetor no arquivo (um produto por linha).
void salvarProdutos(Produto estoque[], int total) {
    FILE *arq = fopen(ARQUIVO, "w");
    int i;

    if (arq == NULL) {
        printf("\nErro: nao foi possivel salvar o arquivo.\n");
        return;
    }

    for (i = 0; i < total; i++) {
        fprintf(arq, "%d %d %.2f\n",
                estoque[i].codigo,
                estoque[i].quantidade,
                estoque[i].preco);
    }

    fclose(arq);
}

// ---------------------------------------------------------------
// BUSCA
// ---------------------------------------------------------------

// Busca linear: devolve a posicao do produto no vetor ou -1 se nao achar.
int buscarProduto(Produto estoque[], int total, int codigo) {
    int i;

    for (i = 0; i < total; i++) {
        if (estoque[i].codigo == codigo) {
            return i;
        }
    }
    return -1;
}

// ---------------------------------------------------------------
// EXIBICAO E CADASTRO
// ---------------------------------------------------------------

void exibirProduto(Produto p) {
    printf("Codigo: %d\n", p.codigo);
    printf("Quantidade: %d unidades\n", p.quantidade);
    printf("Preco Unitario: R$ %.2f\n", p.preco);
    printf("Valor Total em Estoque: R$ %.2f\n", p.quantidade * p.preco);
}

// Cadastra novos produtos e devolve o novo total de produtos.
int cadastrarProdutos(Produto estoque[], int total) {
    int quantidade_cadastro, i;

    if (total == MAX) {
        printf("\nErro: O estoque ja possui %d produtos cadastrados.\n", MAX);
        return total;
    }

    printf("Quantos produtos deseja cadastrar? ");
    scanf("%d", &quantidade_cadastro);

    if (quantidade_cadastro < 1) {
        printf("\nErro: Cadastre pelo menos 1 produto.\n");
    } else if (quantidade_cadastro > MAX - total) {
        printf("\nErro: Voce pode cadastrar no maximo %d produto(s) agora.\n",
               MAX - total);
    } else {
        for (i = 0; i < quantidade_cadastro; i++) {
            int codigo;

            printf("\nProduto %d:\n", total + 1);

            // Repete ate o usuario digitar um codigo que ainda nao existe
            do {
                printf("Digite o codigo (ID numerico): ");
                scanf("%d", &codigo);

                if (buscarProduto(estoque, total, codigo) != -1) {
                    printf("Erro: Esse codigo ja esta cadastrado. Digite outro.\n");
                }
            } while (buscarProduto(estoque, total, codigo) != -1);

            estoque[total].codigo = codigo;

            printf("Digite a quantidade em estoque: ");
            scanf("%d", &estoque[total].quantidade);

            printf("Digite o preco unitario: ");
            scanf("%f", &estoque[total].preco);

            total++;
        }

        salvarProdutos(estoque, total);   // persiste logo apos cadastrar
        printf("\nCadastro concluido e salvo em arquivo!\n");
    }

    return total;
}

// ---------------------------------------------------------------
// PROCESSAMENTO DE DADOS
// ---------------------------------------------------------------

void exibirRelatorio(Produto estoque[], int total) {
    float valor_total_estoque = 0;
    int indice_mais_caro = 0;
    int i;

    for (i = 0; i < total; i++) {
        valor_total_estoque += estoque[i].quantidade * estoque[i].preco;

        if (estoque[i].preco > estoque[indice_mais_caro].preco) {
            indice_mais_caro = i;
        }
    }

    printf("\n--- RELATORIO GERAL E ESTATISTICAS ---\n");
    printf("Total de produtos cadastrados: %d\n", total);
    printf("Valor total acumulado no estoque: R$ %.2f\n", valor_total_estoque);
    printf("Produto de maior valor unitario: Codigo %d (R$ %.2f)\n",
           estoque[indice_mais_caro].codigo,
           estoque[indice_mais_caro].preco);
}

// ---------------------------------------------------------------
// MAIN
// ---------------------------------------------------------------

int main() {
    Produto estoque[MAX];                     // vetor de structs
    int total_produtos = carregarProdutos(estoque);  // recupera execucao anterior
    int opcao;

    if (total_produtos > 0) {
        printf("%d produto(s) carregado(s) do arquivo.\n", total_produtos);
    }

    do {
        printf("\n=== SISTEMA DE GERENCIAMENTO DE ESTOQUE ===\n");
        printf("1. Cadastrar Produtos\n");
        printf("2. Buscar Produto por Codigo\n");
        printf("3. Exibir Relatorio e Estatisticas\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            printf("\n--- Cadastramento de Produtos ---\n");
            total_produtos = cadastrarProdutos(estoque, total_produtos);

        } else if (opcao == 2) {
            if (total_produtos == 0) {
                printf("\nErro: Nenhum produto cadastrado ainda!\n");
            } else {
                int codigo_busca, posicao;

                printf("\n--- Busca de Produto ---\n");
                printf("Digite o codigo do produto procurado: ");
                scanf("%d", &codigo_busca);

                posicao = buscarProduto(estoque, total_produtos, codigo_busca);

                if (posicao != -1) {
                    printf("\n[PRODUTO ENCONTRADO]\n");
                    exibirProduto(estoque[posicao]);
                } else {
                    printf("\nProduto com codigo %d nao foi encontrado.\n",
                           codigo_busca);
                }
            }

        } else if (opcao == 3) {
            if (total_produtos == 0) {
                printf("\nErro: Nenhum produto cadastrado ainda!\n");
            } else {
                exibirRelatorio(estoque, total_produtos);
            }

        } else if (opcao != 4) {
            printf("\nOpcao invalida! Tente novamente.\n");
        }

    } while (opcao != 4);

    salvarProdutos(estoque, total_produtos);  // garante que tudo foi salvo
    printf("\nPrograma encerrado.\n");
    return 0;
}