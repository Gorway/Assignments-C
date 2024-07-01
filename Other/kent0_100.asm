extern printf
section .data
       msg    db  "%d",10,0
section .text
    global main            
main:
  push rbp
  mov rbp, rsp
  sub rsp, 16
  mov DWORD  [rbp-4], 1
  jmp .L1
.L2:
  mov eax, DWORD [rbp-4]
  mov esi, eax
  mov edi, msg
  mov eax, 0
  call printf
  add DWORD  [rbp-4], 2
.L1:
  cmp DWORD [rbp-4], 99
  jle .L2
  mov eax, 0
  leave
  ret
