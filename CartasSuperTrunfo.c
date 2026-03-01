#include <stdio.h>
#include <string.h>

int main() {
    // ====================================================================
    // 1. DADOS PRÉ-CADASTRADOS (SIMPLIFICAÇÃO DO NÍVEL)
    // ====================================================================
    char pais1[] = "Brasil";
    float pop1 = 214.3;      // Em milhões para facilitar a visualização e soma
    float area1 = 8515.7;    // Em milhares de km²
    float pib1 = 1.9;        // Em trilhões
    float pt1 = 85.0;        // Pontos turísticos
    float dens1 = pop1 / (area1 / 1000.0); // População dividida pela área real

    char pais2[] = "França";
    float pop2 = 67.9;       // Em milhões
    float area2 = 551.6;     // Em milhares de km²
    float pib2 = 2.9;        // Em trilhões
    float pt2 = 120.0;       // Pontos turísticos
    float dens2 = pop2 / (area2 / 1000.0);

    // Variáveis para armazenar as escolhas e valores
    int opcao1, opcao2;
    char nomeAtributo1[30], nomeAtributo2[30];
    float valor1_carta1, valor1_carta2;
    float valor2_carta1, valor2_carta2;
    
    // Flags para sabermos se o atributo escolhido é a Densidade Demográfica (regra invertida)
    int isDensidade1 = 0, isDensidade2 = 0;

    // ====================================================================
    // 2. MENU DINÂMICO - ESCOLHA DO PRIMEIRO ATRIBUTO
    // ====================================================================
    printf("========================================\n");
    printf("      SUPER TRUNFO: DUELO FINAL       \n");
    printf("========================================\n\n");
    
    printf("Escolha o PRIMEIRO atributo para comparar:\n");
    printf("1. Populacao\n");
    printf("2. Area\n");
    printf("3. PIB\n");
    printf("4. Pontos Turisticos\n");
    printf("5. Densidade Demografica (Vence o menor valor)\n");
    printf("Digite sua opcao: ");
    scanf("%d", &opcao1);

    switch (opcao1) {
        case 1: strcpy(nomeAtributo1, "Populacao"); valor1_carta1 = pop1; valor1_carta2 = pop2; break;
        case 2: strcpy(nomeAtributo1, "Area"); valor1_carta1 = area1; valor1_carta2 = area2; break;
        case 3: strcpy(nomeAtributo1, "PIB"); valor1_carta1 = pib1; valor1_carta2 = pib2; break;
        case 4: strcpy(nomeAtributo1, "Pontos Turisticos"); valor1_carta1 = pt1; valor1_carta2 = pt2; break;
        case 5: strcpy(nomeAtributo1, "Densidade Demografica"); valor1_carta1 = dens1; valor1_carta2 = dens2; isDensidade1 = 1; break;
        default: printf("\nErro: Opcao invalida. O jogo sera encerrado.\n"); return 1;
    }

    // ====================================================================
    // 3. MENU DINÂMICO - ESCOLHA DO SEGUNDO ATRIBUTO
    // ====================================================================
    printf("\nEscolha o SEGUNDO atributo para comparar:\n");
    // O menu só exibe as opções que NÃO foram escolhidas na opcao1
    if (opcao1 != 1) printf("1. Populacao\n");
    if (opcao1 != 2) printf("2. Area\n");
    if (opcao1 != 3) printf("3. PIB\n");
    if (opcao1 != 4) printf("4. Pontos Turisticos\n");
    if (opcao1 != 5) printf("5. Densidade Demografica (Vence o menor valor)\n");
    
    printf("Digite sua opcao: ");
    scanf("%d", &opcao2);

    if (opcao1 == opcao2) {
        printf("\nErro: Voce nao pode escolher o mesmo atributo duas vezes. O jogo sera encerrado.\n");
        return 1;
    }

    switch (opcao2) {
        case 1: strcpy(nomeAtributo2, "Populacao"); valor2_carta1 = pop1; valor2_carta2 = pop2; break;
        case 2: strcpy(nomeAtributo2, "Area"); valor2_carta1 = area1; valor2_carta2 = area2; break;
        case 3: strcpy(nomeAtributo2, "PIB"); valor2_carta1 = pib1; valor2_carta2 = pib2; break;
        case 4: strcpy(nomeAtributo2, "Pontos Turisticos"); valor2_carta1 = pt1; valor2_carta2 = pt2; break;
        case 5: strcpy(nomeAtributo2, "Densidade Demografica"); valor2_carta1 = dens1; valor2_carta2 = dens2; isDensidade2 = 1; break;
        default: printf("\nErro: Opcao invalida. O jogo sera encerrado.\n"); return 1;
    }

    // ====================================================================
    // 4. CÁLCULO DA SOMA
    // ====================================================================
    float somaCarta1 = valor1_carta1 + valor2_carta1;
    float somaCarta2 = valor1_carta2 + valor2_carta2;

    // ====================================================================
    // 5. EXIBIÇÃO DOS RESULTADOS E COMPARAÇÕES (USANDO TERNÁRIO)
    // ====================================================================
    printf("\n========================================\n");
    printf("              RESULTADOS\n");
    printf("========================================\n");
    
    printf("Cartas na mesa: %s x %s\n\n", pais1, pais2);

    // Comparação do Atributo 1 usando Operador Ternário
    // Se for densidade (isDensidade1 == 1), vence o menor (<). Senão, vence o maior (>).
    printf("--- Atributo 1: %s ---\n", nomeAtributo1);
    printf("%s: %.2f\n", pais1, valor1_carta1);
    printf("%s: %.2f\n", pais2, valor1_carta2);
    
    // Tratando empate no atributo individual (opcional para polimento, mas boa prática)
    if (valor1_carta1 == valor1_carta2) {
        printf("Vencedor no Atributo 1: Empate!\n\n");
    } else {
        char *vencedorAttr1 = isDensidade1 ? 
                              (valor1_carta1 < valor1_carta2 ? pais1 : pais2) : 
                              (valor1_carta1 > valor1_carta2 ? pais1 : pais2);
        printf("Vencedor no Atributo 1: %s\n\n", vencedorAttr1);
    }

    // Comparação do Atributo 2 usando Operador Ternário
    printf("--- Atributo 2: %s ---\n", nomeAtributo2);
    printf("%s: %.2f\n", pais1, valor2_carta1);
    printf("%s: %.2f\n", pais2, valor2_carta2);
    
    if (valor2_carta1 == valor2_carta2) {
        printf("Vencedor no Atributo 2: Empate!\n\n");
    } else {
        char *vencedorAttr2 = isDensidade2 ? 
                              (valor2_carta1 < valor2_carta2 ? pais1 : pais2) : 
                              (valor2_carta1 > valor2_carta2 ? pais1 : pais2);
        printf("Vencedor no Atributo 2: %s\n\n", vencedorAttr2);
    }

    // ====================================================================
    // 6. VENCEDOR FINAL (SOMA DOS ATRIBUTOS)
    // ====================================================================
    printf("========================================\n");
    printf("           SOMA E VENCEDOR FINAL        \n");
    printf("========================================\n");
    printf("Soma dos atributos (%s): %.2f\n", pais1, somaCarta1);
    printf("Soma dos atributos (%s): %.2f\n", pais2, somaCarta2);

    if (somaCarta1 > somaCarta2) {
        printf("\n>>> VENCEDOR FINAL: %s! <<<\n", pais1);
    } else if (somaCarta2 > somaCarta1) {
        printf("\n>>> VENCEDOR FINAL: %s! <<<\n", pais2);
    } else {
        printf("\n>>> RESULTADO FINAL: Empate! <<<\n");
    }

    return 0;
}