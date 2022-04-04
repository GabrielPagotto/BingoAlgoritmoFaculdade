#ifndef _MODELOS_H
#define _MODELOS_H

#include <stdio.h>

// Modelo do participante.
struct Participante {
    char nome[16];
    char sobrenome[32];
    char numTelefone[15];
    char numDocumento[15]; 
};

#endif