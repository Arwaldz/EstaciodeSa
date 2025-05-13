#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 2 - Comparação das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de comparação de cartas de cidades. 
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Definição das variáveis para armazenar as propriedades das cidades
    // Você pode utilizar o código do primeiro desafio


// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de cadastro de cartas de cidades.

#include <string.h> // Para usar strcspn

int main() {;
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

    
    /*
 * Desafio Super Trunfo - Países (Nível Novato)
 * Sistema de comparação básica de cartas de cidades.
 * Atributos: estado, código, nome, população, área (km2), PIB e pontos turísticos.
 * Regra de vitória: maior valor vence, exceto densidade populacional (menor vence).
 */

#include <stdio.h>
#include <string.h>

#define MAX_STR 100

// Estrutura que representa uma carta de cidade
struct Carta {
    char estado[MAX_STR];
    char codigo[MAX_STR];
    char nome[MAX_STR];
    long populacao;
    double area;
    double pib;
    int pontosTuristicos;
};

// Função para ler dados de uma carta
void cadastrarCarta(struct Carta *c, int indice) {
    printf("\n--- Cadastro da Carta %d ---\n", indice);
    printf("Estado: ");
    // Lê linha inteira, incluindo espaços
    scanf(" ");
    fgets(c->estado, MAX_STR, stdin);
    c->estado[strcspn(c->estado, "\n")] = '\0';

    printf("Código da Carta: ");
    fgets(c->codigo, MAX_STR, stdin);
    c->codigo[strcspn(c->codigo, "\n")] = '\0';

    printf("Nome da Cidade: ");
    fgets(c->nome, MAX_STR, stdin);
    c->nome[strcspn(c->nome, "\n")] = '\0';

    printf("População: ");
    scanf("%ld", &c->populacao);

    printf("Área (km2): ");
    scanf("%lf", &c->area);

    printf("PIB (em bilhões): ");
    scanf("%lf", &c->pib);

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &c->pontosTuristicos);
}

// Função para exibir os dados de uma carta
void mostrarCarta(const struct Carta *c) {
    printf("\nCarta: %s\n", c->codigo);
    printf(" Estado: %s\n", c->estado);
    printf(" Cidade: %s\n", c->nome);
    printf(" População: %ld\n", c->populacao);
    printf(" Área: %.2f km2\n", c->area);
    printf(" PIB: %.2f bilhões\n", c->pib);
    printf(" Pontos Turísticos: %d\n", c->pontosTuristicos);
    double densidade = c->populacao / c->area;
    printf(" Densidade Populacional: %.2f hab/km2\n", densidade);
}

int main() {
    struct Carta c1, c2;

    // Cadastro interactivo das duas cartas
    cadastrarCarta(&c1, 1);
    cadastrarCarta(&c2, 2);

    // Exibe as cartas cadastradas
    printf("\n=== Cartas Cadastradas ===\n");
    mostrarCarta(&c1);
    mostrarCarta(&c2);

    // Defina aqui o atributo de comparação:
    // 1 = População, 2 = Área, 3 = PIB, 4 = Pontos Turísticos, 5 = Densidade
    int atributo = 1;  // Exemplo: comparando População

    double valor1, valor2;
    double dens1 = c1.populacao / c1.area;
    double dens2 = c2.populacao / c2.area;

    // Seleção do valor a comparar
    if (atributo == 1) {
        valor1 = c1.populacao;
        valor2 = c2.populacao;
    } else if (atributo == 2) {
        valor1 = c1.area;
        valor2 = c2.area;
    } else if (atributo == 3) {
        valor1 = c1.pib;
        valor2 = c2.pib;
    } else if (atributo == 4) {
        valor1 = c1.pontosTuristicos;
        valor2 = c2.pontosTuristicos;
    } else if (atributo == 5) {
        valor1 = dens1;
        valor2 = dens2;
    } else {
        printf("Atributo inválido. Encerrando.\n");
        return 1;
    }

    // Comparação e decisão de vencedor
    printf("\n=== Resultado da Comparação ===\n");
    if (atributo == 5) {
        // Menor densidade vence
        if (valor1 < valor2) {
            printf("Carta %s vence (menor densidade: %.2f < %.2f)\n", c1.codigo, valor1, valor2);
        } else if (valor2 < valor1) {
            printf("Carta %s vence (menor densidade: %.2f < %.2f)\n", c2.codigo, valor2, valor1);
        } else {
            printf("Empate! Densidades iguais: %.2f\n", valor1);
        }
    } else {
        // Maior valor vence
        if (valor1 > valor2) {
            printf("Carta %s vence (%.2f > %.2f)\n", c1.codigo, valor1, valor2);
        } else if (valor2 > valor1) {
            printf("Carta %s vence (%.2f > %.2f)\n", c2.codigo, valor2, valor1);
        } else {
            printf("Empate! Valores iguais: %.2f\n", valor1);
        }
    }

    return 0;
}
