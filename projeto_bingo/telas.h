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
    exibir_opcao(ROTA_LISTAR_PARTICIPANTE, "Participantes");
    exibir_opcao(ROTA_LISTAR_PREMIOS, "Prêmios");
    exibir_opcao(ROTA_CONFIGURACOES, "Configurações" );
    
    printf("\n");

    exibir_opcao(ROTA_FINALIZAR, "Fechar");
    int proxRota = pegar_opc_selecionada();
    return proxRota;
}

#include "modelos.h"

Rota cadastro_participante_tela() {
    char str[GET_STRING_MAX_LENGTH];
    pegar_linha("");
    Participante participante_cad;

    bool nome_valido = false;
    bool sobrenome_valido = false; 
    bool numero_telefone_valido = false;
    bool numero_documento_valido = false;

    do {        
        exibir_cabecalho("CADASTRAR PARTICIPANTE");
        char *nome_mensagem = "Informe o nome do participante: ";
        char *sobrenome_mensagem = "Informe o sobrenome do participante: ";
        char *numero_telefone_mensagem = "Informe o número de telefone do participante: ";
        char *numero_documento_mensagem = "Informe o número de documento do participante: ";

        if (!nome_valido) {
            strcpy(str, pegar_linha(nome_mensagem));
        } else { 
            printf("%s", nome_mensagem);
            printf("%s\n", participante_cad.nome);
            strcpy(str, participante_cad.nome);
        }

        nome_valido = strlen(str) > 0 && strlen(str) < 16;
        if (!nome_valido) {
            mostrar_mensagem("O nome do participante precisa ter entre 1 e 16 caracteres");
            system("clear");
            continue;
        }
        
        strcpy(participante_cad.nome, str);

        if (!sobrenome_valido) {
            strcpy(str, pegar_linha(sobrenome_mensagem));
        } else { 
            printf("%s", sobrenome_mensagem);
            printf("%s\n", participante_cad.sobrenome);
            strcpy(str, participante_cad.sobrenome);
        }

        sobrenome_valido = strlen(str) > 0 && strlen(str) < 32;
        if (!sobrenome_valido) {
            mostrar_mensagem("O sobrenome do participante precisa ter entre 1 e 32 caracteres");
            system("clear");
            continue;
        }

        strcpy(participante_cad.sobrenome, str);

        if (!numero_telefone_valido) {
            strcpy(str, pegar_linha(numero_telefone_mensagem));
        } else { 
            printf("%s", numero_telefone_mensagem);
            printf("%s\n", participante_cad.numero_telefone);
            strcpy(str, participante_cad.numero_telefone);
        }

        numero_telefone_valido = strlen(str) == 10 || strlen(str) == 11;
        if (!numero_telefone_valido) {
            mostrar_mensagem("O número de telefone do participante precisa ter 10 ou 11 caracteres");
            system("clear");
            continue;
        }

        strcpy(participante_cad.numero_telefone, str);

        if (!numero_documento_valido) {
            strcpy(str, pegar_linha(numero_documento_mensagem));
        } else { 
            printf("%s", numero_documento_mensagem);
            printf("%s\n", participante_cad.numero_documento);
            strcpy(str, participante_cad.numero_documento);
        } 

        numero_documento_valido = strlen(str) == 11;
        if (!numero_documento_valido) {
            mostrar_mensagem("O número de documento do participante precisa ter 11 caracteres");
            system("clear");
            continue;
        }

        strcpy(participante_cad.numero_documento, str);

    } while (!nome_valido || !sobrenome_valido || !numero_telefone_valido || !numero_documento_valido);
    
    char *log;
    bool prtcAdicionado = adicionar_participante(participante_cad);
    return ROTA_LISTAR_PARTICIPANTE;
}

Rota listar_participantes_tela() {
    Participante *prtcs;
    int array_size;

    prtcs = pegar_todos_participantes(&array_size);
    exibir_cabecalho("PARTICIPANTES");
    
    if (array_size == 0) {
        printf("    Nenhum participante cadastrado.\n");
    } else {
        for (int i = 0; i < array_size; i++)
            mostrar_participante(prtcs[i]);
    }

    printf("\n");
    exibir_opcao(1, "Adicionar participante"); 

    if (array_size > 0)
        exibir_opcao(2, "Cartela participante"); 

    exibir_opcao(3, "Voltar para o menu"); 
    char opc = pegar_opc_selecionada();

    if (opc == 1)
        return ROTA_CADASTRAR_PARTICIPANTE;

    if (opc == 2)
        return ROTA_CARTELA_PARTICIPANTE;

    return ROTA_MENU;
}

Rota cadastrar_premios_tela() {
    char str[GET_STRING_MAX_LENGTH];
    pegar_linha("");
    Premio prm;

    bool descricao_valida = false;

    do {
        exibir_cabecalho("CADASTRAR PRÊMIO");
        char *descricao_mensagem = "Informe uma descrição para o prêmio: ";

        if (!descricao_valida) {
            strcpy(str, pegar_linha(descricao_mensagem));
        } else { 
            printf("%s", descricao_mensagem);
            printf("%s\n", prm.desricao);
            strcpy(str, prm.desricao);
        }
        
        descricao_valida = strlen(str) > 0 && strlen(str) < 16;
        if (!descricao_valida) {
            mostrar_mensagem("A descricao do prêmio precisa ter entre 1 e 16 caracteres");
            system("clear");
            continue;
        }

        strcpy(prm.desricao, str);

    } while (!descricao_valida);

    bool premioAdicionado = adicionar_premio(prm);    
    return ROTA_LISTAR_PREMIOS;
}

