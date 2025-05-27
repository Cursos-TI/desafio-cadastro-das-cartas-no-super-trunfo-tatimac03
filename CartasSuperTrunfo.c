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
/*
NIVEL MESTRE 
-populacao unsigned long int
- super poder (float) - soma de todos os atributos numericos (pop, area, pib, pontos turisticos, pib per capita e o inverso da densidade populacional)
- comparar as cartas por atributos (- estado, codigo e nome
- exibir os resultados das coparacoes ), para cada atributo imprimir a carta que venceu 
*/

// funcao renda 
float calculo_densidade( unsigned long int populacao, float area){
    return populcao / area ;
}

// pib per capita 
float calculo_percapita(float pib, unsigned long int  populacao){
    return (pib * 1000000)/ populacao ; 
}

// super poder 
float calculo_super_poder (unsigned long int populacao, float area, float pib, int pontos, float densidade, float calculo_percapita){
    return populacao + area + (pib * 1000000) + pontos + percapita + (1/calculo_densidade);
}

// 1. criando as cartas 
struct carta_estrutura {
// lembrar que para o codigo vou usar letras maisculas para os estados e numeros para cidade
// comecando com a primeira letra do alfabeto e a sequencia 01 (A01/A02/A03/A04)
// lembra que em c tem um espaco a mais. 
    char estado[25];
    char codigo[4]; 
    char cidade[25];
    unsigned long int populacao ;
    float area;
    float pib; // milhoes 
    int pontos_turisticos;
};

int main() {
    // so registrar duas cartas 

    struct carta_estrutura carta_1, carta_2;
// carta 1
    printf("Cadastro da Primeira Carta:\n");
    printf(">>>>>Atencao: Use ponto ('.') para separar as casas decimais.<<<<<\n")
    printf("Estado: ");
    scanf(" %s", carta_1.estado);
    printf("Código da Cidade ex ('A01'): ");
    scanf(" %s", carta_1.codigo);
    printf("Cidade: ");
    scanf(" %s", carta_1.cidade ); // NAO ESQUECER DE ESPACAR 
    printf("Populacao: ");
    scanf(" %f", &carta_1.populacao);
    printf("Area (em km²): ");
    scanf(" %f", &carta_1.area);
    printf("PIB (em milhoes): ");
    scanf(" %f", &carta_1.pib);
    printf("Quantidade de Pontos Turisticos: ");
    scanf(" %d", &carta_1.pontos_turisticos);

// carta 2
    printf("\n\n");
    printf("Cadastro da Segunda Carta:\n");
    printf(">>>>> Atencao: Use ponto ('.') para separar as casas decimais.<<<<<")
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
    printf("PIB (em milhoes): ");
    scanf(" %f", &carta_2.pib);
    printf("Quantidade de Pontos Turisticos: ");
    scanf(" %d", &carta_2.pontos_turisticos);

/* Comecando desafio aventureiro 
-acrescentar densidade demografica 
- renda per capita 
tendo atencao no calculos e numeros informados, ja que nao tem mecanismo de controle */ 

// calculo carta 1
float densidade_1 = calculo_densidade (carta_1.populacao, carta_1.area);
float pib_percapita_1 = calculo_percapita( carta_1.pib , carta_1.populcao); 
float super_poder_1 = calculo_super_poder (carta_1.populacao, carta_1.area, carta_1.pib, carta_1.pontos_turisticos, densidade_1, pib_percapita_1);

// calculo carta 2
float densidade_2 = calculo_densidade (carta_2.populcao, carta_2.area);
float pib_percapita_2 = calculo_percapita (carta_2.pib , carta_2.populacao);
float super_poder_2 = calculo_super_poder (carta_2.populacao, carta_2.area, carta_2.pib, carta_2.pontos_turisticos, densidade_2, pib_percapita_2); 


// 2. imprimir as cartas
// impressao carta 1
    printf("\n");
    printf("------- CARTAS CADASTRADAS -------\n");
    printf(">>>>> Primeira Carta <<<<<\n");
    printf("Estado: %s\n", carta_1.estado);
    printf("Codigo da Cidade: %s\n", carta_1.codigo);
    printf("Cidade: %s\n", carta_1.cidade);
    printf("Populacao: %lu habitantes\n", carta_1.populacao );
    printf("Area: %.2f Km²\n", carta_1.area);
    printf("Densidade Populacional: %.2f hab/km²", densidade_1);// acrescimo nivel aventureiro 
    printf("PIB: %.2f milhoes\n", carta_1.pib);
    printf("PIB per capita %.2f milhoes; ", pib_percapita_1);
    printf("Quantidade de Pontos Turisticos: %d\n", carta_1.pontos_turisticos); // nivel aventureiro
    printf("Super Poder: %.2f\n", super_poder_1);

    // impressao carta 2
    printf("\n");
    printf(">>>>> Segunda Carta <<<<<\n");
    printf("Estado: %s\n", carta_2.estado);
    printf("Codigo da Cidade: %s\n", carta_2.codigo);
    printf("Cidade: %s\n", carta_2.cidade);
    printf("Populacao: %lu habitantes\n", carta_2.populacao);
    printf("Area: %.2f Km²\n", carta_2.area);
    printf("Densidade Populacional: %.2f hab/km²\n ", densidade_2); // aventureiro
    printf("PIB: %.2f milhoes\n", carta_2.pib);
    printf("PIB per capita: %.2f milhoes\n", pib_percapita_2);// aventureiro
    printf("Quantidade de Pontos Turisticos: %d\n", carta_2.pontos_turisticos);
    printf("Super Poder: %.2f\n", super_poder_2);

    // comparacoes 
    printf("\n\n >>>>>COMPARACOES <<<<<");
    printf("Populacao: Carta 1 venceu (%d)\n", carta_1.populcao > carta_2.populacao);
    printf("Area: Carta 1 venceu (%d)\n", carta_1.area > carta_2.area);
    printf("PIB: Carta 1 venceu (%d)\n", carta_1.pib > carta_2.pib);
    printf("Pontos Turisticos: Carta 1 venceu (%d)\n", carta_1.pontos_turisticos > carta_2.pontos_turisticos);
    printf("Densidade Populacional (o MENOR vence): (%d)\n", densidade_1 < densidade_2);
    printf("PIB per capita: Carta 1 venceu (%d)\n", pib_percapita_1 > pib_percapita_2);
    printf("Super Poder: Carta 1 venceu (%d)\n", super_poder_1 > super_poder_2);


       

    return 0;
}

