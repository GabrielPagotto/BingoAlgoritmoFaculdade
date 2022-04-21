//
//  rotas.h
//  ProjetoBingo
//

#ifndef rotas_h
#define rotas_h

#include <stdio.h>

typedef enum
{
    ROTA_MENU = 0,
    ROTA_CADASTRAR_PARTICIPANTE = 1,
    ROTA_LISTAR_PARTICIPANTE = 2,
    ROTA_CADASTRAR_PREMIO = 3,
    ROTA_LISTAR_PREMIOS = 4,
    ROTA_CADASTRAR_NUMERO = 5,
    ROTA_FINALIZAR = 999
} Rota;

#include "telas.h"

Rota rotaCtl(Rota proximaRota)
{
    Rota sw;

    switch (proximaRota)
    {
    case ROTA_MENU:
        sw = menuTela();
        break;

    case ROTA_CADASTRAR_PARTICIPANTE:
        sw = cadastroParticipanteTela();
        break;

    case ROTA_LISTAR_PARTICIPANTE:
        sw = listarParticipantesTela();
        break;

    case ROTA_CADASTRAR_PREMIO:
        sw = cadastrarPremiosTela();
        break;

    case ROTA_LISTAR_PREMIOS:
        sw = listarPremiosTela();
        break;
    
    default:
        sw = menuTela();
        break;
    }
    return sw;
}

#endif /* rotas_h */
