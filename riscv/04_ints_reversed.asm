	# Counter from 10 to 1
	li	x1, 10
	
loop:	
	# Print x1
	mv	x10, x1
	li	x17, 1
	ecall
	
	# Print newline character ('\n' == 10)
	li	x10, '\n'
	li	x17, 11
	ecall
	
	# Decrement x1 and repeat if it is positive
	addi	x1, x1, -1
	bgt	x1, x0, loop
