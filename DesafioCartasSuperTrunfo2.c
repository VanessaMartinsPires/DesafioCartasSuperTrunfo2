#include <stdio.h>
#include <string.h>

#define MAX_NOME 50

typedef struct {
    char nome[MAX_NOME];
    int ataque;
    int defesa;
    int vida;
} Carta;

/* Prototipação das funções de cada desafio */
void desafio1(Carta c1, Carta c2);
void desafio2(Carta c1, Carta c2);
void desafio3(Carta c1, Carta c2);

/* Função para ler uma carta (nome + 3 atributos) */
void lerCarta(Carta *c) {
    printf("Nome da carta: ");
    scanf(" %49[^\n]", c->nome);

    printf("  Ataque  (inteiro): ");
    scanf("%d", &c->ataque);

    printf("  Defesa  (inteiro): ");
    scanf("%d", &c->defesa);

    printf("  Vida    (inteiro): ");
    scanf("%d", &c->vida);
}

int main() {
    Carta cartaJogador, cartaCPU;
    int opcao;

    printf("=== Simulador Super Trunfo 2 ===\n\n");

    /* Leitura das duas cartas (jogador e CPU) */
    printf("Cadastre a carta do Jogador:\n");
    lerCarta(&cartaJogador);
    printf("\nCadastre a carta da CPU:\n");
    lerCarta(&cartaCPU);

    printf("\nEscolha o DESAFIO a executar:\n");
    printf("  1 - Desafio 1: comparar apenas ATAQUE com if/if-else\n");
    printf("  2 - Desafio 2: comparação com múltiplos atributos (if-else if, switch e oper. lógicos)\n");
    printf("  3 - Desafio 3: comparação usando 2 atributos e operador ternário\n");
    printf("Opção: ");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            desafio1(cartaJogador, cartaCPU);
            break;
        case 2:
            desafio2(cartaJogador, cartaCPU);
            break;
        case 3:
            desafio3(cartaJogador, cartaCPU);
            break;
        default:
            printf("Opção inválida. Encerrando.\n");
    }

    return 0;
}


/* -------- DESAFIO 1 --------*/

void desafio1(Carta c1, Carta c2) {
    printf("\n=== DESAFIO 1: COMPARAÇÃO POR ATAQUE ===\n");

    printf("Carta Jogador: %s | Ataque = %d\n", c1.nome, c1.ataque);
    printf("Carta CPU    : %s | Ataque = %d\n\n", c2.nome, c2.ataque);

    if (c1.ataque > c2.ataque) {
        printf("Resultado: Jogador VENCEU! (ATAQUE %d > %d)\n", c1.ataque, c2.ataque);
    }
    else if (c1.ataque < c2.ataque) {
        printf("Resultado: CPU VENCEU! (ATAQUE %d < %d)\n", c1.ataque, c2.ataque);
    }
    else {
        printf("Resultado: EMPATE em ATAQUE (%d == %d)\n", c1.ataque, c2.ataque);
    }
}


/* -------- DESAFIO 2 --------*/

