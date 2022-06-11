#include "parser.h"

int conta_linee(FILE* fp){
    char c = fgetc(fp);
    int linee = 1;
    while(c!=EOF){
        if(c=='\n'){
            linee++;
        }
        c = fgetc(fp);
    }
    rewind(fp);
    return linee;
}

void leggi_studente(FILE* fp, Studente* s){
    fscanf(fp, "%s %s", s->nome, s->cognome);
    int j;
    for(j=0; j<N_VOTI; j++){
        fscanf(fp, "%d", s->voti+j);
    }
}

void scrivi_studente(FILE* fp, Studente s){
    fprintf(fp, "%s %s", s.nome, s.cognome);
    int j;
    for(j=0; j<N_VOTI; j++){
        fprintf(fp, " %d", s.voti[j]);
    }
    fprintf(fp, "\n");
}