# Documentação do Projeto Super Trunfo Avançado

## 1. Visão Geral

Este documento descreve o projeto “Super Trunfo Avançado”, um programa em C que permite comparações de cartas de países usando dois atributos escolhidos pelo usuário. Cada carta contém informações como nome do país, população, área, PIB e número de pontos turísticos. O programa calcula também densidade demográfica e PIB per capita para cada carta e, em seguida, realiza comparações detalhadas para determinar a carta vencedora.

---

## 2. Objetivos

1. **Registrar Dados de Duas Cartas (Países)**  
   - Nome do país  
   - População (unsigned long)  
   - Área (double)  
   - PIB (double)  
   - Número de pontos turísticos (int)

2. **Calcular Campos Derivados**  
   - Densidade Demográfica (população ÷ área)  
   - PIB per Capita (PIB ÷ população)

3. **Permitir a Escolha de Dois Atributos para Comparação**  
   - A interface exibe menus interativos para que o jogador escolha dois atributos diferentes (1 a 6).  
   - Caso o jogador escolha o mesmo atributo duas vezes ou digite uma opção inválida, o programa solicita nova entrada.

4. **Comparar Cartas por Atributo**  
   - Para cada atributo escolhido, determina-se qual carta vence:  
     - Atributos normais (População, Área, PIB, Pontos Turísticos e PIB per Capita): vence quem tiver valor maior.  
     - Densidade Demográfica: vence quem tiver valor menor.

5. **Soma dos Atributos**  
   - Soma-se os dois valores dos atributos escolhidos para cada carta.  
   - A carta com a maior soma vence a rodada; em caso de igualdade, exibe-se “Empate!”.

6. **Exibição de Resultados**  
   - Nome das duas cartas (países).  
   - Nome e valor de cada atributo escolhido para cada carta.  
   - Indicação de qual carta venceu cada atributo (1 ou 0).  
   - Soma dos dois atributos para cada carta.  
   - Anúncio da carta vencedora ou “Empate!”.

---

## 3. Compilação e Execução

1. **Compilação**  
   No terminal, execute:
   ```
   gcc super_trunfo_avancado.c -o super_trunfo_avancado
   ```

2. **Execução**  
   Após compilar, execute:
   ```
   ./super_trunfo_avancado
   ```

---

## 4. Menus de Escolha de Atributos

### Primeiro Atributo
```
Escolha o PRIMEIRO atributo para comparação:
  1 - População
  2 - Área
  3 - PIB
  4 - Pontos Turísticos
  5 - Densidade Demográfica (menor vence)
  6 - PIB per Capita
Opção (1-6):
```

### Segundo Atributo
```
Escolha o SEGUNDO atributo para comparação (diferente do primeiro):
  1 - População
  2 - Área
  3 - PIB
  4 - Pontos Turísticos
  5 - Densidade Demográfica (menor vence)
  6 - PIB per Capita
Opção (1-6):
```

---

## 5. Exemplo de Fluxo

1. Cadastro da Carta 1:
   - Nome do país: Brasil
   - População: 213000000
   - Área: 8516000.0
   - PIB: 1440000000000.0
   - Pontos Turísticos: 100

2. Cadastro da Carta 2:
   - Nome do país: Argentina
   - População: 45000000
   - Área: 2780000.0
   - PIB: 450000000000.0
   - Pontos Turísticos: 80

3. Escolha de Atributos:
   - Primeiro atributo: 3 (PIB)
   - Segundo atributo: 5 (Densidade Demográfica)

4. Resultado:
   ```
   Carta 1: Brasil
   Carta 2: Argentina

   Atributo 1: PIB
     Brasil: 1440000000000.000
     Argentina: 450000000000.000
     -> Brasil venceu (1)

   Atributo 2: Densidade Demográfica
     Brasil: 25.027
     Argentina: 16.187
     -> Argentina venceu (0)

   Soma:
     Brasil: 1440000000025.027
     Argentina: 450000000016.187

   Resultado FINAL: Brasil venceu!
   ```

---

## 6. Estrutura do Código

- `struct Carta`:
  - `nomePais`: string (até 99 caracteres)
  - `populacao`: unsigned long
  - `area`: double
  - `pib`: double
  - `numPontosTuristicos`: int
  - `densidade`: double
  - `pibPerCapita`: double

- Funções:
  1. `calcularDerivados(Carta *c)`: Calcula densidade e PIB per capita.
  2. `obterValorAtributo(const Carta *c, int opcao)`: Retorna valor do atributo em double.
  3. `main()`: Lê dados, exibe menus, realiza comparações e exibe resultados.

---
