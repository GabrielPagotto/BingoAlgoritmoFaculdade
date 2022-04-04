#ifndef _SISTEMA_H
#define _SISTEMA_H

#include <stdio.h>
#include <locale.h>

#include "rotas.h"

// Método responsável por realizar o update na visualização do terminal.
// O método faz referência a ele mesmo sempre que a rota for diferente de 999, no caso desta rota ser selecionada o sistema será finalizado.
void atualizar(int rotaAtual) {
    system("cls");
    int proxRota = getRoute(rotaAtual);
    if (proxRota != 999) {
        atualizar(proxRota);
    } else {
        printf_s("\nFinalizando...");
    }
}

// Método que inicializará o sistema.
// Também neste método serão adicionadas todas as configurações necessárias.
// Adicionado o método setLocale com o valor Portuguese_Brasil para realizar tentativa de setar o programa para o padrão UTF8.
void rodarSistema() {
    setlocale(LC_ALL, "Portuguese_Brasil");

    // Valor inicial será definido com 0 para a primeira tela ser a tela de menu.
    atualizar(0);
}

#endif
