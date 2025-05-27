#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das Cartas
//  Cada país está dividido em 8 estados
// Cada Estado tem 4 cidades 
// A carta tem que ser identificada por um código
// Criar uma estrutura, pra nao ter que ta repetindo as variaveis porque pode ficar confuso.
/* modelo aula 
carta 1: 
    estado : a
    codigo: a01
    nome : (lembrar de nao usar nome composto)
    populacao: 
    area: km2
    pib:
    numero de pontos turisticos: 
*/
// Nivel aventureiro 
// calculo para densidade e renda per capita 

// funcao renda 
float calculo_densidade(float populacao, float area){
    return populcao / area ;
}

// pib per capita 
float calculo_percapita(float pib, float populacao){
    return pib / populacao ; 
}

// 1. criando as cartas 
struct carta_estrutura {
// lembrar que para o codigo vou usar letras maisculas para os estados e numeros para cidade
// comecando com a primeira letra do alfabeto e a sequencia 01 (A01/A02/A03/A04)
// lembra que em c tem um espaco a mais. 
    char estado[25];
    char codigo[4]; 
    char cidade[25];
    float populacao;
    float area;
    float pib;
    int pontos_turisticos;
};

int main() {
    // so registrar duas cartas 

    struct carta_estrutura carta_1, carta_2;
// carta 1
    printf("Cadastro da Primeira Carta:\n");
    printf(">>>>>Atenção: Use ponto ('.') para separar as casas decimais.<<<<<\n")
    printf("Estado: ");
    scanf(" %s", carta_1.estado);
    printf("Código da Cidade ex ('A01'): ");
    scanf(" %s", carta_1.codigo);
    printf("Cidade: ");
    scanf(" %s", carta_1.cidade ); // NAO ESQUECER DE ESPACAR 
    printf("População: ");
    scanf(" %f", &carta_1.populacao);
    printf("Area (em km²): ");
    scanf(" %f", &carta_1.area);
    printf("PIB (em milhões): ");
    scanf(" %f", &carta_1.pib);
    printf("Quantidade de Pontos Turisticos: ");
    scanf(" %d", &carta_1.pontos_turisticos);

// carta 2
    printf("\n\n");
    printf("Cadastro da Segunda Carta:\n");
    printf(">>>>> Atenção: Use ponto ('.') para separar as casas decimais.<<<<<")
    printf("Estado: ");
    scanf(" %s", carta_2.estado);
    printf("Codigo da Cidade (ex: 'B01'): ");
    scanf(" %s", carta_2.codigo);
    printf("Cidade: ");
    scanf(" %s", carta_2.cidade ); 
    printf("Populacao: ");
    scanf(" %f", &carta_2.populacao);
    printf("Area (em km²): ");
    scanf(" %f", &carta_2.area);
    printf("PIB (em milhões): ");
    scanf(" %f", &carta_2.pib);
    printf("Quantidade de Pontos Turisticos: ");
    scanf(" %d", &carta_2.pontos_turisticos);

/* Comecando desafio aventureiro 
-acrescentar densidade demografica 
- renda per capita 
tendo atencao no calculos e numeros informados, ja que nao tem mecanismo de controle */ 

float densidade_1 = calculo_densidade (carta_1.populacao, carta_1.area);
float pib_percapita_1 = calculo_percapita( carta_1.pib * 1000000, carta_1.populcao); // converte pib para unidade para realizar o calculo correto

float densidade_2 = calculo_densidade (carta_2.populcao, carta_2.area);
float pib_percapita_2 = calculo_percapita (carta_2.pib * 1000000, carta_2.populacao);


// 2. imprimir as cartas
    printf("\n");
    printf("------- CARTAS CADASTRADAS -------\n");
    printf(">>>>> Primeira Carta <<<<<\n");
    printf("Estado: %s\n", carta_1.estado);
    printf("Codigo da Cidade: %s\n", carta_1.codigo);
    printf("Cidade: %s\n", carta_1.cidade);
    printf("Populacao: %.0f habitantes\n", carta_1.populacao );
    printf("Area: %.2f Km²\n", carta_1.area);
    printf("Densidade Populacional: %.2f hab/km²", densidade_1);// acrescimo nivel aventureiro 
    printf("PIB: %.2f\n", carta_1.pib);
    printf("PIB per capita %.2f milhões; ", pib_percapita_1);
    printf("Quantidade de Pontos Turisticos: %d\n", carta_1.pontos_turisticos); // nivel aventureiro
    printf("\n");
    printf(">>>>> Segunda Carta <<<<<\n");
    printf("Estado: %s\n", carta_2.estado);
    printf("Codigo da Cidade: %s\n", carta_2.codigo);
    printf("Cidade: %s\n", carta_2.cidade);
    printf("Populacao: %.0f habitantes\n", carta_2.populacao);
    printf("Area: %.2f Km²\n", carta_2.area);
    printf("Densidade Populacional: %.2f hab/km²\n ", densidade_2); // aventureiro
    printf("PIB: %.2f\n", carta_2.pib);
    printf("PIB per capita: %.2f milhões\n", pib_percapita_2);// aventureiro
    printf("Quantidade de Pontos Turisticos: %d\n", carta_2.pontos_turisticos);

       

    return 0;
}

