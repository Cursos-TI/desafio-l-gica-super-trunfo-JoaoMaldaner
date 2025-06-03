#include <stdio.h>
#include <string.h>
//define o maximo de 10 entradas.
#define MAX 10

//definindo as variaveis das cartas.
typedef struct {
    char estado[50];
    char codigo[20];
    char nomeCidade[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadePopulacional;
} Carta;

//Metodo para calcular a densidade.
void calcularDensidade(Carta *carta) {
    if (carta->area > 0)
        carta->densidadePopulacional = carta->populacao / carta->area;
    else
        carta->densidadePopulacional = 0;
}

//Metodo para cadastrar as cartas a serem jogadas
void cadastrarCartas(Carta cartas[], int *quantidade) {
    printf("Quantas cartas deseja cadastrar (max %d)? ", MAX);
    scanf("%d", quantidade);
    if (*quantidade > MAX) *quantidade = MAX; //quantidade maxima de 10 cartas.


    //Laço for para cadastrar as informações em cada carta
    for (int i = 0; i < *quantidade; i++) {
        printf("\n--- Carta %d ---\n", i + 1);
        printf("Estado: ");
        scanf(" %[^\n]", cartas[i].estado);
        printf("Código da carta: ");
        scanf(" %[^\n]", cartas[i].codigo);
        printf("Nome da cidade: ");
        scanf(" %[^\n]", cartas[i].nomeCidade);
        printf("População: ");
        scanf("%d", &cartas[i].populacao);
        printf("Área (km²): ");
        scanf("%f", &cartas[i].area);
        printf("PIB (em bilhões): ");
        scanf("%f", &cartas[i].pib);
        printf("Número de pontos turísticos: ");
        scanf("%d", &cartas[i].pontosTuristicos);

        calcularDensidade(&cartas[i]);
    }
}

//Exibindo as cartas
void exibirCarta(Carta c) {
    printf("\nCidade: %s (%s)\n", c.nomeCidade, c.estado);
    printf("Código: %s\n", c.codigo);
    printf("População: %d\n", c.populacao);
    printf("Área: %.2f km²\n", c.area);
    printf("PIB: %.2f bilhões\n", c.pib);
    printf("Pontos turísticos: %d\n", c.pontosTuristicos);
    printf("Densidade populacional: %.2f hab/km²\n", c.densidadePopulacional);
}

//Metodo para comparar as cartas
void compararCartas(Carta c1, Carta c2, int criterio) {
    printf("\nComparando cartas:\n");
    exibirCarta(c1);
    exibirCarta(c2);

    float valor1, valor2;
    int menorVence = 0;

    switch (criterio) {
        case 1:
            valor1 = c1.populacao;
            valor2 = c2.populacao;
            break;
        case 2:
            valor1 = c1.area;
            valor2 = c2.area;
            break;
        case 3:
            valor1 = c1.pib;
            valor2 = c2.pib;
            break;
        case 4:
            valor1 = c1.pontosTuristicos;
            valor2 = c2.pontosTuristicos;
            break;
        case 5:
            valor1 = c1.densidadePopulacional;
            valor2 = c2.densidadePopulacional;
            menorVence = 1;
            break;
        default:
            printf("Critério inválido.\n");
            return;
    }

    printf("\nResultado da comparação:\n");
    if ((valor1 > valor2 && !menorVence) || (valor1 < valor2 && menorVence)) {
        printf("Vencedora: %s (%s)\n", c1.nomeCidade, c1.estado);
    } else if ((valor2 > valor1 && !menorVence) || (valor2 < valor1 && menorVence)) {
        printf("Vencedora: %s (%s)\n", c2.nomeCidade, c2.estado);
    } else {
        printf("Empate!\n");
    }
}

int main() {
    Carta cartas[MAX];
    int quantidade = 0;

    cadastrarCartas(cartas, &quantidade);

    int indice1, indice2, criterio;

    printf("\nEscolha dois índices de cartas para comparar (0 a %d):\n", quantidade - 1);
    printf("Índice da primeira carta: ");
    scanf("%d", &indice1);
    printf("Índice da segunda carta: ");
    scanf("%d", &indice2);

    if (indice1 >= quantidade || indice2 >= quantidade || indice1 == indice2) {
        printf("Índices inválidos!\n");
        return 1;
    }
    //Metodo que busca o critério de comparação das cartas.
    printf("\nEscolha o critério de comparação:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos turísticos\n");
    printf("5 - Densidade populacional (menor vence)\n");
    printf("Opção: ");
    scanf("%d", &criterio);

    compararCartas(cartas[indice1], cartas[indice2], criterio);

    return 0;
}
