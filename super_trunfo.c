#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de cadastro de cartas de cidades.
// Siga os comentários para implementar cada parte do desafio.

#include <stdio.h>
#include <string.h> // Para usar strcspn

int main() {
    int codigo, populacao, pontos_turisticos;
    char nome[50];
    float area, pib;
    
    // Cadastro das Cartas:
    printf("Cadastro da Cidade\n"); // Serve como título do programa

    // Código da cidade
    printf("Digite o código da cidade: "); // Primeiro input a ser dado pelo usuário
    scanf("%d", &codigo);
    while (getchar() != '\n'); // Limpa o buffer de entrada, pois o programa estava solicitando mais de um dado a partir da segunda linha

    // Nome da cidade
    printf("Digite o nome da cidade: "); // Segundo input
    scanf(" %[^\n]", nome); // Com o %[^\n] o programa captura a linha inteira, permitindo que o usuário digite o nome de cidades que possuam espaços

    // População da cidade
    printf("Digite a população da cidade: "); //Terceiro input
    scanf("%d", &populacao);
    while (getchar() != '\n'); // Limpa o buffer de entrada conforme comentário acima
    
    // Área da cidade
    printf("Digite a área da cidade (em km²): "); //Quarto input
    scanf("%f", &area);
    while (getchar() != '\n'); // Limpa o buffer de entrada conforme comentário acima

    // PIB da cidade
    printf("Digite o PIB da cidade (em milhões): "); //Quinto input
    scanf("%f", &pib);
    while (getchar() != '\n'); // Limpar o buffer de entrada conforme comentário acima

    // Número de pontos turísticos
    printf("Digite o número de pontos turísticos: "); //Sexto input
    scanf("%d", &pontos_turisticos);
    while (getchar() != '\n'); // Limpar o buffer de entrada conforme comentário acima
    
    // Exibição dos Dados das Cartas:
    printf("\nDados da Cidade Cadastrada:\n");
    printf("Código: %d\n", codigo);
    printf("Nome: %s\n", nome);
    printf("População: %d habitantes\n", populacao);
    printf("Área: %.2f km²\n", area);
    printf("PIB: %.2f milhões\n", pib);
    printf("Pontos Turísticos: %d\n", pontos_turisticos);

    return 0;
}