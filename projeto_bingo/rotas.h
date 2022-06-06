//
//  rotas.h
//  ProjetoBingo
//

#ifndef rotas_h
#define rotas_h

#include <stdio.h>

typedef enum {
    ROTA_MENU = 0,
    ROTA_LISTAR_PARTICIPANTE = 1,
    ROTA_LISTAR_PREMIOS = 2,
    ROTA_CONFIGURACOES = 3,
    ROTA_BINGO = 4,
    ROTA_FINALIZAR = 999,
    ROTA_CARTELA_PARTICIPANTE = 500,
    ROTA_CADASTRAR_PREMIO = 501,
    ROTA_CADASTRAR_PARTICIPANTE = 502,
    ROTA_ALTERAR_CONFIGURACOES = 503
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

    case ROTA_CARTELA_PARTICIPANTE:
        sw = cartela_participante_tela();
        break;

    case ROTA_BINGO:
        sw = rodar_bingo_tela();
        break;
    
    default:
        sw = menu_tela();
        break;
    }
    return sw;
}

#endif /* rotas_h */
