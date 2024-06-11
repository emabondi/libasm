section	.text
	global ft_strcmp

	;ARGS: rdi= s1, rsi= s2
	
	ft_strcmp:
		xor		eax, eax			;set eax to 0

	.loop:
		mov		al, [rdi]		;load byte from s1 in al that is lower 8 bits of eax/rax
		mov		bl, [rsi]		;load byte from s2
		cmp		al, bl
		jne		.not_equal		;if not equal jump to .not_equal
		test	al, al			;check if we reached null terminator
		je		.end				;if equal to 0 jump to end
		inc		rdi
		inc		rsi
		jmp		.loop
	

	.not_equal:
		sub		al, bl
		movsx	eax, al		;put al value in eax and extends the sign
	
	.end:
		ret