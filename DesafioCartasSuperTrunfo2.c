#include <stdio.h>
#include <string.h>

#define MAX_NOME 100

typedef struct {
    char nomePais[MAX_NOME];
    unsigned long populacao;
    double area;
    double pib;
    int numPontosTuristicos;
    double densidade; 
    double pibPerCapita; 
} Carta;

void calcularDerivados(Carta *c) {
    if (c->area > 0.0)
        c->densidade = (double)c->populacao / c->area;
    else
        c->densidade = 0.0; 

    if (c->populacao > 0UL)
        c->pibPerCapita = c->pib / (double)c->populacao;
    else
        c->pibPerCapita = 0.0;
}

double obterValorAtributo(const Carta *c, int opcao) {
    switch (opcao) {
        case 1: return (double)c->populacao;
        case 2: return c->area;
        case 3: return c->pib;
        case 4: return (double)c->numPontosTuristicos;
        case 5: return c->densidade;
        case 6: return c->pibPerCapita;
        default: return 0.0; 
    }
}

int main() {
    Carta carta1, carta2;
    int escolha1 = 0, escolha2 = 0;
    char *nomesAtributos[] = {
        "",                    
        "População",          
        "Área",               
        "PIB",                 
        "Pontos Turísticos",   
        "Densidade Demográfica",
        "PIB per Capita"       
    };
    int valido;

    printf("=== Cadastro da Carta 1 ===\n");
    printf("Nome do país: ");
    scanf(" %99[^\n]", carta1.nomePais);
    printf("População (unsigned long): ");
    scanf("%lu", &carta1.populacao);
    printf("Área (double, em km²): ");
    scanf("%lf", &carta1.area);
    printf("PIB (double): ");
    scanf("%lf", &carta1.pib);
    printf("Número de pontos turísticos (int): ");
    scanf("%d", &carta1.numPontosTuristicos);

    printf("\n=== Cadastro da Carta 2 ===\n");
    printf("Nome do país: ");
    scanf(" %99[^\n]", carta2.nomePais);
    printf("População (unsigned long): ");
    scanf("%lu", &carta2.populacao);
    printf("Área (double, em km²): ");
    scanf("%lf", &carta2.area);
    printf("PIB (double): ");
    scanf("%lf", &carta2.pib);
    printf("Número de pontos turísticos (int): ");
    scanf("%d", &carta2.numPontosTuristicos);

    calcularDerivados(&carta1);
    calcularDerivados(&carta2);

    /* Menu dinâmico: escolha do primeiro atributo */
    do {
        printf("\nEscolha o PRIMEIRO atributo para comparação:\n");
        printf("  1 - População\n");
        printf("  2 - Área\n");
        printf("  3 - PIB\n");
        printf("  4 - Pontos Turísticos\n");
        printf("  5 - Densidade Demográfica (menor vence)\n");
        printf("  6 - PIB per Capita\n");
        printf("Opção (1-6): ");
        scanf("%d", &escolha1);

        valido = (escolha1 >= 1 && escolha1 <= 6);
        if (!valido)
            printf("Opção inválida. Tente novamente.\n");
    } while (!valido);

    /* Menu dinâmico: escolha do segundo atributo (diferente do primeiro) */
    do {
        printf("\nEscolha o SEGUNDO atributo para comparação (diferente de %s):\n",
               nomesAtributos[escolha1]);
        for (int i = 1; i <= 6; i++) {
            if (i == escolha1) continue;
            printf("  %d - %s\n", i, nomesAtributos[i]);
        }
        printf("Opção: ");
        scanf("%d", &escolha2);

        valido = (escolha2 >= 1 && escolha2 <= 6 && escolha2 != escolha1);
        if (!valido)
            printf("Opção inválida ou igual ao primeiro atributo. Tente novamente.\n");
    } while (!valido);

    double valor1_attr1 = obterValorAtributo(&carta1, escolha1);
    double valor2_attr1 = obterValorAtributo(&carta2, escolha1);
    double valor1_attr2 = obterValorAtributo(&carta1, escolha2);
    double valor2_attr2 = obterValorAtributo(&carta2, escolha2);

    int venceu_attr1 = (escolha1 == 5)
                       ? (valor1_attr1 < valor2_attr1 ? 1 : 0)
                       : (valor1_attr1 > valor2_attr1 ? 1 : 0);

    int venceu_attr2 = (escolha2 == 5)
                       ? (valor1_attr2 < valor2_attr2 ? 1 : 0)
                       : (valor1_attr2 > valor2_attr2 ? 1 : 0);

    double soma1 = valor1_attr1 + valor1_attr2;
    double soma2 = valor2_attr1 + valor2_attr2;

    /* Exibição clara do resultado */
    printf("\n=== Resultado da Batalha ===\n\n");
    printf("Carta 1: %s\n", carta1.nomePais);
    printf("Carta 2: %s\n\n", carta2.nomePais);

    printf("Atributo 1: %s\n", nomesAtributos[escolha1]);
    printf("  Valor em %s: %.3f\n", carta1.nomePais, valor1_attr1);
    printf("  Valor em %s: %.3f\n", carta2.nomePais, valor2_attr1);
    printf("  -> ");
    if (venceu_attr1)
        printf("%s venceu este atributo (1)\n\n", carta1.nomePais);
    else
        printf("%s venceu este atributo (0)\n\n", carta2.nomePais);

    printf("Atributo 2: %s\n", nomesAtributos[escolha2]);
    printf("  Valor em %s: %.3f\n", carta1.nomePais, valor1_attr2);
    printf("  Valor em %s: %.3f\n", carta2.nomePais, valor2_attr2);
    printf("  -> ");
    if (venceu_attr2)
        printf("%s venceu este atributo (1)\n\n", carta1.nomePais);
    else
        printf("%s venceu este atributo (0)\n\n", carta2.nomePais);

    printf("Soma dos atributos escolhidos:\n");
    printf("  %s: %.3f\n", carta1.nomePais, soma1);
    printf("  %s: %.3f\n\n", carta2.nomePais, soma2);

    if (soma1 > soma2) {
        printf("Resultado FINAL: %s venceu a rodada!\n", carta1.nomePais);
    }
    else if (soma2 > soma1) {
        printf("Resultado FINAL: %s venceu a rodada!\n", carta2.nomePais);
    }
    else {
        printf("Resultado FINAL: Empate!\n");
    }

    return 0;
}
