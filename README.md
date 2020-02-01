In  this  assignment,  you  will  implement  a  virtual  machine  (VM)  known  as  the  P-machine (PM/0).  The  P-machine  is  a  stack  machine  with  two  memory  stores:  the  “stack,”  which  is organized  as  a  stack  and  contains  the  data  to  be  used  by  the  PM/0  CPU,  and  the  “text”, which contains the instructions for the VM. The PM/0 CPU has four registers to handle the stack  and  text  segments:  The  registers  are  named  base  pointer  (BP),  stack  pointer  (SP), program counter (PC) and instruction register (IR). They will be explained in detail later on in this document. The machine also has a register file (RF) with eight (8) registers (0-7).

COMPILATION PROCESS

Step 1 (Preprocessing) : cpp vm.c vm.i

Step 2 (Compilation) : gcc -S vm.i -o vm.s

Step 3 (Assembly) : as vm.s -o vm.o

Step 4 (Linking) : gcc vm.o

Step 5 (Executiom) : ./a.out

