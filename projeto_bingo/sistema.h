//
//  sistema.h
//  ProjetoBingo
//

#ifndef sistema_h
#define sistema_h

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "rotas.h"

void rotear() {
    Rota rt = ROTA_MENU;

    while (rt != 999) {
        system("clear");
        rt = rota_ctl(rt);
    }
    
    printf("\nFinalizando...");
    return;
}

void rodar_sistema() {
    setvbuf(stdout, NULL, _IONBF, 0);
    setlocale(LC_ALL, "Portuguese_Brasil");
    rotear();
}

#endif /* sistema_h */
