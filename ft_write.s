section	.text
	extern __errno_location
	global ft_write

	ft_write:
		call	__errno_location wrt ..plt
		mov		qword [rax], 0				;sets errno to 0
		mov		rax,1						;1 is syscall number for write
		syscall
		test	rax, rax					;check return value of syscall
		js		.error						;jump if signed (negative)
		ret

	.error:
		neg		rax							;fa il negativo per ottenere l'error number
		push	rax						
		call	__errno_location wrt ..plt
		pop		qword [rax]					;push and pop rax in stack to avoid that the call changes it
		mov		rax, -1						;sets ret value
		ret

