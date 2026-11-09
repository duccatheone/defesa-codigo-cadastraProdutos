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

Os produtos ficam guardados em um vetor
