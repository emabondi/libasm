section	.text
	extern ft_strlen
	extern ft_strcpy
	extern malloc
	global ft_strdup

	ft_strdup:
		push	rdi			;push in stack to avoid malloc overwrite 

		call	ft_strlen	;rdi is still string to dup
		inc		rax			;inc to add space for '\0' 

		mov		rdi, rax	;put in rdi size to malloc
		call	malloc wrt ..plt
		cmp		rax, 0
		je		.error

		pop		rsi			;string to dup put as src for ft_strcpy
		mov		rdi, rax	;allocated string as dest
		call	ft_strcpy
		ret 

	.error:
		pop		rdi
		ret
