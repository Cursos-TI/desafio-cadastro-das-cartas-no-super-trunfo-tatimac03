#include <stdio.h>
/*
 * DESAFIO SUPER TRUNFO - PAÍSES
 *
 * Objetivo: Criar um jogo Super Trunfo baseado em cartas que representam cidades/estados.
 * Cada carta é identificada por um código único e possui diversos atributos.
 * O jogo permite o cadastro de duas cartas, cálculo de atributos derivados e comparações entre elas.
 *
 * --- NÍVEIS DE IMPLEMENTAÇÃO ---
 *
 * Nível 1: Cadastro das Cartas
 * - Estrutura de dados para armazenar informações de cada cidade (estado, código, nome, população, área, PIB, pontos turísticos).
 * - Códigos da cidade no formato: Primeira letra do estado (maiúscula) + dois dígitos (ex: A01, B01).
 *
 * Nível Aventureiro: Cálculos Derivados
 * - Implementação de funções para calcular a densidade populacional (População / Área).
 * - Implementação de função para calcular o PIB per capita (PIB total / População).
 *
 * Nível Mestre: Atributos Avançados e Comparações Detalhadas
 * - `populacao` definida como `unsigned long int` para suportar grandes números.
 * - Cálculo de um "Super Poder" para cada carta, somando atributos (população, área, PIB, pontos turísticos, PIB per capita e o inverso da densidade populacional).
 * - Comparação detalhada entre as duas cartas para cada atributo, exibindo qual carta venceu.
 */


/*
 *  Calcula a densidade populacional de uma área.
 *  populacao População total em número de habitantes.
 *  area Área em quilômetros quadrados (km²).
 *  A densidade populacional em habitantes por km².
 */
float calculo_densidade( unsigned long int populacao, float area){
    return (float) populacao / area ;
}
/*
 *  Calcula o Produto Interno Bruto (PIB) per capita.
 *  pib Valor do PIB em milhões (ex: 2.5 para 2.5 milhões).
 *  populacao População total em número de habitantes.
 *  O PIB per capita. O valor do PIB é convertido de milhões para o valor total antes da divisão.
 */

float calculo_percapita(float pib, unsigned long int  populacao){
    return (pib * 1000000)/ (float) populacao ; 
}
/*
 * Calcula o "Super Poder" de uma carta, que é a soma de diversos atributos.
 * O PIB é somado em sua escala de "milhões", como inserido na entrada.
 *  populacao População da cidade.
 *  area Área da cidade.
 * pib PIB da cidade em milhões.
 *  pontos Quantidade de pontos turísticos.
 * densidade Densidade populacional já calculada.
 * percapita PIB per capita já calculado.
 * O valor total do Super Poder.
 */

float calculo_super_poder (unsigned long int populacao, float area, float pib, int pontos, float densidade, float percapita){
     // Soma de todos os atributos numéricos, incluindo pib na escala de milhões
    return populacao + area + pib + pontos + percapita +  (float)(1.0 / densidade);
}

/*
 *  Estrutura que representa uma carta de cidade no jogo Super Trunfo.
 */
struct carta_estrutura {
    char estado[25];  // Nome do estado (ex: "Minas_Gerais"). Nomes compostos devem ser digitados com underline.
    char codigo[4];    / // Nome da cidade (ex: "Belo_Horizonte"). Nomes compostos devem ser digitados com underline.
    char cidade[25];    // Nome da cidade (ex: "Belo_Horizonte"). Nomes compostos devem ser digitados com underline.
    unsigned long int populacao ;  // População da cidade (número inteiro grande).
    float area;            // Área da cidade em km² (valor decimal). 
    float pib;            // Produto Interno Bruto da cidade em milhões (valor decimal).
    int pontos_turisticos;   // Quantidade de pontos turísticos (número inteiro).
};

