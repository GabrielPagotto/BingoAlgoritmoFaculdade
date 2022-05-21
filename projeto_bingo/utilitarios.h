//
//  utilitarios.h
//  ProjetoBingo
//

#ifndef utilitarios_h
#define utilitarios_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "modelos.h" 
#include "constantes.h"

int mostrar_mensagem(char *mensagem) {
    printf("\n\n  %s.\n", mensagem); 
    fflush(stdout);   
    return system( "read -n 1 -s -p \"  Pressione qualquer tecla para continuar...\"" );
}

void exibir_cabecalho(char *titulo) {
    printf("%s\n\n", titulo);
    fflush(stdout);
}

void exibir_opcao(int num_opc, char *desc) {
    printf("%d. %s\n", num_opc, desc);
    fflush(stdout);   
}

char pegar_opc_selecionada() {
    int sel;
    printf("\n\n  Digite o número para a função desejada: ");
    fflush(stdout);   
    scanf("%d", &sel);
    return sel;
}

void salvar_log(char *log) {
    
}

void mostrar_participante(Participante prtc) {
    printf("Codigo: %d, Nome: %s, Sobrenome: %s, Telefone: %s, Documento: %s\n",
        prtc.codigo,
        prtc.nome,
        prtc.sobrenome,
        prtc.numero_telefone,
        prtc.numero_documento);

    fflush(stdout);
}

char *pegar_linha(char *msg)
{
    char *linha = NULL;
    int i = 0, j = 2, caractere;
    linha = (char*) malloc(sizeof(char));

    if (linha == NULL) {
        printf(ERRO_ALOCACAO_MEMORIA);
        exit(EXIT_FAILURE);
    }

    printf("%s", msg);
    fflush(stdout);

    while((caractere = getc(stdin)) && caractere != '\n') {
        linha[i] = caractere;
        linha = realloc(linha, j * sizeof(char));

        if (linha == NULL) {
            printf(ERRO_ALOCACAO_MEMORIA);
            free(linha);
            exit(EXIT_FAILURE);
        }

        i++;
        j++;
    }

    linha[i] = '\0';
    return linha;
}

Participante *pegar_todos_participantes(int *array_size) {
    Participante *prtcs;
    Participante prtc;
    FILE *arqv;

    prtcs = malloc(sizeof(Participante) * 2);
    arqv = fopen(PARTICIPANTES_ARQV, "r");
    *array_size = 0;

    if (arqv == NULL)
        return prtcs;

    for (int i = 0; fread(&prtc, sizeof(Participante), 1, arqv); i++) {
        int size = i + 1;

        prtcs[i] = prtc;
        prtcs = realloc(prtcs, sizeof(Participante) * (size + 1));
        *array_size = size;
    }

    fclose(arqv);
    return prtcs;
}

bool adicionar_participante(Participante prtc) {
    int array_size;
    Participante *tods_prtcs;
    tods_prtcs = pegar_todos_participantes(&array_size);
    prtc.codigo = 1;

    if (array_size > 0)
        for (int i = 0; i < array_size; i++)
            if (tods_prtcs[i].codigo >= prtc.codigo)
                prtc.codigo = tods_prtcs[i].codigo + 1;

    FILE *arqv;
    arqv = fopen(PARTICIPANTES_ARQV, "a");

    if (arqv == NULL) 
        return false;

    fwrite(&prtc, sizeof(Participante), 1, arqv);

    if (*fwrite != 0) {
        fclose(arqv);
        return true;
    } else {
        fclose(arqv);
        return false;
    }
}

void mostrar_premio(Premio premio) {
    printf("Codigo: %d, Descrição: %s\n",
        premio.codigo,
        premio.desricao);

    fflush(stdout);
}

Premio *pegar_todos_premios(int *array_size) {
    Premio premio;
    Premio *premios;
    FILE *arqv;

    arqv = fopen(PREMIOS_ARQV, "rb+");
    premios = malloc(sizeof(Premio) * 2);
    *array_size = 0;

    if (arqv == NULL)
        return premios;

    for (int i = 0; fread(&premio, sizeof(Premio), 1, arqv); i++) {
        int size = i + 1;

        premios[i] = premio;
        premios = realloc(premios, sizeof(Premio) * (size + 1));
        *array_size = size;
    }
    
    fclose(arqv);
    return premios;
}

bool adicionar_premio(Premio premio) {
    int array_size;
    Premio *tods_premios;
    tods_premios = pegar_todos_premios(&array_size);
    premio.codigo = 1;
    
    if (array_size > 0)
        for (int i = 0; i < array_size; i++)
            if (tods_premios[i].codigo >= premio.codigo)
                premio.codigo = tods_premios[i].codigo + 1;

    FILE *arqv;
    arqv = fopen(PREMIOS_ARQV, "a");

    if (arqv == NULL)
        return false;

    fwrite(&premio, sizeof(premio), 1, arqv);

    if (*fwrite != 0) {
        fclose(arqv);
        return true;
    } else {
        fclose(arqv);
        return false;
    }
}

#endif /* utilitarios_h */