void desafio2(Carta c1, Carta c2) {
    int escolha;
    printf("\n=== DESAFIO 2: COMPARAÇÃO COM MÚLTIPLOS ATRIBUTOS ===\n");
    printf("Opções de comparação:\n");
    printf("  1 - Comparar ATAQUE\n");
    printf("  2 - Comparar DEFESA\n");
    printf("  3 - Comparar VIDA\n");
    printf("Escolha um atributo (1-3): ");
    scanf("%d", &escolha);

    switch (escolha) {
        case 1:
            printf("\n>> Comparando ATAQUE:\n");
            if (c1.ataque > c2.ataque) {
                printf("  Jogador: %d vs CPU: %d  -> Jogador vence por ATAQUE\n",
                       c1.ataque, c2.ataque);
            }
            else if (c1.ataque < c2.ataque) {
                printf("  Jogador: %d vs CPU: %d  -> CPU vence por ATAQUE\n",
                       c1.ataque, c2.ataque);
            }
            else {
                /* Desempate por DEFESA se ATAQUE empatou */
                printf("  Empate em ATAQUE (%d == %d). Verificando DEFESA como desempate...\n",
                       c1.ataque, c2.ataque);
                if (c1.defesa > c2.defesa) {
                    printf("  DEFESA: Jogador %d > CPU %d  -> Jogador vence no desempate\n",
                           c1.defesa, c2.defesa);
                }
                else if (c1.defesa < c2.defesa) {
                    printf("  DEFESA: Jogador %d < CPU %d  -> CPU vence no desempate\n",
                           c1.defesa, c2.defesa);
                }
                else {
                    printf("  DEFESA também empatou (%d == %d). Resultado: EMPATE\n",
                           c1.defesa, c2.defesa);
                }
            }
            break;

        case 2:
            printf("\n>> Comparando DEFESA:\n");
            if (c1.defesa > c2.defesa) {
                printf("  Jogador: %d vs CPU: %d  -> Jogador vence por DEFESA\n",
                       c1.defesa, c2.defesa);
            }
            else if (c1.defesa < c2.defesa) {
                printf("  Jogador: %d vs CPU: %d  -> CPU vence por DEFESA\n",
                       c1.defesa, c2.defesa);
            }
            else {
                /* Desempate por VIDA se DEFESA empatou */
                printf("  Empate em DEFESA (%d == %d). Verificando VIDA como desempate...\n",
                       c1.defesa, c2.defesa);
                if (c1.vida > c2.vida) {
                    printf("  VIDA: Jogador %d > CPU %d  -> Jogador vence no desempate\n",
                           c1.vida, c2.vida);
                }
                else if (c1.vida < c2.vida) {
                    printf("  VIDA: Jogador %d < CPU %d  -> CPU vence no desempate\n",
                           c1.vida, c2.vida);
                }
                else {
                    /* Desempate por ATAQUE se VIDA empatou */
                    printf("  VIDA também empatou (%d == %d). Verificando ATAQUE como segundo desempate...\n",
                           c1.vida, c2.vida);
                    if (c1.ataque > c2.ataque) {
                        printf("  ATAQUE: Jogador %d > CPU %d  -> Jogador vence no desempate secundário\n",
                               c1.ataque, c2.ataque);
                    }
                    else if (c1.ataque < c2.ataque) {
                        printf("  ATAQUE: Jogador %d < CPU %d  -> CPU vence no desempate secundário\n",
                               c1.ataque, c2.ataque);
                    }
                    else {
                        printf("  ATAQUE também empatou (%d == %d). Resultado: EMPATE TOTAL\n",
                               c1.ataque, c2.ataque);
                    }
                }
            }
            break;

        case 3:
            printf("\n>> Comparando VIDA:\n");
            if (c1.vida > c2.vida) {
                printf("  Jogador: %d vs CPU: %d  -> Jogador vence por VIDA\n",
                       c1.vida, c2.vida);
            }
            else if (c1.vida < c2.vida) {
                printf("  Jogador: %d vs CPU: %d  -> CPU vence por VIDA\n",
                       c1.vida, c2.vida);
            }
            else {
                /* Desempate por ATAQUE e DEFESA juntos usando operador lógico */
                printf("  Empate em VIDA (%d == %d). Verificando ATAQUE e DEFESA juntos para desempate...\n",
                       c1.vida, c2.vida);
                if ((c1.ataque > c2.ataque) && (c1.defesa > c2.defesa)) {
                    printf("  ATAQUE: %d > %d E DEFESA: %d > %d  -> Jogador vence no desempate\n",
                           c1.ataque, c2.ataque, c1.defesa, c2.defesa);
                }
                else if ((c1.ataque < c2.ataque) && (c1.defesa < c2.defesa)) {
                    printf("  ATAQUE: %d < %d E DEFESA: %d < %d  -> CPU vence no desempate\n",
                           c1.ataque, c2.ataque, c1.defesa, c2.defesa);
                }
                else {
                    printf("  Não houve um vencedor claro nos critérios combinados. EMPATE\n");
                }
            }
            break;

        default:
            printf("Opção inválida no Desafio 2. Encerrando.\n");
    }
}


