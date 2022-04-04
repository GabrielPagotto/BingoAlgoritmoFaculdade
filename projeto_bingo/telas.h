#ifndef _TELAS_H
#define _TELAS_H

#include <stdio.h>

#include "utilitarios.h"
#include "modelos.h"
#include "rotas.h"

// Tela responsável por mostrar as funções disponíveis no sistema.
int menuTela(Rotas rotas) {
    char sel;
    int proxRota = 0;
    
    exibirCabecalho("MENU");
    exibirOpc('0', "Voltar ao menu");
    exibirOpc('1', "Cadastrar participante");
    exibirOpc('2', "Listar Participantes");
    exibirOpc('3', "Cadastrar premios");
    exibirOpc('4', "Cadastrar intervalo de números sorteados");
    sel = pegarOpcSelecionada();
    printf("%d", sel);

    switch (sel) {
        case '0':
            proxRota = rotas.menu;
            break;
        case '1':
            proxRota = rotas.cadParticipante;
            break;
        case '2':
            proxRota = rotas.cadPremios;
            break;
        case '3':
            proxRota = rotas.cadNumeros;
        default:
            break;
    }

    return proxRota;
}

// Tela responsável por realizar o cadastro de um participante.
int cadParticipanteTela(Rotas rotas) {   
    struct Participante prtcpt;

    exibirCabecalho("CADASTRAR PARTICIPANTE");
    printf_s("  Informe abaixo os dados do participante\n");

    printf("    Nome: ");
    scanf(" %[^\n]", prtcpt.nome);


    printf("    Sobrenome: ");
    scanf(" %[^\n]", prtcpt.sobrenome);

    printf("    Num. Telefone: ");
    scanf(" %[^\n]", prtcpt.numTelefone);

    printf("    Num. Documento: ");
    scanf(" %[^\n]", prtcpt.numDocumento);


    adicionarParticipante(&prtcpt);

    return rotas.menu;
}

int listarParticipantes(Rotas rotas) {
    exibirCabecalho("PARTICIPANTES CADASTRADOS");
    char close;

    pegarTodosParticipantes();

    printf("    APERTE ENTER PARA FECHAR: ");
    scanf("%s", &close);
    
    return rotas.menu;
}

#endif
