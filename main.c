#include <stdio.h>
#include <stdlib.h>

#define NAME_MAXLEN 30
#define SURNAME_MAXLEN 30
#define CLASS_MAXLEN 4

struct s_student {
    char name[NAME_MAXLEN+1];
    char surname[SURNAME_MAXLEN+1];
    char class[CLASS_MAXLEN+1];
    int age;
};

typedef struct s_student student;

struct s_element {
    student value;
    struct s_element *next;
};

typedef struct s_element element;

element * addElement(element *first, student value);
void printList(element *first);
void emptyList(element *first);

int main(int argc, char** argv) {
    element * first;
    student value;
    int choice;
    
    first = NULL; // lista vuota
    choice = 1;
    while(choice != 0) {
        printf("Qual è il nome dello studente? (max %d) ", NAME_MAXLEN);
        scanf("\n%[^\n]", value.name);
        printf("Qual è il cognome dello studente? (max %d) ", SURNAME_MAXLEN);
        scanf("\n%[^\n]", value.surname);
        printf("Qual è la classe dello studente? (max %d) ", CLASS_MAXLEN);
        scanf("%s", value.class);
        printf("Qual è l'eta' dello studente? ");
        scanf("%d", &(value.age));
        
        first = addElement(first, value);
        if(first == NULL) {
            fprintf(stderr, "Impossibile allocare la memoria richiesta");
            exit(1);
        }
        
        printf("Vuoi aggiungere un altro elemento? (1: Sì, 0: No) ");
        scanf("%d", &choice);
    }
    
    printList(first);
    
    emptyList(first);
    
    return (EXIT_SUCCESS);
}

element * addElement(element *first, student value) {
    element * newElement;
    newElement = (element *)malloc(sizeof(element));
    if(newElement != NULL) {
        newElement->value = value;
        newElement->next = first;
    }
    first = newElement; // non indispensabile: solo per chiarezza
    return first;
}

void printList(element *first) {
    printf("\nStampa della lista\n");

    /* Avrei potuto impiegare direttamente first.
     * Infatti il passaggio dei parametri ad una funzione è per valore:
     * il parametro formale first è una copia del parametro attuale.
     * 
     * Per chiarezza viene, comunque, usato un puntatore per scorrere gli elementi
     * della lista.
     */
    element *current;
    current = first;
    while(current != NULL){
        printf("%s, %s, %s, %d\n",
                current->value.name, 
                current->value.surname, 
                current->value.class, 
                current->value.age);
        current = current->next;
    }
    return;
}

void emptyList(element *first) {
    printf("\nSvuotamento della lista in corso... ");
    element *temp;
    while(first != NULL) {
        temp = first;
        first = first->next;
        free(temp);
    }
    printf("completato\n");
    return;
}
