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

main()
{
return 0;
} 
/* FETCH CYCLE */
ir = stack[pc];
pc = pc +1;

/* EXECUTE CYCLE */

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
 // LIT 1
 
 // RTN 2
 sp = bp -1;
 bp = stack[sp+3];
 pc = stack[sp+4];
 
 // LOD 3

 // STO 4

 // CAL 5
 // INC 6
 sp = sp + m;
 // JMP 7
 pc = m;
 // JPC 8
 if (stack [sp] == 0)
 {
 	pc = m;
 }
 // SIO 9
 // SIO 10
 // SIO 11
 
