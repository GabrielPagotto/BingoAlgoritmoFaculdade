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

Rota menu_tela() {
    exibir_cabecalho("MENU");
    exibir_opcao(ROTA_CADASTRAR_PARTICIPANTE, "Cadastrar participante");
    exibir_opcao(ROTA_LISTAR_PARTICIPANTE, "Listar Participantes");
    exibir_opcao(ROTA_CADASTRAR_PREMIO, "Cadastrar prêmios");
    exibir_opcao(ROTA_LISTAR_PREMIOS, "Listar prêmios");
    exibir_opcao(ROTA_CONFIGURACOES, "Configurações" );
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
    
    char *mensagem, *log;
    bool prtcAdicionado = adicionar_participante(prtc);

    if (prtcAdicionado) {
        mensagem = "O participante foi adicionado com sucesso";
    } else {
        mensagem = "Ocorreu um erro ao adicionar o participante";
    }

    mostrar_mensagem(mensagem);
    return ROTA_MENU;
}

Rota listar_participantes_tela() {
    Participante *prtcs;
    int array_size;

    prtcs = pegar_todos_participantes(&array_size);
    exibir_cabecalho("LISTA DE PARTICIPANTES");

    for (int i = 0; i < array_size; i++)
        mostrar_participante(prtcs[i]);

    mostrar_mensagem("Todos os participantes listados");
    return ROTA_MENU;
}

Rota cadastrar_premios_tela() {
    exibir_cabecalho("CADASTRAR PRÊMIO");
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

Rota listar_premios_tela() {
    int array_size;
    Premio *premios;
    premios = pegar_todos_premios(&array_size);
    exibir_cabecalho("LISTA DE PRÊMIOS");

    for (int i = 0; i < array_size; i++)
        mostrar_premio(premios[i]);
        
    mostrar_mensagem("Todos os prêmios listados");
    return ROTA_MENU;
}

Rota configuracoes_tela() { 
    BingoConfiguracao config = pegar_configuracoes_bingo();
    exibir_cabecalho("CONFIGURAÇÕES");
    printf("Intervalo dos números da cartela: %d até %d.\n", config.intervalo_inicio, config.intervalo_final);
    printf("Quantidade de números por catela: %d\n\n", config.numeros_catela);
    

    exibir_opcao(1, "Alterar configurações"); 
    exibir_opcao(2, "Voltar para o menu"); 
    char opc = pegar_opc_selecionada();

    if (opc == 1)
        return ROTA_ALTERAR_CONFIGURACOES;

    return ROTA_MENU;
}

Rota alterar_configuracoes_tela() { 
    BingoConfiguracao config;

    config.intervalo_inicio = pegar_int("Informe o intervalo inicial para os números do bingo: ");
    config.intervalo_final = pegar_int("Informe o intervalo final para os números do bingo: ");

    if (config.intervalo_final <= config.intervalo_inicio) {
        mostrar_mensagem("O intervalo final deve ser maior que o inicial, nenhuma alteração foi realizada");
        return ROTA_MENU;
    }
    
    config.numeros_catela = pegar_int("Qual o número máximo de números sorteados por cartela: ");

    if (config.numeros_catela < 6) {
        mostrar_mensagem("O número de seleções por cartela deve ser maior que 5, nenhuma alteração foi realizada");
        return ROTA_MENU;
    }

    alterar_configuracoes_bingo(config);
    mostrar_mensagem("Alterações realizadas com sucesso.");
    return ROTA_MENU;
}
    
#endif /* telas_h */
s