Rota listar_premios_tela() {
    int array_size;
    Premio *premios;
    premios = pegar_todos_premios(&array_size);
    exibir_cabecalho("LISTA DE PRÊMIOS");

    if (array_size == 0) { 
        printf("    Nenhum prêmio cadastrado.\n");
    } else { 
        for (int i = 0; i < array_size; i++)
            mostrar_premio(premios[i]);
    }

    printf("\n");
    exibir_opcao(1, "Adicionar prêmio"); 
    exibir_opcao(2, "Voltar para o menu"); 
    char opc = pegar_opc_selecionada();

    if (opc == 1)
        return ROTA_CADASTRAR_PREMIO;

    return ROTA_MENU;
}

Rota configuracoes_tela() { 
    exibir_cabecalho("CONFIGURAÇÕES");
    mostrar_configuracoes_bingo();

    exibir_opcao(1, "Alterar configurações"); 
    exibir_opcao(2, "Voltar para o menu"); 
    char opc = pegar_opc_selecionada();

    if (opc == 1)
        return ROTA_ALTERAR_CONFIGURACOES;

    return ROTA_MENU;
}

Rota alterar_configuracoes_tela() { 
    BingoConfiguracao config;
    exibir_cabecalho("ALTERAR CONFIGURAÇÕES");

    config.intervalo_inicio = pegar_int("Intervalo inicial de números: ");
    config.intervalo_final = pegar_int("Intervalo final de números: ");

    if (config.intervalo_final <= config.intervalo_inicio) {
        mostrar_mensagem("O intervalo final deve ser maior que o inicial, nenhuma alteração foi realizada");
        return ROTA_CONFIGURACOES;
    }
    
    config.numeros_catela = pegar_int("Números por cartela: ");

    if (config.numeros_catela < 6) {
        mostrar_mensagem("O número de seleções por cartela deve ser maior que 5, nenhuma alteração foi realizada");
        return ROTA_CONFIGURACOES;
    }

    alterar_configuracoes_bingo(config);
    return ROTA_CONFIGURACOES;
}

Rota cartela_participante_tela() { 
    Participante *prtcs;
    Participante prtcpt = {0, "", "", "", ""};
    int array_size;

    do { 
        prtcs = pegar_todos_participantes(&array_size);
        exibir_cabecalho("PARTICIPANTES");
        
        for (int i = 0; i < array_size; i++)
            mostrar_participante(prtcs[i]);

        printf("\n");

        int participante_codigo;
        printf("Informe o código do participante que deseja visualizar a cartela: ");
        scanf("%d", &participante_codigo);
        prtcpt = pegar_participante_por_codigo(participante_codigo);

        if (prtcpt.codigo == 0) {
            mostrar_mensagem("Participante com este código não foi encontrado");
            system("clear");
            continue;
        }
    } while (prtcpt.codigo == 0);

    system("clear");
    printf("CARTELA - %s %s\n\n", prtcpt.nome, prtcpt.sobrenome);
    char *cad_title;
    char *opc1_message;

    if (prtcpt.cartela.ativo == 0) { 
        cad_title = "ADICIONAR CARTELA";
        opc1_message = "Adicionar cartela";
        printf("    Participante ainda não possui uma cartela cadastrada.\n\n"); 
    } else { 
        cad_title = "EDITAR CARTELA";
        opc1_message = "Editar cartela";
        mostrar_cartela(prtcpt.cartela);
    }

    exibir_opcao(1, opc1_message); 
    exibir_opcao(2, "Voltar para participantes"); 
    exibir_opcao(3, "Voltar para o menu"); 
    char opc = pegar_opc_selecionada();

    if (opc == 1) {
        BingoConfiguracao config = pegar_configuracoes_bingo();
        int numeros_cartela[config.numeros_catela];

        for (int i = 0; i < config.numeros_catela + 1; i++) {
            system("clear");
            printf("%s - %s %s\n\n", cad_title, prtcpt.nome, prtcpt.sobrenome);
            mostrar_configuracoes_bingo();
            printf("\n");

            printf("CARTELA [ ");
            for (int j = 0; j < sizeof(numeros_cartela) / sizeof(int); j++) {
                if (j < i) { 
                    printf("%d ", numeros_cartela[j]);
                } else {
                    printf("%c ", '_');
                }
            }

            printf("]");

            if (i != config.numeros_catela) {
                printf("\n\nInforme um número: ");
                scanf("%d", &numeros_cartela[i]);

                for (int j = 0; j < i; j++) {
                    if (numeros_cartela[j] == numeros_cartela[i]) {
                        mostrar_mensagem("Este número já está cadastrado na cartela");
                        i--;
                        continue;
                    }

                    if (numeros_cartela[i] < config.intervalo_inicio) {
                        mostrar_mensagem("O número não pode ser menor que o intervalo inicial");
                        i--;
                        continue;
                    }

                    if (numeros_cartela[i] > config.intervalo_final) {
                        mostrar_mensagem("O número não pode ser maior que o intervalo final");
                        i--;
                        continue;
                    }
                }   
            }
        }

        bool salva = salvar_cartela_participante(prtcpt, numeros_cartela);

        if (salva) {
            mostrar_mensagem("Cartela salva com sucesso");
        } else {
            mostrar_mensagem("Ocorreu um erro ao salvar a cartela");
        }

        system("clear");
        return ROTA_LISTAR_PARTICIPANTE;
    } else { 
        system("clear");
        if (opc == 2)
            return ROTA_LISTAR_PARTICIPANTE;
            
        return ROTA_MENU;
    }
}
    
#endif /* telas_h */
