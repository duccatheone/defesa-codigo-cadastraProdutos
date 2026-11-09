# 📦 Sistema de Gerenciamento de Estoque — A2-2

Projeto desenvolvido em **linguagem C** para a disciplina de **Algoritmos e Pensamento Computacional** (Prof. Marlon), como parte da atividade **A2-2 — Defesa de Código**.

Esta versão é a evolução do primeiro trabalho. O sistema continua simulando o controle de um estoque, mas agora usa **structs**, **funções** e **arquivos**, e os dados cadastrados são mantidos entre uma execução e outra.

**Grupo:** Eduardo, Marcelo, Marcelo Luz, Hemanuel e Patryck

## 🎯 Objetivo

Integrar os conteúdos estudados após a primeira entrega aos conteúdos anteriores:

- Funções;
- Structs;
- Arquivos;
- Estruturas de decisão;
- Estruturas de repetição;
- Vetores, busca e processamento de dados.

## 🔄 O que mudou em relação ao primeiro trabalho

| Primeiro trabalho | Esta versão |
|---|---|
| 3 vetores separados (`codigos[]`, `quantidades[]`, `precos[]`) | 1 `struct Produto` e 1 vetor de structs (`estoque[]`) |
| Todo o código dentro do `main` | Código dividido em 6 funções |
| Limite de 5 produtos | Limite de 100 produtos (`MAX`) |
| Dados perdidos ao fechar o programa | Dados salvos em `estoque.txt` e recuperados ao abrir |

## ⚙️ Funcionalidades

O sistema possui um menu principal com as seguintes opções:

### 1. Cadastrar Produtos

Permite cadastrar vários produtos de uma vez, informando:

- Código do produto (não pode repetir);
- Quantidade disponível em estoque;
- Preço unitário.

Após o cadastro, os dados são **salvos automaticamente** no arquivo `estoque.txt`.

### 2. Buscar Produto por Código

Realiza uma **busca linear** no vetor de structs. Quando o produto é encontrado, mostra código, quantidade, preço unitário e valor total daquele produto em estoque.

### 3. Exibir Relatório e Estatísticas

Apresenta:

- Total de produtos cadastrados;
- Valor total acumulado no estoque;
- Produto de maior valor unitário.

### 4. Sair

Salva os dados no arquivo e encerra o programa.

## 🧱 Estrutura de dados

O produto é modelado por uma struct:

```c
typedef struct {
    int codigo;
    int quantidade;
    float preco;
} Produto;
```

Os produtos ficam guardados em um vetor de structs: `Produto estoque[MAX];`

## 🧩 Funções do programa

| Função | Parâmetros | Retorno | O que faz |
|---|---|---|---|
| `carregarProdutos` | vetor `estoque` | `int` (total lido) | Lê o arquivo e preenche o vetor |
| `salvarProdutos` | vetor `estoque`, `total` | nenhum | Grava todos os produtos no arquivo |
| `buscarProduto` | vetor `estoque`, `total`, `codigo` | `int` (posição ou `-1`) | Busca linear por código |
| `exibirProduto` | um `Produto` | nenhum | Mostra os dados de um produto |
| `cadastrarProdutos` | vetor `estoque`, `total` | `int` (novo total) | Cadastra novos produtos e salva |
| `exibirRelatorio` | vetor `estoque`, `total` | nenhum | Calcula e mostra as estatísticas |

## 💾 Persistência em arquivo

Os dados são gravados em um **arquivo texto** chamado `estoque.txt`, na pasta onde o programa é executado. Cada linha representa um produto, no formato `codigo quantidade preco`:

```
10 5 3.50
20 2 12.90
```

- **Ao iniciar**, o programa chama `carregarProdutos` e recupera os produtos da execução anterior. Se o arquivo não existir (primeira execução), o estoque começa vazio.
- **Ao cadastrar** e **ao sair**, o programa chama `salvarProdutos`, que regrava o arquivo inteiro.

Para recomeçar do zero, basta apagar o `estoque.txt`.

## 🧠 Conceitos utilizados

- **Estruturas de decisão:** `if`, `else if` e `else` no menu e nas validações;
- **Estruturas de repetição:** `for` para percorrer o vetor e `do-while` para o menu e para a validação de código repetido;
- **Funções:** 6 funções criadas pela equipe, com parâmetros e valor de retorno;
- **Struct e vetor de structs:** modelagem do produto e armazenamento de vários registros;
- **Arquivos:** `fopen`, `fscanf`, `fprintf` e `fclose`;
- **Busca:** busca linear por código;
- **Processamento:** cálculo do valor total do estoque e identificação do produto mais caro.

## ▶️ Como compilar e executar

Com o GCC instalado:

```bash
gcc estoque_a2.c -o estoque
./estoque
```

No Windows, execute `estoque.exe` no lugar de `./estoque`.

## 🧪 Como testar a persistência

1. Execute o programa e cadastre alguns produtos (opção 1);
2. Saia pela opção 4 e confira o arquivo `estoque.txt` criado na pasta;
3. Execute o programa novamente. Ele deve informar quantos produtos foram carregados do arquivo;
4. Use a busca (opção 2) e o relatório (opção 3) para confirmar que os dados foram recuperados.

## 📥 Entradas e 📤 Saídas

**Entradas:** opção do menu, quantidade de produtos a cadastrar, código, quantidade em estoque e preço unitário, além do código a ser buscado.

**Saídas:** mensagens do menu, dados do produto encontrado, relatório com estatísticas e o arquivo `estoque.txt` atualizado.

## 📁 Arquivos do projeto

- `estoque_a2.c` — código-fonte do programa;
- `estoque.txt` — arquivo de dados, gerado automaticamente pelo programa;
- `README.md` — este documento.
