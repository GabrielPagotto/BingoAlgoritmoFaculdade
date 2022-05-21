//
//  modelos.h
//  ProjetoBingo
//

#ifndef modelos_h
#define modelos_h

#include <stdio.h>

struct Participante {
    int codigo;
    char nome[16];
    char sobrenome[32];
    char numero_telefone[11];
    char numero_documento[11];
};

struct Premio {   
    int codigo;
    char desricao[16];   
};

#endif /* modelos_h */
