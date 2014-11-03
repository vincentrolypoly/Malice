 segment .bss
global_0_rbp resb 8
hatta_0_rbp resb 8
LC0_1_rbp resb 8
segment .text
global main
extern printf
extern scanf
extern malloc
segment .data.
integer:
	db "%i",0 
string:
	db `%s`,0 
char: 
   db "%c",0 
scaninteger:
	db "%d", 0
scanstring:
	db `%[^\n]%*c` , 0
scanchar: 
   db "%c"
main:
push rbp
mov rbp,rsp
mov [global_0_rbp],rbp
call hatta_0
mov rsp,rbp
pop  rbp
ret
string0: 
db `\n`,0
hatta_0:
push rbp
mov rbp,rsp
mov [hatta_0_rbp],rbp
mov [LC0_1_rbp],rbp
mov rbx,0
push rbx
loop_0:
mov rbx,[hatta_0_rbp]
lea rbx, [rbx+-8]
mov rbx,[rbx]
mov rcx,3
cmp rbx,rcx
mov rbx,0
jne bool_0
not rbx
bool_0:
cmp rbx,0
jne endloop_0
push rdi
push rsi
push rax
mov rbx,[hatta_0_rbp]
lea rbx, [rbx+-8]
mov rsi,[rbx]
mov rdi,integer
mov rax,0
call printf
pop  rax
pop  rsi
pop  rdi
push rdi
push rsi
push rax
mov rbx,string0
mov rsi,rbx
mov rdi,string
mov rax,0
call printf
pop  rax
pop  rsi
pop  rdi
mov rbx,[hatta_0_rbp]
lea rbx, [rbx+-8]
mov rcx,[hatta_0_rbp]
lea rcx, [rcx+-8]
mov rbx,[rcx]
inc rbx
mov [rcx],rbx
jmp loop_0
endloop_0:
mov rsp,rbp
pop  rbp
ret
