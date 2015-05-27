#include <stdio.h>
#include <stdlib.h>

#define MAXSTRLEN 30
#define MAXCLASSLEN 4

struct s_studente {
    char nome[MAXSTRLEN+1];
    char cognome[MAXSTRLEN+1];
    char classe[MAXCLASSLEN+1];
    int eta;
};
typedef struct s_studente studente;

struct s_elemento{
    studente v;
    struct s_elemento* next;
};
typedef struct s_elemento elemento;

elemento* inserisciStudente(elemento*primo);
void stampaLista(elemento*primo, int i);
void SvuotaLista(elemento *primo);

int main(int argc, char** argv) {
    elemento *primo=NULL;
    char a;
    int i;
    
    i=0;
    do {
        i++;
        printf("\nStudente %d:\n", i);
        primo=inserisciStudente(primo);
        printf("Vuoi inserire un altro studente? (s/n): ");
        scanf("\n%c", &a);
    }while(a=='s');
    
    stampaLista(primo, i);
    SvuotaLista(primo);
    return (EXIT_SUCCESS);
}

elemento* inserisciStudente(elemento*primo){
    elemento *nuovoElemento;
    nuovoElemento=(elemento*)malloc(sizeof(elemento));
    printf("Nome: ");
    scanf("\n%[^\n]", nuovoElemento->v.nome);
    printf("Cognome: ");
    scanf("\n%[^\n]", nuovoElemento->v.cognome);
    printf("Classe: ");
    scanf("\n%[^\n]", nuovoElemento->v.classe);
    printf("Eta': ");
    scanf("\n%d", &(nuovoElemento->v.eta));
    nuovoElemento->next=primo;
    primo=nuovoElemento;
    return primo;
}

void stampaLista(elemento*primo, int i){
    elemento *scorri;
    scorri=primo;
    while(scorri!=NULL){
        printf("\nStudente %d\n Nome: %s\n Cognome: %s\n Classe: %s\n Eta': %d\n",
        i,
        scorri->v.nome,
        scorri->v.cognome,
        scorri->v.classe,
        scorri->v.eta);
        
        scorri=scorri->next;
        i--;
    }
}

void SvuotaLista(elemento *primo){
    elemento *temp;
    printf("\nSvuotamento lista in corso...\n");
    while(primo!=NULL){
        temp=primo->next;
        free(primo);
        primo=temp;
    }
    printf("Completato");
    return;
}