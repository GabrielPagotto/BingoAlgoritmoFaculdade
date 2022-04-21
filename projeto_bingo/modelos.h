//
//  modelos.h
//  ProjetoBingo
//

#ifndef modelos_h
#define modelos_h

#include <stdio.h>

struct Participante
{
    int codigo;
    char *nome;
    char *sobrenome;
    char *numeroTelefone;
    char *numeroDocumento;
};

struct Premio
{   
    int codigo;
    char *desricao;   
};

#endif /* modelos_h */
