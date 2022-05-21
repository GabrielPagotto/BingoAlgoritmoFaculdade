//
//  rotas.h
//  ProjetoBingo
//

#ifndef rotas_h
#define rotas_h

#include <stdio.h>

typedef enum {
    ROTA_MENU = 0,
    ROTA_CADASTRAR_PARTICIPANTE = 1,
    ROTA_LISTAR_PARTICIPANTE = 2,
    ROTA_CADASTRAR_PREMIO = 3,
    ROTA_LISTAR_PREMIOS = 4,
    ROTA_CONFIGURACOES = 5,
    ROTA_ALTERAR_CONFIGURACOES = 998, 
    ROTA_FINALIZAR = 999
} Rota;

#include "telas.h"

Rota rota_ctl(Rota proxima_rota) {
    Rota sw;

    switch (proxima_rota) {
    case ROTA_MENU:
        sw = menu_tela();
        break;

    case ROTA_CADASTRAR_PARTICIPANTE:
        sw = cadastro_participante_tela();
        break;

    case ROTA_LISTAR_PARTICIPANTE:
        sw = listar_participantes_tela();
        break;

    case ROTA_CADASTRAR_PREMIO:
        sw = cadastrar_premios_tela();
        break;

    case ROTA_LISTAR_PREMIOS:
        sw = listar_premios_tela();
        break;

    case ROTA_CONFIGURACOES:
        sw = configuracoes_tela();
        break;

    case ROTA_ALTERAR_CONFIGURACOES:
        sw = alterar_configuracoes_tela();
        break;
    
    default:
        sw = menu_tela();
        break;
    }
    return sw;
}

#endif /* rotas_h */