int main() {
// Declaração de duas variáveis do tipo 'struct carta_estrutura' para armazenar as cartas.

    struct carta_estrutura carta_1, carta_2;

     // --- CADASTRO DA PRIMEIRA CARTA ---
     // Instrução importante para o usuário sobre o separador decimal.
    // O sistema de execução pode aceitar ponto '.' 
    
    printf(">>>>>Atencao >>>>>\n");
    printf("1 - Use ponto ('.') para separar as casas decimais.\n");
    printf("2 - Na entrada de Populacao informar numero inteiro, sem '.' ou ','.\n");
    // O ' %s\n' lê a string e consome o '\n' (Enter) do buffer, evitando pulos nas próximas entradas.
    printf("3 - Se o nome da Cidade ou Estado for composto usar  '_'  ex: Sao_Paulo.\n\n");
    printf("Cadastro da Primeira Carta:\n\n");
    printf("Estado: ");
    scanf(" %s", carta_1.estado);
    printf("Codigo da Cidade ex ('A01'): ");
    scanf(" %s", carta_1.codigo);
    printf("Cidade: ");
    scanf(" %s", carta_1.cidade ); 
    printf("Populacao: ");
    scanf(" %lu", &carta_1.populacao);   // %lu é o especificador correto para 'unsigned long int'; '\n' limpa o buffer.
    printf("Area (em km²): ");  
    scanf(" %f", &carta_1.area);  // %f é o especificador para 'float'; '\n' limpa o buffer.
    printf("PIB (em milhoes): ");
    scanf(" %f", &carta_1.pib);  // %f é o especificador para 'float'; '\n' limpa o buffer.
    printf("Quantidade de Pontos Turisticos: ");
    scanf(" %d", &carta_1.pontos_turisticos);   // %d é o especificador para 'int'; '\n' limpa o buffer.


    printf("\n\n");
     // --- CADASTRO DA SEGUNDA CARTA ---
    
    printf(">>>>>Atencao >>>>>\n");
    printf("1 - Use ponto ('.') para separar as casas decimais.\n");
    printf("2 - Na entrada de Populacao informar numero inteiro, sem '.' ou ','.\n");
    printf("3 - Se o nome da Cidade ou Estado for composto usar '_' ex: Sao_Paulo.\n\n");
    printf("Cadastro da Segunda Carta:\n\n");
    printf("Estado: ");
    scanf(" %s", carta_2.estado);
    printf("Codigo da Cidade (ex: 'B01'): ");
    scanf(" %s", carta_2.codigo);
    printf("Cidade: ");
    scanf(" %s", carta_2.cidade ); 
    printf("Populacao: ");
    scanf(" %lu", &carta_2.populacao);
    printf("Area (em km²): ");
    scanf(" %f", &carta_2.area);
    printf("PIB (em milhoes): ");
    scanf(" %f", &carta_2.pib);
    printf("Quantidade de Pontos Turisticos: ");
    scanf(" %d", &carta_2.pontos_turisticos);
 
    /* --- CÁLCULOS DOS ATRIBUTOS  ---
     * Esta seção calcula a densidade populacional, PIB per capita e o Super Poder para cada carta.
     */
// calculo carta 
float densidade_1 = calculo_densidade (carta_1.populacao, carta_1.area);
float pib_percapita_1 = calculo_percapita( carta_1.pib , carta_1.populacao); 
float super_poder_1 = calculo_super_poder (carta_1.populacao, carta_1.area, carta_1.pib, carta_1.pontos_turisticos, densidade_1, pib_percapita_1);

// calculo carta 2
float densidade_2 = calculo_densidade (carta_2.populacao, carta_2.area);
float pib_percapita_2 = calculo_percapita (carta_2.pib , carta_2.populacao);
float super_poder_2 = calculo_super_poder (carta_2.populacao, carta_2.area, carta_2.pib, carta_2.pontos_turisticos, densidade_2, pib_percapita_2); 

 // --- IMPRESSÃO DAS CARTAS CADASTRADAS ---
    // Esta seção exibe todos os detalhes e atributos calculados para ambas as cartas.
 // Impressão dos detalhes da Primeira Carta
    printf("\n");
    printf("------- CARTAS CADASTRADAS -------\n");
    printf(">>>>> Primeira Carta <<<<<\n");
    printf("Estado: %s\n", carta_1.estado);
    printf("Codigo da Cidade: %s\n", carta_1.codigo);
    printf("Cidade: %s\n", carta_1.cidade);
    printf("Populacao: %lu habitantes\n", carta_1.populacao );
    printf("Area: %.2f Km²\n", carta_1.area);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade_1);// acrescimo nivel aventureiro 
    printf("PIB: %.2f milhoes\n", carta_1.pib);
    printf("PIB per capita %.2f milhoes; \n", pib_percapita_1);
    printf("Quantidade de Pontos Turisticos: %d\n", carta_1.pontos_turisticos); // nivel aventureiro
    printf("Super Poder: %.2f\n", super_poder_1);

   // Impressão dos detalhes da Segunda Carta
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

     // --- COMPARAÇÕES ENTRE AS CARTAS ---
    // Esta seção compara os atributos das duas cartas e indica qual vence em cada categoria.
    printf("\n\n >>>>>COMPARACOES <<<<<\n");
    printf("Resultado '1' Verdadeiro / Resultado '0' Falso.\n\n");  // Explicação para o usuário
    // Comparações de atributos: Carta 1 vence se o resultado for 1.
    printf("Populacao: Carta 1 venceu (%d)\n", carta_1.populacao > carta_2.populacao);
    printf("Area: Carta 1 venceu (%d)\n", carta_1.area > carta_2.area);
    printf("PIB: Carta 1 venceu (%d)\n", carta_1.pib > carta_2.pib);
    printf("Pontos Turisticos: Carta 1 venceu (%d)\n", carta_1.pontos_turisticos > carta_2.pontos_turisticos);
    printf("Densidade Populacional (o MENOR vence): (%d)\n", densidade_1 < densidade_2); // Para Densidade Populacional, a carta com o MENOR valor geralmente "vence".
    printf("PIB per capita: Carta 1 venceu (%d)\n", pib_percapita_1 > pib_percapita_2);
    printf("Super Poder: Carta 1 venceu (%d)\n", super_poder_1 > super_poder_2);


       

    return 0; // Indica que o programa foi executado com sucesso.
}




    
    


  
   
   

       

   
