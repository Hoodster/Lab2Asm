includelib  kernel32.lib
EXTERN MessageBoxA: PROC
EXTERN WriteConsoleA: PROC
EXTERN SetConsoleTitleA: PROC
EXTERN GetForegroundWindow: PROC
EXTERN GetStdHandle: PROC
EXTERN ExitProcess: PROC

.data
STD_INPUT_HANDLE = -10
STD_OUTPUT_HANDLE = -11

hello_msq db "Hello World", 0
dummy dq 0
stdHandle dq 0
handler dq 0

.code
addInt PROC
mov RAX, RCX
add RAX, RDX
ret
addInt ENDP

subInt PROC
mov RAX, RCX
sub RAX, RDX
ret
subInt ENDP

mulInt PROC
mov RAX, RCX
mov RBX, RDX
xor RDX, RDX
imul RBX
ret
mulInt ENDP

divInt PROC
mov RAX, RCX
mov RBX, RDX
xor RDX, RDX
idiv RBX
ret
divInt ENDP

addFloat PROC
addps XMM0, XMM1
ret
addFloat ENDP

subFloat PROC
subps XMM0, XMM1
ret
subFloat ENDP

mulFloat PROC
mulps XMM0, XMM1
ret
mulFloat ENDP

divFloat PROC
divps XMM0, XMM1
ret
divFloat ENDP
END
