#ifndef _ROTAS_H
#define _ROTAS_H

#include <stdio.h>

// Rotas existentes no sistema.
// Toda nova rota que for adicionada ao sistema deverá ser gravada neste Struct.
// Ao adicionar a rota no Struct deve ser dados um número valor não existente para a mesma no método [gerarValoresDasRotas].
typedef struct {
    int menu;
    int cadParticipante;
    int listarParticipantes;
    int cadPremios;
    int cadNumeros;
} Rotas;

// Será adicionado valores padrões que não poderam ser auterados posteriormente.
// Cada rota deve possuir um valor único, pois esse valor é usado como identificador nas telas.
// Setar somente número inteiros.
// O valor 999 não pode ser usado, pois o mesmo já usado para finalizar o sistema.
// A rota menu sempre deve ser o número 0, pois está sendo chamada no inicio da aplicação.
const Rotas gerarValoresDasRotas() {
    Rotas rotas;

    rotas.menu = 0;
    rotas.cadParticipante = 1;
    rotas.listarParticipantes = 2;
    rotas.cadPremios = 3;
    rotas.cadNumeros = 4;

    return rotas;
}

#include "telas.h"

// Método que selecionará a rota responsável por selecionar a view que será exibida.
// Toda view deverá retornar um número inteiro, que será o número valor da próxima view a ser exibida.
// Por padrão o primeiro valor de rota será 0.
// A rota padrão será a view inicial, que no caso será o menu.
int getRoute(int proximaRota) {   
    Rotas rotas = gerarValoresDasRotas();

    if (rotas.menu == proximaRota)
        return menuTela(rotas);
    
    if (rotas.cadParticipante == proximaRota)
        return cadParticipanteTela(rotas);

    if (rotas.listarParticipantes)
        return listarParticipantes(rotas);

    return rotas.menu;
}

#endif
