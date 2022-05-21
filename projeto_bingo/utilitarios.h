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
#include "globais.h"

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

void mostrar_participante(struct Participante prtc) {
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

struct Participante *pegar_todos_participantes() {
    struct Participante prtc;
    struct Participante *prtcs;
    FILE *arqv;
    arqv = fopen(PARTICIPANTES_ARQV, "r");
    prtcs = malloc(sizeof(struct Participante) * 200);

    if (arqv == NULL)
        return prtcs;

    for (int i = 0; fread(&prtcs[i], sizeof(struct Participante), 1, arqv); i++) {
        // mostrarParticipante(prtc);
        // prtcs[i] = prtc;
        // prtcs = realloc(prtcs, sizeof(struct Participante) * i + 2);
    }

    fclose(arqv);
    return prtcs;
}

bool adicionar_participante(struct Participante prtc) {
    struct Participante *tods_prtcs;
    tods_prtcs = pegar_todos_participantes();
    prtc.codigo = 1;

    for (int i = 0; i < sizeof(*tods_prtcs) / sizeof(struct Participante); i++)
        if (tods_prtcs[i].codigo >= prtc.codigo)
            prtc.codigo = tods_prtcs[i].codigo + 1;

    FILE *arqv;
    arqv = fopen(PARTICIPANTES_ARQV, "a");

    if (arqv == NULL) 
        return false;

    fwrite(&prtc, sizeof(struct Participante), 1, arqv);

    if (*fwrite != 0) {
        printf("Certo");
        fclose(arqv);
        return true;
    } else {
        printf("Errado");
        fclose(arqv);
        return false;
    }
}

void mostrar_premio(struct Premio premio) {
    printf("Codigo: %d, Descrição: %s\n",
        premio.codigo,
        premio.desricao);

    fflush(stdout);
}

struct Premio *pegar_todos_premios() {
    struct Premio premio;
    struct Premio *premios;
    FILE *arqv;
    arqv = fopen(PREMIOS_ARQV, "rb+");
    premios = malloc(sizeof premio);

    if (arqv == NULL)
        return premios;

    for (int i = 0; fread(&premio, sizeof(premio), 1, arqv); i++) {
        premios = realloc(premios, (i + 2) * sizeof(premio));
        premios[i] = premio;
    }
    
    fclose(arqv);
    return premios;
}

bool adicionar_premio(struct Premio premio) {
    struct Premio *tods_premios;
    tods_premios = pegar_todos_premios();
    premio.codigo = 1;
    
    for (int i = 0; i < sizeof(*tods_premios) / sizeof(struct Premio); i++)
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
