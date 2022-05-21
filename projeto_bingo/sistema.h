//
//  sistema.h
//  ProjetoBingo
//

#ifndef sistema_h
#define sistema_h

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <sys/stat.h>
#include "rotas.h"
#include "utilitarios.h"

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
    criar_pastas_necessarias();
    rotear();
}

#endif /* sistema_h */