/* -------- DESAFIO 3 --------*/
void desafio3(Carta c1, Carta c2) {
    int opcao1, opcao2;
    int resultadoA1, resultadoA2;
    char nomeAtr1[10], nomeAtr2[10];

    printf("\n=== DESAFIO 3: COMPARAÇÃO POR DOIS ATRIBUTOS E OPERADOR TERNÁRIO ===\n");
    printf("Atributos disponíveis:\n");
    printf("  1 - ATAQUE\n");
    printf("  2 - DEFESA\n");
    printf("  3 - VIDA\n");

    /* Seleção do primeiro atributo */
    printf("Escolha o PRIMEIRO atributo (1-3): ");
    scanf("%d", &opcao1);
    /* Seleção do segundo atributo */
    printf("Escolha o SEGUNDO atributo (1-3), diferente do primeiro: ");
    scanf("%d", &opcao2);

    /* Validação simples: se forem iguais ou fora do intervalo, encerra */
    if (opcao1 < 1 || opcao1 > 3 || opcao2 < 1 || opcao2 > 3 || opcao1 == opcao2) {
        printf("Seleção inválida de atributos. Encerrando.\n");
        return;
    }

    /* Identificação e comparação do primeiro atributo com ternário */
    switch (opcao1) {
        case 1:
            strcpy(nomeAtr1, "ATAQUE");
            resultadoA1 = (c1.ataque > c2.ataque) ? 1 :
                          (c1.ataque < c2.ataque) ? -1 : 0;
            break;
        case 2:
            strcpy(nomeAtr1, "DEFESA");
            resultadoA1 = (c1.defesa > c2.defesa) ? 1 :
                          (c1.defesa < c2.defesa) ? -1 : 0;
            break;
        case 3:
            strcpy(nomeAtr1, "VIDA");
            resultadoA1 = (c1.vida > c2.vida) ? 1 :
                          (c1.vida < c2.vida) ? -1 : 0;
            break;
    }

    /* Identificação e comparação do segundo atributo com ternário */
    switch (opcao2) {
        case 1:
            strcpy(nomeAtr2, "ATAQUE");
            resultadoA2 = (c1.ataque > c2.ataque) ? 1 :
                          (c1.ataque < c2.ataque) ? -1 : 0;
            break;
        case 2:
            strcpy(nomeAtr2, "DEFESA");
            resultadoA2 = (c1.defesa > c2.defesa) ? 1 :
                          (c1.defesa < c2.defesa) ? -1 : 0;
            break;
        case 3:
            strcpy(nomeAtr2, "VIDA");
            resultadoA2 = (c1.vida > c2.vida) ? 1 :
                          (c1.vida < c2.vida) ? -1 : 0;
            break;
    }

    /* Exibição dos resultados parciais */
    printf("\nComparação de %s:\n", nomeAtr1);
    if (resultadoA1 == 1)
        printf("  Jogador (%d) > CPU (%d)  -> Jogador vence em %s\n",
               (opcao1==1?c1.ataque:opcao1==2?c1.defesa:c1.vida),
               (opcao1==1?c2.ataque:opcao1==2?c2.defesa:c2.vida),
               nomeAtr1);
    else if (resultadoA1 == -1)
        printf("  Jogador (%d) < CPU (%d)  -> CPU vence em %s\n",
               (opcao1==1?c1.ataque:opcao1==2?c1.defesa:c1.vida),
               (opcao1==1?c2.ataque:opcao1==2?c2.defesa:c2.vida),
               nomeAtr1);
    else
        printf("  Empate em %s (%d == %d)\n",
               nomeAtr1,
               (opcao1==1?c1.ataque:opcao1==2?c1.defesa:c1.vida),
               (opcao1==1?c2.ataque:opcao1==2?c2.defesa:c2.vida));

    printf("\nComparação de %s:\n", nomeAtr2);
    if (resultadoA2 == 1)
        printf("  Jogador (%d) > CPU (%d)  -> Jogador vence em %s\n",
               (opcao2==1?c1.ataque:opcao2==2?c1.defesa:c1.vida),
               (opcao2==1?c2.ataque:opcao2==2?c2.defesa:c2.vida),
               nomeAtr2);
    else if (resultadoA2 == -1)
        printf("  Jogador (%d) < CPU (%d)  -> CPU vence em %s\n",
               (opcao2==1?c1.ataque:opcao2==2?c1.defesa:c1.vida),
               (opcao2==1?c2.ataque:opcao2==2?c2.defesa:c2.vida),
               nomeAtr2);
    else
        printf("  Empate em %s (%d == %d)\n",
               nomeAtr2,
               (opcao2==1?c1.ataque:opcao2==2?c1.defesa:c1.vida),
               (opcao2==1?c2.ataque:opcao2==2?c2.defesa:c2.vida));

    /* Lógica final para determinar o vencedor*/
    printf("\n=== Resultado FINAL do Desafio 3 ===\n");
    if (resultadoA1 == 1 && resultadoA2 == 1) {
        printf("Jogador venceu em ambos atributos (%s e %s). Jogador vence!\n",
               nomeAtr1, nomeAtr2);
    }
    else if (resultadoA1 == -1 && resultadoA2 == -1) {
        printf("CPU venceu em ambos atributos (%s e %s). CPU vence!\n",
               nomeAtr1, nomeAtr2);
    }
    else if ((resultadoA1 == 1 && resultadoA2 == -1) ||
             (resultadoA1 == -1 && resultadoA2 == 1)) {
        /* Cada um venceu em um atributo: desempatar pela soma simples */
        int somaJog = c1.ataque + c1.defesa + c1.vida;
        int somaCPU = c2.ataque + c2.defesa + c2.vida;
        printf("Cada carta venceu em um atributo.\n");
        printf("  Soma geral Jogador = %d | Soma geral CPU = %d\n",
               somaJog, somaCPU);
        if (somaJog > somaCPU)
            printf("  Soma do Jogador maior. Jogador vence no desempate de soma!\n");
        else if (somaJog < somaCPU)
            printf("  Soma da CPU maior. CPU vence no desempate de soma!\n");
        else
            printf("  Soma geral igual. Resultado: EMPATE TOTAL\n");
    }
    else if ((resultadoA1 == 0 && resultadoA2 == 0)) {
        printf("Empate em ambos atributos (%s e %s). Resultado: EMPATE TOTAL\n",
               nomeAtr1, nomeAtr2);
    }
    else {
        /* Casos onde um ou dois empates ocorrem, ou combinação de empate e vitória */
        int contaJog = (resultadoA1 == 1) + (resultadoA2 == 1);
        int contaCPU = (resultadoA1 == -1) + (resultadoA2 == -1);

        if (contaJog > contaCPU) {
            printf("Jogador teve mais vitórias parciais nos atributos. Jogador vence!\n");
        }
        else if (contaCPU > contaJog) {
            printf("CPU teve mais vitórias parciais nos atributos. CPU vence!\n");
        }
        else {
            /* Mesma quantidade de vitórias e empates complementar => empate geral */
            printf("Nenhum jogador teve maioria clara. Resultado: EMPATE\n");
        }
    }
}
