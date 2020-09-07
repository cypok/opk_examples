	# Read first integer
	li	x17, 5
	ecall
	mv	x1, x10
	# x1 contains first input
	
	# Read second integer
	ecall
	# x10 contains second input

	# Let x10 <- x1 + x10
	add	x10, x1, x10
	
	# Print result
	li	x17, 1
	ecall
