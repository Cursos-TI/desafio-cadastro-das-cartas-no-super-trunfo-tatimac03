#include <stdio.h> // Inclui a biblioteca padrão de entrada e saída, necessária para funções como printf e scanf.

/*
 * DESAFIO SUPER TRUNFO - PAÍSES
 *
 * Objetivo: Criar um jogo de cartas "Super Trunfo" baseado em informações geográficas e econômicas de cidades.
 * O programa permite o cadastro de duas cartas de cidades, calcula atributos derivados e as compara entre si.
 *
 * --- NÍVEIS DE IMPLEMENTAÇÃO ---
 *
 * Nível 1: Cadastro das Cartas
 * - Uma estrutura de dados (`struct`) é utilizada para organizar as informações de cada cidade (estado,
 * código, nome da cidade, população, área, PIB, e pontos turísticos).
 * - O código da cidade segue um padrão (ex: A01, B01).
 *
 * Nível Aventureiro: Cálculos Derivados
 * - Implementação de funções para calcular a densidade populacional (população por área).
 * - Implementação de função para calcular o PIB per capita (PIB total por habitante).
 *
 * Nível Mestre: Atributos Avançados e Comparações Detalhadas
 * - A população é armazenada como `unsigned long int` para acomodar grandes valores.
 * - Um atributo "Super Poder" é calculado para cada carta, somando e ponderando os demais atributos numéricos
 * (população, área, PIB, pontos turísticos, PIB per capita e o inverso da densidade populacional).
 * - As cartas são comparadas atributo por atributo, indicando qual delas possui o maior valor (ou menor, no caso da densidade).
 *
 * --- INSTRUÇÕES PARA A ENTRADA DE DADOS ---
 * 1 - Para números decimais (Área, PIB), use o ponto ('.') como separador decimal.
 * 2 - Para a População, informe apenas números inteiros, sem pontos ou vírgulas.
 * 3 - Se o nome da Cidade ou Estado for composto (ex: "Rio de Janeiro"), use underline '_' para conectar as palavras (ex: Rio_de_Janeiro).
 */

/*
 * @brief Calcula a densidade populacional de uma área.
 * @param populacao População total em número de habitantes.
 * @param area Área em quilômetros quadrados (km²).
 * @return A densidade populacional em habitantes por km² (float).
 */
float calculo_densidade(unsigned long int populacao, float area) {
    return (float)populacao / area;
}

/*
 * @brief Calcula o Produto Interno Bruto (PIB) per capita.
 * @param pib Valor do PIB em milhões (ex: 2.5 para 2.5 milhões).
 * @param populacao População total em número de habitantes.
 * @return O PIB per capita (float). O valor do PIB é convertido de milhões para o valor total antes da divisão.
 */
float calculo_percapita(float pib, unsigned long int populacao) {
    // Converte o PIB de milhões para o valor total antes de dividir pela população.
    return (pib * 1000000) / (float)populacao;
}

/*
 * @brief Calcula o "Super Poder" de uma carta, que é a soma de diversos atributos.
 * O PIB é somado em sua escala de "milhões", como foi inserido na entrada.
 * @param populacao População da cidade.
 * @param area Área da cidade.
 * @param pib PIB da cidade em milhões.
 * @param pontos Quantidade de pontos turísticos.
 * @param densidade Densidade populacional já calculada.
 * @param percapita PIB per capita já calculado.
 * @return O valor total do Super Poder (float).
 */
float calculo_super_poder(unsigned long int populacao, float area, float pib, int pontos, float densidade, float percapita) {
    // Soma de todos os atributos numéricos. O inverso da densidade é usado para ponderar.
    return populacao + area + pib + pontos + percapita + (float)(1.0 / densidade);
}

/*
 * @brief Estrutura que representa uma carta de cidade no jogo Super Trunfo.
 * Contém todos os atributos de uma cidade para o jogo.
 */
