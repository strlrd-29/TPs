#include<stdio.h>
#include<stdlib.h>

struct noeud
{
    int info;
    struct noeud *suivant;
};

typedef struct noeud Element;

Element* insertionDebut(int n, Element *l)
{
    Element *nouveau;
    nouveau=(Element*)malloc(sizeof(Element));
    if(!nouveau)
    {
        printf("There has been some issue");
        exit(-1);
    }
    nouveau->info = n;
    nouveau->suivant = l;

    l=nouveau;
    return l;
}

Element* deleteFirst(Element *l)
{
    Element *p = l;
    l=l->suivant;
    free(p);
    return l;
}

void displayList(Element *l)
{
    int i=0;
    Element *p;

    printf("le contenu de la liste est :");
    for(p=l; p!=NULL; p=p->suivant)
    {
        printf("\n valeur %d : %d ---- son adresse : %p",i+1,p->info,p);
        i++;
    }
}

int main()
{
    Element *liste;
    liste = NULL;

    liste = insertionDebut(3,liste);
    liste = insertionDebut(4,liste);
    liste = insertionDebut(5,liste);
    liste = insertionDebut(6,liste);
    liste = deleteFirst(liste);
    displayList(liste);

    return 0;
}
