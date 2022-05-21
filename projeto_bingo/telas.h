//
//  telas.h
//  ProjetoBingo
//

#ifndef telas_h
#define telas_h

#include <stdio.h>
#include <stdbool.h>

#include "rotas.h"
#include "utilitarios.h"
#include "globais.h"

Rota menu_tela() {
    exibir_cabecalho("MENU");
    exibir_opcao(ROTA_CADASTRAR_PARTICIPANTE, "Cadastrar participante");
    exibir_opcao(ROTA_LISTAR_PARTICIPANTE, "Listar Participantes");
    exibir_opcao(ROTA_CADASTRAR_PREMIO, "Cadastrar prêmios");
    exibir_opcao(ROTA_LISTAR_PREMIOS, "Listar prêmios");
    exibir_opcao(ROTA_FINALIZAR, "Fechar");
    int proxRota = pegar_opc_selecionada();
    return proxRota;
}

#include "modelos.h"

Rota cadastro_participante_tela() {
    Participante prtc;
    exibir_cabecalho("CADASTRAR PARTICIPANTE");
    pegar_linha("");

    strcpy(prtc.nome, pegar_linha("Informe o nome do participante: "));
    strcpy(prtc.sobrenome, pegar_linha("Informe o sobrenome do participante: "));
    strcpy(prtc.numero_telefone, pegar_linha("Informe o número de telefone do participante: "));
    strcpy(prtc.numero_documento, pegar_linha("Informe o número de documento do participante: "));
    
    char *res;
    bool prtcAdicionado = adicionar_participante(prtc);

    if (prtcAdicionado) {
        res = "Participante adicionado com sucesso";
    } else {
        res = "Ocorreu um erro ao adicionar o participante";
    }

    mostrar_mensagem(res);
    return ROTA_MENU;
}

Rota listar_participantes_tela()
{
    exibir_cabecalho("LISTA DE PARTICIPANTES");
    Participante *prtcs;
    prtcs = pegar_todos_participantes();

    ssize_t prtcsSize = sizeof(*prtcs);

    printf("%d", (int) sizeof(prtcs));

    for (int i = 0; i < (sizeof(*prtcs) / sizeof(Participante)); i++)
        mostrar_participante(prtcs[i]);

    mostrar_mensagem("Todos os participantes listados");
    return ROTA_MENU;
}

Rota cadastrar_premios_tela()
{
    exibir_cabecalho("LISTA DE PRÊMIOS");
    Premio prm;
    pegar_linha("");
    strcpy(prm.desricao, pegar_linha("Informe uma descrição para o prêmio: "));

    char *res;
    bool premioAdicionado = adicionar_premio(prm);

    if (premioAdicionado) {
        res = "Prêmio adicionado com sucesso";
    } else {
        res = "Ocorreu um erro ao adicionar o prêmio";
    }
    
    mostrar_mensagem(res);
    return ROTA_MENU;
}

Rota listar_premios_tela()
{
    exibir_cabecalho("LISTA DE PRÊMIOS");
    Premio *premios;
    premios = pegar_todos_premios();

    for (int i = 0; i < (sizeof(*premios) / sizeof(Premio)); i++)
        mostrar_premio(premios[i]);
        
    mostrar_mensagem("Todos os prêmios listados");
    return ROTA_MENU;
}

#endif /* telas_h */
