#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_STACK_HEIGHT 40
#define MAX_CODE_LENGTH 200
#define MAX_LEXI_LEVELS 3


/* typedef struct Stack{

  int size;

  int *values;

  int capacity;

} Stack; */

char* OPS[] =  // OP Code stuff for printing
{
  //11 basic instructions
  "lit","rtn","lod","sto","cal","inc","jmp","jpc","sio",
  //13 arithmetic instructions
  "neg","add","sub","mul","div","odd","mod","eql","neq","lss","leq","gtr","geq"
};

typedef struct Instruction{
  int op;
  int R;
  int L;
  int M;

} Instruction;

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
int stack[MAX_STACK_HEIGHT] = {0};
int reg[8] = {0};

int base(l, base) // l stand for L in the instruction format
{
  int b1; //find base L levels down
  b1 = base;
  while (l > 0)
  {
    b1 = stack[b1 + 1];
    l--;
  }
  return b1;
}

int main(){
  //Variable declaration
  int i;
  int codecount = 0;
  int opcode, r, l, m;
  char filename[30];
  //file i/o and stack creation
  FILE *ifp = NULL;

  int stack[MAX_STACK_HEIGHT] = {0};
  int reg[8] = {0}; // registers initialized to 0


  //code creation
strcpy(filename, "input.txt");
  ifp = fopen(filename, "r");
  if(ifp == NULL)
    printf("FILE READ ERROR, TRY AGAIN");

  Instruction *code[MAX_CODE_LENGTH];

  printf("Line	OP	R	L	M");
  while(fscanf(ifp, "%d %d %d %d", &opcode, &r, &l, &m) != EOF){

      code[codecount] = buildIR(opcode, r, l, m);
      printf("%d %s \t %d %d %d", codecount, OPS[opcode], r, l, m);
      codecount++;
  }

  int halt = 0;
  Instruction *IR;
  /* EXEXCUTE CYCLE */
  while(halt != 1){

  IR = code[pc];
  pc = pc + 1;

     switch (IR->op)
     {
     	case 1 :
      // LIT 1
     reg[IR->R] = IR->M;
     break;

     // RTN 2
     case 2 :
     sp = bp -1;
     bp = stack[sp+3];
     pc = stack[sp+4];
     break;

     // LOD 3
     case 3:
     reg[IR->R] = stack[base(IR->L,bp)+IR->M];
     break;

     // STO 4
     case 4 :
     stack[base(IR->L,bp)+IR->M] = reg[IR->R];
     break;

     // CAL 5
     case 5 :
     stack[sp + 1]  = 0; // space to return value
     stack[sp + 2]  =  base(IR->L, bp); // static link (SL)
     stack[sp + 3]  = bp; // dynamic link (DL)
     stack[sp + 4]  = pc; // return address (RA)
     bp = sp + 1;
     pc = IR->M;
     break;

     // INC 6
     case 6:
     sp = sp + IR->M;
     break;

     // JMP 7
     case 7:
     pc = IR->M;
     break;

     // JPC 8
     case 8:
     if (reg[IR->R] == 0)
     {
     	pc = IR->M;
     }
     break;

     // SIO 9
     case 9:
     printf("%d", reg[IR->R]);
     break;

     // SIO 10
     case 10:
     scanf("%d", &reg[IR->R]);
     break;

     // SIO 11
     case 11:
     halt = 1; // end of program
     break;

     /* OPR */
    // NEG 12
     case  12:
     reg[IR->R] = -reg[IR->R];
     break;

     case 13:
     reg[IR->R] = reg[IR->L] + reg[IR->M];
     break;

     case 14:
     reg[IR->R] = reg[IR->L] - reg[IR->M];
     break;

     case 15:
     reg[IR->R] = reg[IR->L] * reg[IR->M];
     break;

     case 16:
     reg[IR->R] = reg[IR->L] / reg[IR->M];
     break;

     case 17:
     reg[IR->R] = reg[IR->R] % 2;
     break;

     case 18:
     reg[IR->R] = reg[IR->L] % reg[IR->M];
     break;

     case 19:
     reg[IR->R] = reg[IR->L] == reg[IR->M];
     break;

     case 20:
     reg[IR->R] = reg[IR->L] != reg[IR->M];
     break;

     case 21:
     reg[IR->R] = reg[IR->L] < reg[IR->M];
     break;

     case 22:
     reg[IR->R] = reg[IR->L] <= reg[IR->M];
     break;

     case 23:
     reg[IR->R] = reg[IR->L] > reg[IR->M];
     break;

     case 24:
     reg[IR->R] = reg[IR->L] >= reg[IR->M];
     break;
    }
  }
}
