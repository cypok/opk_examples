	# Read first integer
	li	x17, 5
	ecall
	mv	x1, x10
	# x1 contains first input
	
	# Read second integer
	ecall
	# x10 contains second input

	# Branch to "end" if second integer is maximum.
	bge	x10, x1, end
	
	# Otherwise first integer is maximum.
	mv	x10, x1
	
end:		
	# Print result
	li	x17, 1
	ecall
	
