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

char** OPS[] =  // OP Code stuff for printing
{  //11 basic instructions
  "lit","rtn","lod","sto","cal","inc","jmp","jpc","sio",
  //13 arithmetic instructions
  "neg","add","sub","mul","div","odd","mod","eql","neq","lss","leq","gtr","geq"
};

typedef struct Instruction{
  int op;
  int r;
  int l;
  int m;

} Instruction;



/*Stack *buildStack()
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
} */

Instruction *buildIR(int opcode, int r, int l, int m){

  Instruction *IR;

  if((IR = malloc(sizeof(Instruction))) == NULL)
    return NULL;

  IR->op = opcode;
  IR->r = r;
  IR->l = l;
  IR->m = m;

  return IR;

}

int userIn = 0;
int sp = 0;
int bp = 1;
int pc = 0;


/* FETCH CYCLE */
    // IR = code[pc];
    // pc = pc + 1;
    int halt = 0;
    Instruction *irp;

  /* EXECUTE CYCLE */
void execute ()
{
  while(halt != 1){
  Instruction* IR = code[pc]; 
  pc = pc + 1;
     /* PSEUDOCODE put this in a switch statement */
     switch (IR->op)
     {
     case 1:
      // LIT 1
     reg[IR->r] = IR->m;
     break;

     // RTN 2
     case 2:
     sp = bp -1;
     bp = stack[sp+3];
     pc = stack[sp+4];
     break;

     // LOD 3
     case 3:
     reg[IR->r] = stack[base(IR->l,bp)+IR->m];
     break;

     // STO 4
     case 4 :
     stack[base(IR->l,bp)+IR->m] = reg[IR->r];
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
     if (reg[IR->r] == 0)
     {
     	pc = IR->m;
     }
     break;

     // SIO 9
     case 9:
     printf(reg[IR->r]);
     break;

     // SIO 10
     case 10:
     scanf("%d", reg[IR->r]);
     break;

     // SIO 11
     case 11:
     halt = 1; // end of program
     break;

     /* OPR */
    // NEG 12
     case  12:
     reg[IR->r] = -reg[IR->r];
     break;

     case 13:
     reg[IR->r] = reg[IR->l] + reg[IR->m];
     break;

     case 14:
     reg[IR->r] = reg[IR->l] - reg[IR->m];
     break;

     case 15:
     reg[IR->r] = reg[IR->l] * reg[IR->m];
     break;

     case 16:
     reg[IR->r] = reg[IR->l] / reg[IR->m];
     break;

     case 17:
     reg[IR->r] = reg[IR->r] % 2;
     break;

     case 18:
     reg[IR->r] = reg[IR->l] % reg[IR->m];
     break;

     case 19:
     reg[IR->r] = reg[IR->l] == reg[IR->m];
     break;

     case 20:
     reg[IR->r] = reg[IR->l] != reg[IR->m];
     break;

     case 21:
     reg[IR->r] = reg[IR->l] < reg[IR->m];
     break;

     case 22:
     reg[IR->r] = reg[IR->l] <= reg[IR->m];
     break;

     case 23:
     reg[IR->r] = reg[IR->l] > reg[IR->m];
     break;

     case 24:
     reg[IR->r] = reg[IR->l] >= reg[IR->m];
     break;
     
     default :
     	error_stackOverflow();
     	break;
}
return; 

void error_stackOverflow ()
{
	printf("ERROR: STACK OVERFLOW");
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



 //Instruction *current = buildIR(0,0,0,0);
	
  printf("Line	OP	R	L	M");
  while(fscanf(ifp, "%d %d %d %d", &opcode, &r, &l, &m) != EOF){

      code[codecount] = buildIR(opcode, r, l, m);
      printf("%d %s %t %d %t %d %t %d", codecount, OPS[opcode], r, l, m);
      codecount++; 



  }

    }
    free(IR);
  }
