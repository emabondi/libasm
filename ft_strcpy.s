section	.text
	global ft_strcpy

	;ARGS: rdi= dest, rsi= src
	
	ft_strcpy:
		push rdi			;save dest in stack

	.loop:
		mov al, [rsi]		;load byte from src in al that is lower 8 bits of eax/rax
		mov [rdi], al		;copy byte inside dest
		inc rsi				;next byte in src
		inc rdi				;next byte in dest
		test al, al			;check if byte copied is 0
		jnz	.loop			;jump if not 0 to loop

		pop rax				;put dest pointer in rax
		ret					;return rax