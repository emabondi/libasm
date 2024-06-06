section	.text
	global ft_strlen
	
	ft_strlen:
		xor rax, rax		;set counter to 0

	.loop:
		cmp byte [rdi], 0	;check if rdi is 0
		je .done			;if equal to 0 jump to .done
		inc rdi				;next char
		inc rax				;inc counter
		jmp .loop			;restart loop
	
	.done:
		ret					;return result in rax