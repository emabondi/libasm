section	.text
	extern __errno_location
	global ft_write

	ft_write:
		mov rax,1			;1 is syscall number for write
		syscall
		test rax, rax		;check return value of syscall
		js .error			;jump if signed (negative)
		ret

	.error:
		neg rax				;fa il negativo per ottenere l'error number
		mov rdi, rax		;store error value in rdi
		push rax
		call __errno_location
		pop qword [rax]
		mov qword [rax], rdi	;set the value of errno
		neg rax
		ret

