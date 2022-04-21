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

int mostrarMensagem(char *mensagem) {
    printf("\n\n  %s.\n", mensagem); 
    fflush(stdout);   
    return system( "read -n 1 -s -p \"  Pressione qualquer tecla para continuar...\"" );
}

void exibirCabecalho(char *titulo) {
    printf("%s\n\n", titulo);
    fflush(stdout);
}

void exibirOpcao(int opcNum, char *desc) {
    printf("%d. %s\n", opcNum, desc);
    fflush(stdout);   
}

char pegarOpcSelecionada() {
    int sel;
    printf("\n\n  Digite o número para a função desejada: ");
    fflush(stdout);   
    scanf("%d", &sel);
    return sel;
}

void salvarLog(char *log) {
    
}

void mostrarParticipante(struct Participante prtc) {
    printf("Codigo: %d, Nome: %s, Sobrenome: %s, Telefone: %s, Documento: %s\n",
        prtc.codigo,
        prtc.nome,
        prtc.sobrenome,
        prtc.numeroTelefone,
        prtc.numeroDocumento);
    fflush(stdout);
}

char *pegarLinha(char *msg)
{
    char *linha = NULL;
    int i = 0, j = 2, caractere;
    linha = (char*) malloc(sizeof(char));
    if (linha == NULL)
    {
        printf(ERRO_ALOCACAO_MEMORIA);
        exit(EXIT_FAILURE);
    }
    printf("%s", msg);
    fflush(stdout);
    while((caractere = getc(stdin)) && caractere != '\n')
    {
        linha[i] = caractere;
        linha = realloc(linha, j*sizeof(char));
        if (linha == NULL)
        {
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

struct Participante *pegarTodosParticipantes() {
    struct Participante prtc;
    struct Participante *prtcs;
    FILE *arqv;
    arqv = fopen(PARTICIPANTES_ARQV, "rb+");
    PARTICIPANTES_ARRAY_SIZE = 0;
    prtcs = malloc(sizeof prtc);
    if (arqv == NULL)
    {
        return prtcs;
    }
    for (int i = 0; fread(&prtc, sizeof(prtc), 1, arqv); i++)
    {
        prtcs = realloc(prtcs, (i + 2) * sizeof(prtc));
        prtcs[i] = prtc;
        PARTICIPANTES_ARRAY_SIZE = i + 1;
    }
    fclose(arqv);
    return prtcs;
}

bool adicionarParticipante(struct Participante prtc) {
    struct Participante *todsPrtcs;
    todsPrtcs = pegarTodosParticipantes();
    prtc.codigo = 1;
    if (PARTICIPANTES_ARRAY_SIZE > 0)
    {
        for (int i = 0; i < PARTICIPANTES_ARRAY_SIZE; i++)
        {
            if (todsPrtcs[i].codigo >= prtc.codigo)
            {
                prtc.codigo = todsPrtcs[i].codigo + 1;
            }
        }
    }
    FILE *arqv;
    arqv = fopen(PARTICIPANTES_ARQV, "a");
    if (arqv == NULL) 
    {
        return false;
    }
    fwrite(&prtc, sizeof(prtc), 1, arqv);
    if (fwrite != 0)
    {
        fclose(arqv);
        return true;
    } 
    else
    {
        fclose(arqv);
        return false;
    }
}

void mostrarPremio(struct Premio premio) {
    printf("Codigo: %d, Descrição: %s\n",
        premio.codigo,
        premio.desricao);
    fflush(stdout);
}

struct Premio *pegarTodosPremios()
{
    PREMIOS_ARRAY_SIZE = 0;
    struct Premio premio;
    struct Premio *premios;
    FILE *arqv;
    arqv = fopen(PREMIOS_ARQV, "rb+");
    premios = malloc(sizeof premio);
    if (arqv == NULL)
    {
        return premios;
    }
    for (int i = 0; fread(&premio, sizeof(premio), 1, arqv); i++)
    {
        premios = realloc(premios, (i + 2) * sizeof(premio));
        premios[i] = premio;
        PREMIOS_ARRAY_SIZE = i + 1;
    }
    fclose(arqv);
    return premios;
}

bool adicionarPremio(struct Premio premio)
{
    struct Participante *todsPremios;
    todsPremios = pegarTodosPremios();
    premio.codigo = 1;
    if (PREMIOS_ARRAY_SIZE > 0)
    {
        for (int i = 0; i < PREMIOS_ARRAY_SIZE; i++)
        {
            if (todsPremios[i].codigo >= premio.codigo)
            {
                premio.codigo = todsPremios[i].codigo + 1;
            }
        }
    }
    FILE *arqv;
    arqv = fopen(PREMIOS_ARQV, "a");
    if (arqv == NULL) 
    {
        return false;
    }
    fwrite(&premio, sizeof(premio), 1, arqv);
    if (fwrite != 0)
    {
        fclose(arqv);
        return true;
    } 
    else
    {
        fclose(arqv);
        return false;
    }
}

#endif /* utilitarios_h */
