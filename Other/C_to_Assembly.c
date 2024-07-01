#include <stdio.h>

int main(){
    int num = 10;
    int res = 0;

    while(num > 0){
        res += num;
        num --;
    }
    printf("%d\n", res);
}
      // SAME IN ASSEMBLER

/* extern printf
section .data
  string db "%d",10,0
section .text
    global main
main:
  push rbp
  mov rbp, rsp
  sub rsp, 16
  xor eax,eax
  mov DWORD [rbp-4], 10
  mov DWORD [rbp-8], 0
  jmp .L1
.L2:
  mov eax, DWORD [rbp-4]
  add DWORD [rbp-8], eax
  sub DWORD [rbp-4], 1
.L1:
  cmp DWORD [rbp-4], 0
  jg .L2
  mov eax, DWORD [rbp-8]
  mov esi, eax
  mov edi, string
  mov eax, 0
  call printf
  mov eax, 0
  leave
  ret

  */
