 #include <stdlib.h>
 #include <stdio.h>
 
#DEFINE MAX_DATA-STACK_HEIGHT 30
#DEFINE MAX_CODE_LENGTH 500
#DEFINE MAX_LEXI_LEVELS 3

 
struct {
int op; // opcode
int l; // levels
int m; // all the stuff M stands for
}instruction;

/* POINTER INTITIALIZATONS*/
sp = 0;
bp = 1;
pc = 0;
ir  = 0;

int stack[MAX DATA-STACK HEIGHT] = {0}; // initializes all values in array to 0

main()
{
return 0;
} 

/* Montagne's base function*/
int base(int l, int base) // l stand for L in the instruction format
{  
  int b1; //find base L levels down
  b1 = base; 
  while (l > 0)
  {
    b1 = stack[b1 - 1]; // stack doesn't exist
    l--;
  }
  return b1;
}
 /* PSEUDOCODE */
 // LIT *edited* in his docs
 if ( bp == 0)
 {
 	gp = gp + 1;
 	stack[gp] = M;
 }
 else
 {
  sp = sp - 1;  
  stack[sp] = M;	
 }

 
 //OPR IS DEF A SWITCH STATEMENT 2
 
 // LOD 3
 sp = sp -1;
 if (base(L, bp) == 0) 
   stack[sp]  stack[ base(L, bp) + M];
			else
			   stack[sp]  stack[ base(L, bp) - M];

 
 // STO 4
 if (base(l,bp) == 0)
 {
 	stack[base(l,bp) + m] = stack[gp];
	gp = gp -1;
 }
 // CAL 5
 // INC 6
 // JMP 7
 pc = m;
 // JPC 8
 if (stack [sp] == 0)
 {
 	pc = m;
 	s
 }
 // SIO 9-11
 
