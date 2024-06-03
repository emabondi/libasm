section .data
	hello: db "ciao prova", 5
	helloLen: equ $-hello

section	.text
	global _start
	
	_start:
		mov	rax,1
		mov	rdi,1
		mov rsi,hello
		mov rdx,helloLen
		syscall

		mov rax,60
		mov rdi,0
		syscall




section	.text
	[GLOBAL ft_strlen:]
	
	ft_strlen:
			xor rax, rax ;set counter to 0

	.loop:
		cmp byte [rdi], 0	;check if rdi is 0
		je .done			;if equal to 0 jump to .done
		inc rdi				;next char
		inc rax				;inc counter
		jmp .loop			;restart loop
	
	.done:
		ret					;return result in rax