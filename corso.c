#include "corso.h"
#include <stdio.h>

void inserisci_in_array(Studente A[], int start_index, int end_index) {

    Studente value = A[start_index];
    int index = start_index;

    while (index != end_index) {
        A[index] = A[index - 1];
        index--;
    }
    
    A[end_index] = value;
}

void merge(Studente arr[], int l, int m, int r) {

    int l1 = m + 1;

    while (l <= m && l1 <= r) {

        if (calcola_media(arr[l]) <= calcola_media(arr[l1])) {
            l++;
        } else {
            inserisci_in_array(arr, l1, l);
        }

        l++; m++; l1++;
    }
}

void mergeSort(Studente arr[], int l, int r) {

    int m = l + (r - l)/2;

    if (l < r) {

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

float percentuale_superamento_test(Studente s[], int n_studenti, int esame) {
    
    float n_promossi = 0, n_conseguiti = 0, cento = 100;
    int i;

    for (i = 0; i < n_studenti; i++) {

        if (s[i].voti[esame] != -1) {

            n_conseguiti +=1;

            if (s[i].voti[esame] >= 18) {
                n_promossi += 1;
            }
        }
    }

    float percentuale = n_promossi / n_conseguiti;
    return percentuale;
    
}

Studente miglior_studente(Studente s[], int n_studenti) {

    Studente migliore = s[0];
    int i;

    for (i = 0; i < n_studenti; i++) {

        if (calcola_media (s[i]) > calcola_media (migliore)) {
            migliore = s[i];
        }
    }

    return migliore;
}

void ordina_studenti(Studente s[], int n_studenti) {

    float medie[n_studenti];
    int i;

    /*for (i = 0; i < n_studenti; i++) {
        medie[i] = calcola_media (s[i]);
    }*/

    mergeSort (s, 0, n_studenti - 1);
}