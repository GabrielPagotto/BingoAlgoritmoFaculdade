//
//  constantes.h
//  ProjetoBingo
//

#ifndef constantes_h
#define constantes_h

/* Variáveis globais */ 
#define ERRO_ALOCACAO_MEMORIA "Erro de alocação de memória"
#define GET_STRING_MAX_LENGTH 10000
#define MAX_NUMEROS_POR_CARTELA 1000
#define DEFAULT_SPLIT_CHAR '|'
#define INT_MAX_PLACES 6

/* Pastas que serão necessárias para a execução do sistema */  
#define BINGO_FOLDER "BINGO"
#define DATA_FOLDER_NAME "BINGO/data"
#define DATA_PARTICIPANTES_FOLDER_NAME "BINGO/data/participantes"
#define RESULTADOS_FOLDER_NAME "BINGO/resultados"

/* Locais que serão usados para guardar dados */
#define PARTICIPANTES_ARQV "BINGO/data/participantes.txt"
#define PREMIOS_ARQV "BINGO/data/premios.txt"
#define BINGO_CONFIG_ARQV "BINGO/data/config.txt"

/* Locais que são usados para guardar dados de resultados. */
#define LOGS_ARQV "BINGO/resultados/historico.txt"
#define RESULTS_ARQV "BINGO/resultados/resultado.txt"

/* Constantes sobre o sistema operacional */ 

#define MAC_CLEAR_KEY "clear"
#define WINDOWS_CLEAR_KEY "cls"

/// Usar MAC_CLEAR_KEY para MacOS e WINDOWS_CLEAR_KEY para Windows
#define CLEAR_KEY MAC_CLEAR_KEY

#endif /* constantes_h */
