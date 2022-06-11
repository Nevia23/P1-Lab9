#include <stdio.h>
#include "parser.h"

int main(){
    FILE *fp;
    fp = fopen("studenti.txt","r");
    if (fp==NULL){
        printf("Il file non può essere aperto\n");
    }
    else {
        int n_stud = conta_linee(fp), i;
        Studente s[n_stud];

        for(i=0; i<n_stud; i++){
            leggi_studente(fp, s+i);
            print_studente(s[i]);
        }
        
        fclose(fp);
        printf("File letto\n\n");

        printf("Miglior Studente:\n");
        print_studente(miglior_studente(s, n_stud));

        for(i=0; i<N_VOTI; i++){
            printf("Percentuale superamento corso %d: %3.0f%%\n", i, percentuale_superamento_test(s, n_stud, i)*100);
        }

        ordina_studenti(s, n_stud);
        fp = fopen("studenti_ord.txt", "w");

        for(i=n_stud-1; i>=0; i--){
            scrivi_studente(fp, s[i]);
        }

        fclose(fp);
    }
}

/*#include <stdio.h>
#include "parser.h"

int main(){
    FILE *fp;
    fp = fopen("studenti.txt","r");
    if (fp==NULL){
        printf("Il file non può essere aperto\n");
    }
    else {
        //lettura file qui
        
        fclose(fp);
        printf("File letto\n");

        //ordinamento

        //scrittura file qui

        fclose(fp);
    }
}*/