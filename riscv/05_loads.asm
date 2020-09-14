.data
value:	.word	0x13579BDF

msg:	.ascii	"Hello"
	.byte	' '
	.ascii	"world"
	.byte	0x21
	.byte	'\n'
	.byte	0
	
# Plain 100 bytes
buffer:	.space 	100

.macro	print_int
	li	x17, 1
	ecall
	li	x10, '\n'
	li	x17, 11
	ecall
.end_macro
	
.text
	la	x1, value
	
	# Print value as signed byte, unsigned byte, ...
	lb	x10, 0(x1)
	print_int
	lbu	x10, 0(x1)
	print_int
	lh	x10, 0(x1)
	print_int
	lhu	x10, 0(x1)
	print_int
	lw	x10, 0(x1)
	print_int
	
	# Print value as a sequence of bytes
	lbu	x10, 0(x1)
	print_int
	lbu	x10, 1(x1)
	print_int
	lbu	x10, 2(x1)
	print_int
	lbu	x10, 3(x1)
	print_int
	
	
	# Print msg
	la	x10, msg
	li	x17, 4
	ecall
	
	
	# Initialize and print string
	la	x10, buffer
	li 	x2, 'B'
	sb 	x2, 0(x10)
	li 	x2, 'y'
	sb 	x2, 1(x10)
	li 	x2, 'e'
	sb 	x2, 2(x10)
	li 	x2, '!'
	sb 	x2, 3(x10)
	sb 	x0, 4(x10)
	li	x17, 4
	ecall