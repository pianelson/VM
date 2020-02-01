#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_STACK_HEIGHT 40
#define MAX_CODE_LENGTH 200
#define MAX_LEXI_LEVELS 3


typedef struct Stack{

  int size;

  int *values;

  int capacity;

} Stack;

typedef struct Instruction{
  int op;
  int R;
  int L;
  int M;

} Instruction;



Stack *buildStack()
{
	Stack *VM;

	if ((VM = malloc(sizeof(Stack))) == NULL)
		return NULL;

	if ((VM->values = malloc(sizeof(int)*MAX_STACK_HEIGHT)) == NULL)
	{
		free(VM);
		return NULL;
	}

	VM->size = 0;
	VM->capacity = MAX_STACK_HEIGHT;

	return VM;
}

Instruction *buildIR(int opcode, int r, int l, int m){

  Instruction *IR;

  if((IR = malloc(sizeof(Instruction))) == NULL)
    return NULL;

  IR->op = opcode;
  IR->R = r;
  IR->L = l;
  IR->M = m;

  return IR;

}

int sp = 0;
int bp = 1;
int pc = 0;



int main(){
  //Variable declaration
  int i;
  int codecount = 0;
  int opcode, r, l, m;
  char filename[30];
  //file i/o and stack creation
  FILE *ifp = NULL;

  int stack[MAX DATA-STACK HEIGHT] = {0};

  strcpy(filename, "input.txt");
  ifp = fopen(filename, "r");
  if(ifp == NULL)
    printf("FILE READ ERROR, TRY AGAIN");
  //code creation

  Instruction *code[MAX_CODE_LENGTH];





  Instruction *current = buildIR(0,0,0,0);

  while(fscanf(ifp, "%d %d %d %d", &opcode, &r, &l, &m) != EOF){

      code[codecount] = buildIR(opcode, r, l, m);
      codecount++;


  }
    IR = code[pc];
    pc = pc + 1;
    halt = 0;

  /* EXEXCUTE CYCLE */
  while(halt != 1){
     /* PSEUDOCODE put this in a switch statement */
     switch (opcode)
     {
     	case 1 :
      // LIT 1
     IR->r = IR->m;
     break;

     // RTN 2
     case 2 :
     sp = bp -1;
     bp = stack[sp+3];
     pc = stack[sp+4];
     break;

     // LOD 3
     case 3:
     IR->r = stack[base(IR->l,bp)+IR->m];
     break;

     // STO 4
     case 4 :
     stack[base(IR->l,bp)+IR->m] = IR->r;
     break;

     // CAL 5
     case 5 :
     stack[sp + 1]  = 0; // space to return value
     stack[sp + 2]  =  base(IR->l, bp); // static link (SL)
     stack[sp + 3]  = bp; // dynamic link (DL)
     stack[sp + 4]  = pc; // return address (RA)
     bp = sp + 1;
     pc = IR->m;
     break;

     // INC 6
     case 6:
     sp = sp + IR->m;
     break;

     // JMP 7
     case 7:
     pc = IR->m;
     break;

     // JPC 8
     case 8:
     if (stack [sp] == 0)
     {
     	pc = IR->m;
     }
     break;

     // SIO 9
     case 9:
     print(IR->r);
     break;

     // SIO 10
     case 10:
     read(IR->r);
     break;

     // SIO 11
     case 11:
     halt = 1; // end of program
     break;

     /* OPR */
    // NEG 12
     case  12:
     IR->r = -IR->r;
     break;

     case 13:
     IR->r = IR->l + IR->m;
     break;

     case 14:
     IR->r = IR->l - IR->m;
     break;

     case 15:
     IR->r = IR->l * IR->m;

     case 16:
     IR->r = IR->l / IR->m;

     case 17:
     IR->r = IR->r mod 2;

     case 18:
     IR->r = (IR->l) mod (IR->m);
     break;

     case 19:
     IR->r = IR->l == IR->m;
     break;

     case 20:
     IR->r = IR->l != IR->m;
     break;

     case 21:
     IR->r = IR->l < IR->m;
     break;

     case 22:
     IR->r = IR->l <= IR->m;
     break;

     case 23:
     IR->r = IR->l > IR->m;
     break;

     case 24:
     IR->r = IR->l => IR->m;
     break;
  }

  void print ()
  {

  }

  void read ()
  {

  }



    }
    free(IR);
  }
