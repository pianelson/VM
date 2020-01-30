/* Pia Nelson & Nicholas Robelo*/
 #include <stdlib.h>
 #include <stdio.h>
 
#DEFINE MAX_DATA-STACK_HEIGHT 40
#DEFINE MAX_CODE_LENGTH 200
#DEFINE MAX_LEXI_LEVELS 3

struct {
int op; // opcode
int r; // register
int l; // levels
int m; // all the stuff M stands for
}instruction;

/* POINTER INTITIALIZATONS*/
int sp = 0;
int bp = 1;
int pc = 0;
int ir  = 0;

int stack[MAX DATA-STACK HEIGHT] = {0}; // initializes all values in array to 0
int reg[8] = {0}; // registers initialized to 0

main()
{
	int halt = 1;
	while (halt ==1)
	
return 0;
} 
/* FETCH CYCLE */
 ir = code[pc];
 pc = pc + 1;

/* EXEXCUTE CYCLE */

 /* PSEUDOCODE put this in a switch statement */
 switch (opcode)
 {
 	case '1' :
  // LIT 1
 instruction.r = instruction.m;
 break;
 
 // RTN 2
 case '2' :
 sp = bp -1;
 bp = stack[sp+3];
 pc = stack[sp+4];
 break;
 
 // LOD 3
 case'3' :
instruction.r = stack[base(instruction.l,bp)+instruction.m];
break;

 // STO 4
 case '4' :
stack[base(instruction.l,bp)+instruction.m] = instruction.r;
break;

 // CAL 5
 case '5' :
 stack[sp + 1]  = 0; // space to return value
 stack[sp + 2]  =  base(instruction.l, bp); // static link (SL)
 stack[sp + 3]  = bp; // dynamic link (DL)
 stack[sp + 4]  = pc; // return address (RA) 
 bp = sp + 1;
 pc = instruction.m;
 break;
 
 // INC 6
 case '6' :
 sp = sp + instruction.m;
 break;
 
 // JMP 7
 case '7' :
 pc = instruction.m;
 break;
 
 // JPC 8
 case '8' :
 if (stack [sp] == 0)
 {
 	pc = instruction.m;
 }
 break;
 
 // SIO 9
 case '9' :
 print(instruction.r);
 break;
 
 // SIO 10
 case '10' :
 read(instruction.r);
 break;
 
 // SIO 11
 case '11':
 halt = 1; // end of program
 break;
 
 /* OPR */
 
 // NEG 12
 // ADD 13
 // SUB 14
// MUL 15
// DIV 16
// ODD 17
// MOD 18
//EQL 19
// NEQ 20
// LSS 21
//LEQ 22
// GTR 23
//GEQ 24
}
void print ()
{
	
}

void read ()
{
	
}

int base(int instruction.l, int bp) // l stand for L in the instruction format
{  
  int b1; //find base L levels down
  b1 = bp; 
  while (instruction.l > 0)
  {
    b1 = stack[b1 - 1]; // stack doesn't exist
    instruction.l--;
  }
  return b1;
}
