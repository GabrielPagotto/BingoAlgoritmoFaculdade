//
//  modelos.h
//  ProjetoBingo
//

#ifndef modelos_h
#define modelos_h

#include <stdio.h>

typedef struct {
    int codigo;
    char nome[16];
    char sobrenome[32];
    char numero_telefone[11];
    char numero_documento[11];
} Participante;

typedef struct {   
    int codigo;
    char desricao[16];   
} Premio;

#endif /* modelos_h */
