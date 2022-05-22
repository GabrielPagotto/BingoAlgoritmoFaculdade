//
//  modelos.h
//  ProjetoBingo
//

#ifndef modelos_h
#define modelos_h

#include <stdio.h>

typedef struct {
    int intervalo_inicio;
    int intervalo_final;
    int numeros_catela;
} BingoConfiguracao;

typedef struct {
    int codigo;
    int *numeros;
} Cartela;

typedef struct {
    int codigo;
    char nome[16];
    char sobrenome[32];
    char numero_telefone[12];
    char numero_documento[12];
    Cartela cartela;
} Participante;

typedef struct {   
    int codigo;
    char desricao[16];   
} Premio;

#endif /* modelos_h */
