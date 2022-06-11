#include "studente.h"
#include <stdio.h>

float calcola_media (Studente s) {

    int i;
    float somma = 0, count = 0;

    for (i = 0; i < N_VOTI; i++) {
        if (s.voti[i] != -1) {
            somma = somma + s.voti[i];
            count++;
        }
    }
    
    if (count != 0) {
        float media = somma / count;
        return media;
    } else {
        return -1;
    }
}

int sufficienza_studente (Studente s) {

    if (calcola_media(s) >= 18) {
        return 1;
    } else {
        return 0;
    }
}

void print_studente (Studente s) {

    int i;

    printf ("%s ", s.nome);
    printf ("%s", s.cognome);
    
    for (i = 0; i < N_VOTI; i++) {
        printf (" %d", s.voti[i]);
    }

    printf ("\n");
}