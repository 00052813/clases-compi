#include <stdlib.h>
#include <stdio.h>
#include "parser.h"
#include "backend.h"

static void Gen_codigo_expresion(Expresion *expr) {
  switch(expr->tipo) {
    case 'D':
      printf("PUSH %d\n",expr->valor);
      break;
    case 'P':
      Gen_codigo_expresion(expr->izquierda);
      Gen_codigo_expresion(expr->derecha);
      switch (expr->oper) {
        case '+':
          printf("ADD\n");
          break;
        case '*':
          printf("MULT\n");
          break;
      }
      break;
  }
}

static int Int_codigo(Expresion *expr){
switch(expr->tipo) {
    case 'D':
      return expr->valor;
      break;
    case 'P':
      //Int_codigo(expr->izquierda);
      //Int_codigo(expr->derecha);
      //printf("%d\n",Int_codigo(expr->izquierda));
      //printf("%d\n",Int_codigo(expr->derecha));
      switch (expr->oper) {
        case '+':
          printf("ADD\n");
          return (Int_codigo(expr->izquierda) + Int_codigo(expr->derecha));
          break;
        case '*':
          return (Int_codigo(expr->izquierda) + Int_codigo(expr->derecha));
          break;
      }
      break;
  }
}


void Procesar(nodo_AST *codigoi){
  printf("%d\n",Int_codigo(codigoi));
  //printf("%d\n",Int_codigo(codigoi));
}

