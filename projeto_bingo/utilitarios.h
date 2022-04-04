#ifndef _UTILITARIOS_H
#define _UTILITARIOS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "modelos.h"

#define PARTICIPANTES_FN "Participantes.txt"

// Cabeçalho padrão que será exibido em todas as telas.
void exibirCabecalho(char *titulo) {
	printf("\n#########################   ");
    printf_s(titulo);
    printf("   #########################\n\n");
}

// Método com formato padrão para as opções.
void exibirOpc(char ind, char *desc) {
    printf("    %s. %s\n", &ind, desc);
}

// Pede para o usuário selecionar uma opção onde retornará o valor digitado pelo usuário.
char pegarOpcSelecionada() {
    char sel;
    printf_s("\n       Selecione uma opção: ");
    scanf("%c", &sel);
    return sel;
}

// Método que realizará a adição do participante no arquivo onde serão armazenado os dados.
bool adicionarParticipante(struct Participante *prtc) {
    FILE *arqv;
    arqv = fopen(PARTICIPANTES_FN, "a");

    if (arqv == NULL)
        return false;

    // prtc->codigo = 1;
    fwrite(&prtc, sizeof(struct Participante), 1, arqv);

    if (fwrite != 0) {
        fclose(arqv);
        return false;
    }
    
    fclose(arqv);

    return true;
}

// Método que retornará uma lista de participantes, a partir dos dados já gravados no arquivos de dados.
struct Participante *pegarTodosParticipantes() {
    struct Participante prtc;
    FILE *arqv;
    arqv = fopen(PARTICIPANTES_FN, "r");

    if (arqv == NULL) 
        return false;

    while (fread(&prtc, sizeof(struct Participante), 1, arqv)) {
        printf("Nome: %s\nSobrenome: %s\nNumero Tel: %s\nNumero Doc: %s\n",
            prtc.nome,
            prtc.sobrenome,
            prtc.numTelefone,
            prtc.numDocumento);
    } 
    
    fclose(arqv);

    struct Participante participantes[10];
    return participantes;
}

#endif
