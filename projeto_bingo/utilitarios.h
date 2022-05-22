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
#include <sys/types.h>
#include <sys/stat.h>

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

void divisor() { 
    printf("-----------------------------------------------\n");
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

int pegar_int(char *msg) {
    int resultado;
    printf("%s", msg);
    scanf("%d", &resultado);
    return resultado;
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
    prtc.cartela.codigo = 0;

    if (array_size > 0)
        for (int i = 0; i < array_size; i++)
            if (tods_prtcs[i].codigo >= prtc.codigo)
                prtc.codigo = tods_prtcs[i].codigo + 1;

    FILE *arqv;
    arqv = fopen(PARTICIPANTES_ARQV, "a");

    if (arqv == NULL) 
        return false;

    fwrite(&prtc, sizeof(prtc), 1, arqv);

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

void criar_pastas_necessarias() { 
    mkdir(DATA_FOLDER_NAME, S_IRWXU);
    mkdir(RESULTADOS_FOLDER_NAME, S_IRWXU);
}

bool alterar_configuracoes_bingo(BingoConfiguracao config) { 
    FILE *arqv;
    arqv = fopen(BINGO_CONFIG_ARQV, "w");

    if (arqv == NULL)
        return false;

    fwrite(&config, sizeof(config), 1, arqv);
    
    if (*fwrite != 0) {
        fclose(arqv);
        return true;
    } else {
        fclose(arqv);
        return false;
    }
}

BingoConfiguracao pegar_configuracoes_bingo() {
    BingoConfiguracao config = {1, 60, 6};
    FILE *arqv;
    arqv = fopen(BINGO_CONFIG_ARQV, "rb+");

    if (arqv == NULL) {
        alterar_configuracoes_bingo(config);
        return config;
    }

    fread(&config, sizeof(config), 1, arqv);
    return config;
}

void mostrar_cartela(Cartela cartela) {
    BingoConfiguracao config = pegar_configuracoes_bingo();
    printf("\n\n");

    for (int i = 0; i < config.numeros_catela; i++)
        printf("%d ", cartela.numeros[i]);

    printf("\n\n");
}

void mostrar_configuracoes_bingo() {
    BingoConfiguracao config = pegar_configuracoes_bingo();
    printf("Intervalo dos números da cartela: %d até %d.\n", config.intervalo_inicio, config.intervalo_final);
    printf("Quantidade de números por catela: %d\n\n", config.numeros_catela);
}


Participante pegar_participante_por_codigo(int participante_codigo) {
    int array_size;
    Participante *participantes;
    participantes = pegar_todos_participantes(&array_size);

    for (int i = 0; i < array_size; i++)
        if (participantes[i].codigo == participante_codigo)
            return participantes[i];

    Participante participante_vazio = {0, "", "", "", ""};
    return participante_vazio;
}

bool atualizar_participante(Participante participante) { 
    int array_size;
    Participante *participantes;
    participantes = pegar_todos_participantes(&array_size);

    FILE *arqv;
    arqv = fopen(PARTICIPANTES_ARQV, "w");

    if (arqv == NULL) 
        return false;
    
    fprintf(arqv, "");
    fclose(arqv);
    arqv = fopen(PARTICIPANTES_ARQV, "a");
    
    if (arqv == NULL) 
        return false;

    for (int i = 0; i < array_size; i++) {
        Participante part_update = participantes[i];
        if (participantes[i].codigo == participante.codigo) {
            part_update = participante;
        }

        fwrite(&part_update, sizeof(part_update), 1, arqv);
    }
        
    if (*fwrite != 0) {
        fclose(arqv);
        return true;
    } else {
        fclose(arqv);
        return false;
    }
}

bool salvar_cartela_participante(Participante prt, int *numeros_cartela) {
    BingoConfiguracao config = pegar_configuracoes_bingo();
    int nums[config.numeros_catela];

    for (int i = 0; i < config.numeros_catela; i++)
        nums[i] = numeros_cartela[i];

    Cartela crtl;

    crtl.codigo = 1;
    crtl.numeros = nums;

    prt.cartela = crtl;
    strcpy(prt.nome, "Guilherme");
    return atualizar_participante(prt);
}

#endif /* utilitarios_h */
