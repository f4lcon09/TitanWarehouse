# TitanWarehouse
Sistema de Gerenciamento de Memória e Estoque em C++
# Titan Warehouse v1.0 🛡️

Sistema de gerenciamento de estoque focado em manipulação direta de memória via Ponteiros.

## 📚 O Grimório (Tabela da Verdade)

Para não esquecer como conectar a Main com as Funções:

| O que a Função Pede (Declaração) | O que a Main Entrega (Chamada) | O que Acontece? |
| :--- | :--- | :--- |
| `void f(int valor)` | `f(500)` ou `f(x)` | **Cópia** (Seguro, não altera original) |
| `void f(int *ptr)` | `f(&x)` | **Ponteiro** (Altera original, jeito C) |
| `void f(int &ref)` | `f(x)` | **Referência** (Altera original, jeito C++) |
| `void f(int *ptr)` | `f(500)` | **ERRO** (Não pode apontar pra literal) |
| `void f(int &ref)` | `f(&x)` | **ERRO** (Tipo errado) |

---
*Desenvolvido durante treinamento intensivo de C++.*