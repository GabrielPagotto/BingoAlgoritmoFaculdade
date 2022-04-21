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

Rota menuTela() {
    exibirCabecalho("MENU");
    exibirOpcao(ROTA_CADASTRAR_PARTICIPANTE, "Cadastrar participante");
    exibirOpcao(ROTA_LISTAR_PARTICIPANTE, "Listar Participantes");
    exibirOpcao(ROTA_CADASTRAR_PREMIO, "Cadastrar prêmios");
    exibirOpcao(ROTA_LISTAR_PREMIOS, "Listar prêmios");
    exibirOpcao(ROTA_FINALIZAR, "Fechar");
    int proxRota = pegarOpcSelecionada();
    return proxRota;
}

#include "modelos.h"

Rota cadastroParticipanteTela()
{
    struct Participante prtc;
    exibirCabecalho("CADASTRAR PARTICIPANTE");
    pegarLinha("");
    prtc.nome = pegarLinha("Informe o nome do participante: ");
    prtc.sobrenome = pegarLinha("Informe o sobrenome do participante: ");
    prtc.numeroTelefone = pegarLinha("Informe o número de telefone do participante: ");
    prtc.numeroDocumento = pegarLinha("Informe o número de documento do participante: ");
    char *res;
    bool prtcAdicionado = adicionarParticipante(prtc);
    if (prtcAdicionado)
    {
        res = "Participante adicionado com sucesso";
    }
    else
    {
        res = "Ocorreu um erro ao adicionar o participante";
    }
    mostrarMensagem(res);
    return ROTA_MENU;
}

Rota listarParticipantesTela()
{
    exibirCabecalho("LISTA DE PARTICIPANTES");
    struct Participante *prtcs;
    prtcs = pegarTodosParticipantes();
    for (int i = 0; i < PARTICIPANTES_ARRAY_SIZE; i++)
    {
        mostrarParticipante(prtcs[i]);
    }
    mostrarMensagem("Todos os participantes foram listados");
    return ROTA_MENU;
}

Rota cadastrarPremiosTela()
{
    exibirCabecalho("LISTA DE PARTICIPANTES");
    struct Premio prm;
    pegarLinha("");
    prm.desricao = pegarLinha("Informe uma descrição para o prêmio: ");
    char *res;
    bool premioAdicionado = adicionarPremio(prm);
    if (premioAdicionado)
    {
        res = "Prêmio adicionado com sucesso";
    }
    else 
    {
        res = "Ocorreu um erro ao adicionar o prêmio";
    }
    mostrarMensagem(res);
    return ROTA_MENU;
}

Rota listarPremiosTela()
{
    exibirCabecalho("LISTA DE PRÊMIOS");
    struct Premio *premios;
    premios = pegarTodosPremios();
    for (int i = 0; i < PREMIOS_ARRAY_SIZE; i++)
    {
        mostrarPremio(premios[i]);
    }
    mostrarMensagem("Todos os prêmios foram listados");
    return ROTA_MENU;
}

#endif /* telas_h */