struct carta_estrutura {
    char estado[25];    // Nome do estado ao qual a cidade pertence.
    char codigo[4];     // Código único da cidade (ex: A01, B01).
    char cidade[25];    // Nome da cidade.
    unsigned long int populacao; // Número de habitantes da cidade.
    float area;         // Área da cidade em quilômetros quadrados (km²).
    float pib;          // Produto Interno Bruto da cidade em milhões.
    int pontos_turisticos; // Quantidade de pontos turísticos na cidade.
};

int main() {
    // Declaração de duas variáveis do tipo 'struct carta_estrutura' para armazenar os dados das cartas.
    struct carta_estrutura carta_1, carta_2;

    // --- CADASTRO DA PRIMEIRA CARTA ---
    // Exibe as instruções de entrada de dados para o usuário.
    printf(">>>>>Atencao >>>>>\n");
    printf("1 - Use ponto ('.') para separar as casas decimais.\n");
    printf("2 - Na entrada de Populacao informar numero inteiro, sem '.' ou ','.\n");
    printf("3 - Se o nome da Cidade ou Estado for composto usar '_' para fazer a conexao. ex: Sao_Paulo.\n\n");

    printf("Cadastro da Primeira Carta:\n\n");

    printf("Estado: ");
    // %s lê uma string (sequência de caracteres sem espaços). O espaço antes de %s consome qualquer whitespace anterior.
    scanf(" %s", carta_1.estado);

    printf("Codigo da Cidade ex ('A01'): ");
    scanf(" %s", carta_1.codigo);

    printf("Cidade: ");
    scanf(" %s", carta_1.cidade);

    printf("Populacao: ");
    // %lu lê um 'unsigned long int'.
    scanf(" %lu", &carta_1.populacao);

    printf("Area (em km²): ");
    // %f lê um 'float' (número de ponto flutuante).
    scanf(" %f", &carta_1.area);

    printf("PIB (em milhoes): ");
    scanf(" %f", &carta_1.pib);

    printf("Quantidade de Pontos Turisticos: ");
    // %d lê um 'int' (número inteiro).
    scanf(" %d", &carta_1.pontos_turisticos);

    // --- CADASTRO DA SEGUNDA CARTA ---
    printf("\n\n");

    // Reexibe as instruções de entrada para a segunda carta.
    printf(">>>>>Atencao >>>>>\n");
    printf("1 - Use ponto ('.') para separar as casas decimais.\n");
    printf("2 - Na entrada de Populacao informar numero inteiro, sem '.' ou ','.\n");
    printf("3 - Se o nome da Cidade ou Estado for composto usar '_' para fazer a conexao. ex: Sao_Paulo.\n\n");

    printf("Cadastro da Segunda Carta:\n\n");

    printf("Estado: ");
    scanf(" %s", carta_2.estado);

    printf("Codigo da Cidade (ex: 'B01'): ");
    scanf(" %s", carta_2.codigo);

    printf("Cidade: ");
    scanf(" %s", carta_2.cidade);

    printf("Populacao: ");
    scanf(" %lu", &carta_2.populacao);

    printf("Area (em km²): ");
    scanf(" %f", &carta_2.area);

    printf("PIB (em milhoes): ");
    scanf(" %f", &carta_2.pib);

    printf("Quantidade de Pontos Turisticos: ");
    scanf(" %d", &carta_2.pontos_turisticos);

    /* --- CÁLCULOS DOS ATRIBUTOS DERIVADOS ---
     * Esta seção calcula a densidade populacional, PIB per capita e o Super Poder para cada carta,
     * utilizando as funções auxiliares definidas no início do programa.
     */

    // Cálculos para a Primeira Carta
    float densidade_1 = calculo_densidade(carta_1.populacao, carta_1.area);
    float pib_percapita_1 = calculo_percapita(carta_1.pib, carta_1.populacao);
    float super_poder_1 = calculo_super_poder(carta_1.populacao, carta_1.area, carta_1.pib, carta_1.pontos_turisticos, densidade_1, pib_percapita_1);

    // Cálculos para a Segunda Carta
    float densidade_2 = calculo_densidade(carta_2.populacao, carta_2.area);
    float pib_percapita_2 = calculo_percapita(carta_2.pib, carta_2.populacao);
    float super_poder_2 = calculo_super_poder(carta_2.populacao, carta_2.area, carta_2.pib, carta_2.pontos_turisticos, densidade_2, pib_percapita_2);

    // --- IMPRESSÃO DAS CARTAS CADASTRADAS ---
    // Esta seção exibe todos os detalhes e atributos calculados para ambas as cartas.
    printf("\n");
    printf("------- CARTAS CADASTRADAS -------\n");

    // Impressão dos detalhes da Primeira Carta
    printf(">>>>> Primeira Carta <<<<<\n");
    printf("Estado: %s\n", carta_1.estado);
    printf("Codigo da Cidade: %s\n", carta_1.codigo);
    printf("Cidade: %s\n", carta_1.cidade);
    printf("Populacao: %lu habitantes\n", carta_1.populacao);
    printf("Area: %.2f Km²\n", carta_1.area);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade_1);
    printf("PIB: %.2f milhoes\n", carta_1.pib);
    printf("PIB per capita: %.2f milhoes\n", pib_percapita_1);
    printf("Quantidade de Pontos Turisticos: %d\n", carta_1.pontos_turisticos);
    printf("Super Poder: %.2f\n", super_poder_1);

    // Impressão dos detalhes da Segunda Carta
    printf("\n");
    printf(">>>>> Segunda Carta <<<<<\n");
    printf("Estado: %s\n", carta_2.estado);
    printf("Codigo da Cidade: %s\n", carta_2.codigo);
    printf("Cidade: %s\n", carta_2.cidade);
    printf("Populacao: %lu habitantes\n", carta_2.populacao);
    printf("Area: %.2f Km²\n", carta_2.area);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade_2);
    printf("PIB: %.2f milhoes\n", carta_2.pib);
    printf("PIB per capita: %.2f milhoes\n", pib_percapita_2);
    printf("Quantidade de Pontos Turisticos: %d\n", carta_2.pontos_turisticos);
    printf("Super Poder: %.2f\n", super_poder_2);

    // --- COMPARAÇÕES ENTRE AS CARTAS ---
    // Esta seção compara os atributos das duas cartas e indica qual vence em cada categoria.
    printf("\n\n >>>>>COMPARACOES <<<<<\n");
    // Explica o significado dos resultados '1' e '0' para o usuário.
    printf("O resultado '1', e Verdadeiro / O resultado '0' e Falso.\n\n");

    // Comparações de atributos: A Carta 1 vence se o resultado for 1.
    printf("Populacao: Carta 1 venceu (%d)\n", carta_1.populacao > carta_2.populacao);
    printf("Area: Carta 1 venceu (%d)\n", carta_1.area > carta_2.area);
    printf("PIB: Carta 1 venceu (%d)\n", carta_1.pib > carta_2.pib);
    printf("Pontos Turisticos: Carta 1 venceu (%d)\n", carta_1.pontos_turisticos > carta_2.pontos_turisticos);
    // Para Densidade Populacional, a carta com o MENOR valor é considerada a vencedora.
    printf("Densidade Populacional (o MENOR vence): (%d)\n", densidade_1 < densidade_2);
    printf("PIB per capita: Carta 1 venceu (%d)\n", pib_percapita_1 > pib_percapita_2);
    printf("Super Poder: Carta 1 venceu (%d)\n", super_poder_1 > super_poder_2);

    return 0; // Indica que o programa foi executado com sucesso.
}



    
  
    
 
    
 
   
  



    
    


  
   
   

       

   
