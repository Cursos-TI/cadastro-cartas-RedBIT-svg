#include <stdio.h>

int main() {
    // ---------------------------------------------------------
    // DECLARAÇÃO DAS VARIÁVEIS PARA A CARTA 1
    // ---------------------------------------------------------
    char estado1;
    char codigo1[4];       // Array de char para guardar até 3 letras/números + o terminador '\0'
    char cidade1[50];      // Array com espaço suficiente para nomes de cidades grandes
    int populacao1;
    float area1;
    float pib1;
    int pontosTuristicos1;

    // ---------------------------------------------------------
    // DECLARAÇÃO DAS VARIÁVEIS PARA A CARTA 2
    // ---------------------------------------------------------
    char estado2;
    char codigo2[4];
    char cidade2[50];
    int populacao2;
    float area2;
    float pib2;
    int pontosTuristicos2;

    // ---------------------------------------------------------
    // ENTRADA DE DADOS: CARTA 1
    // ---------------------------------------------------------
    printf("--- Cadastro da Carta 1 ---\n");
    
    printf("Digite o Estado (uma letra de A a H): ");
    scanf(" %c", &estado1); // O espaço antes do %c ignora quebras de linha anteriores
    
    printf("Digite o Código da Carta (ex: A01): ");
    scanf("%s", codigo1);
    
    printf("Digite o Nome da Cidade: ");
    // O comando " %[^\n]" permite ler nomes com espaço (ex: "São Paulo") até o usuário apertar Enter
    scanf(" %[^\n]", cidade1); 
    
    printf("Digite a População: ");
    scanf("%d", &populacao1);
    
    printf("Digite a Área (em km²): ");
    scanf("%f", &area1);
    
    printf("Digite o PIB (em bilhões de reais): ");
    scanf("%f", &pib1);
    
    printf("Digite o Número de Pontos Turísticos: ");
    scanf("%d", &pontosTuristicos1);

    // ---------------------------------------------------------
    // ENTRADA DE DADOS: CARTA 2
    // ---------------------------------------------------------
    printf("\n--- Cadastro da Carta 2 ---\n");
    
    printf("Digite o Estado (uma letra de A a H): ");
    scanf(" %c", &estado2);
    
    printf("Digite o Código da Carta (ex: B02): ");
    scanf("%s", codigo2);
    
    printf("Digite o Nome da Cidade: ");
    scanf(" %[^\n]", cidade2);
    
    printf("Digite a População: ");
    scanf("%d", &populacao2);
    
    printf("Digite a Área (em km²): ");
    scanf("%f", &area2);
    
    printf("Digite o PIB (em bilhões de reais): ");
    scanf("%f", &pib2);
    
    printf("Digite o Número de Pontos Turísticos: ");
    scanf("%d", &pontosTuristicos2);

    // ---------------------------------------------------------
    // SAÍDA DE DADOS: EXIBIÇÃO DAS CARTAS
    // ---------------------------------------------------------
    printf("\n========================================\n");
    printf("          CARTAS CADASTRADAS\n");
    printf("========================================\n\n");

    // Exibindo a Carta 1
    printf("Carta 1:\n");
    printf("Estado: %c\n", estado1);
    printf("Código: %s\n", codigo1);
    printf("Nome da Cidade: %s\n", cidade1);
    printf("População: %d\n", populacao1);
    printf("Área: %.2f km²\n", area1); // %.2f formata para exibir apenas duas casas decimais
    printf("PIB: %.2f bilhões de reais\n", pib1);
    printf("Número de Pontos Turísticos: %d\n", pontosTuristicos1);

    printf("\n"); // Linha em branco para separar as cartas

    // Exibindo a Carta 2
    printf("Carta 2:\n");
    printf("Estado: %c\n", estado2);
    printf("Código: %s\n", codigo2);
    printf("Nome da Cidade: %s\n", cidade2);
    printf("População: %d\n", populacao2);
    printf("Área: %.2f km²\n", area2);
    printf("PIB: %.2f bilhões de reais\n", pib2);
    printf("Número de Pontos Turísticos: %d\n", pontosTuristicos2);

    return 0;
}