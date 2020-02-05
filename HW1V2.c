/*Nick Robelo & Pia Nelson */

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
  //printf("B1 BEFORE IS: %d\n", b1);
  //printf("L is: %d\n",l);
  while (l > 0)
  {
    b1 = stack[b1 + 1];
    l--;
  }

  //printf("B1 AFTER IS: %d\n", b1);
  if(b1 == 0)
    b1++;
  return b1;
}

void printStack(int* stack, int sp, int bp){
  if (bp == 0){
    return;
  }
  if(bp == 1){
    printf("");
  }
  if(bp != 1){
    printStack(stack, bp-1, stack[bp+2]);
  }
  if(bp <= sp){
    if(bp != 1)
      printf("| ");

    int i;
    for(i = bp; i <= sp; i++){
      printf("%d ", stack[i]);
    }
  }
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

  printf("Line\tOP\tR\tL\tM\n");
  while(fscanf(ifp, "%d %d %d %d", &opcode, &r, &l, &m) != EOF){

      code[codecount] = buildIR(opcode, r, l, m);
      printf("%d\t%s\t%d\t%d\t%d\n", codecount, OPS[opcode-1], r, l, m);
      codecount++;
  }

  int halt = 0;
  /* EXEXCUTE CYCLE */

  printf("                      pc  bp  sp   registers\n");
  printf("Initial Values        %d   %d   %d    %d %d %d %d %d %d %d %d\n", pc, bp, sp, reg[0], reg[1], reg[2], reg[3], reg[4], reg[5], reg[6], reg[7]);
  printf("Stack: ");
  for(i = 0; i < MAX_STACK_HEIGHT; i++){
    printf("%d ", stack[i]);
  }
  printf("\n");
  int pcholder;
  Instruction *IR;

  while(halt != 1){
  IR = code[pc];
  //printf("PC = %d\n", pc);
  //printf("op = %d, r = %d, l = %d, m = %d\n", IR->op, IR->R, IR->L, IR->M);
  pc = pc + 1;
  pcholder = pc;

     switch (IR->op)
     {
     case 1:
      // LIT 1
     reg[IR->R] = IR->M;
     break;

     // RTN 2
     case 2:
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
     //printf("base + ir->m : %d\n", (base(IR->L, bp)+IR->M));
     stack[(base(IR->L,bp)+IR->M)] = reg[IR->R];
     //printf("stack should be: %d\n", stack[5]);

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

    printf("                      pc  bp  sp   registers\n");
    printf("%d %s %d %d %d          %d   %d   %d    %d %d %d %d %d %d %d %d \n", pcholder - 1, OPS[IR->op-1], IR->R, IR->L, IR->M, pcholder, bp, sp, reg[0], reg[1], reg[2], reg[3], reg[4], reg[5], reg[6], reg[7]);
    printf("Stack: " );
    printStack(stack, sp, bp);
    printf("\n");

  }
}
