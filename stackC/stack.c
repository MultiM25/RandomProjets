#include <stdlib.h>

typedef struct p{
	int tab[100];
	int taille;
}stack;

stack* new_stack(){
	stack* s =(stack*) malloc(sizeof(stack));
	return s;
}

void push(int valeur, stack* s){
	if(s->taille<100){
		int prec = s->tab[0];
		int cour;
		s->tab[0] = valeur;
		for(int i = 1; i < s->taille-1;i++){
			cour = s->tab[i];
			s->tab[i] = prec;
			prec = cour;
		}
		s->taille++;
	}
}

int top(stack* s){
	if(s->taille>0){
		return s->tab[0];
	}
}

void pop(stack* s){
	if(s->taille > 0){
		for(int i = 1 ; i < s->taille;i++){
			s->tab[i-1] = s->tab[i];
		}
		s->taille--;
	}
}

int is_empty(stack* s){
	return s->taille == 0;
}
