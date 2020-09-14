
.eqv	N	4	# Number of integers to be reversed
.eqv	NSIZE	16	# Total size of these integers

.data
wlcm1:	.asciz 	"Input "
wlcm2:	.asciz	" numbers, I'll reverse them.\n"

.align	2
values:	.space	NSIZE

.text

	# Print welcome message
	la	x10, wlcm1
	li	x17, 4
	ecall	
	li	x10, N
	li	x17, 1
	ecall
	la	x10, wlcm2
	li	x17, 4
	ecall	


	# Input numbers
	# (using index to calculate element address on every iteration)
	li	x1, 0	   # index
	li	x2, N	   # limit
	la	x3, values # head of values array
	
inloop:
	bge	x1, x2, einloop	# break if index >= limit

	li	x17, 5 # ReadInt
	ecall
	
	# Store value into array
	slli	x4, x1, 2
	add	x4, x4, x3
	sw	x10, 0(x4)
	
	addi	x1, x1, 1
	b	inloop

einloop:


	# Output numbers in reverse order
	# (using element address decremented on every iteration)
	
	# calculate (value + (N-1)*4)
	la	x1, values
	li	x2, N
	addi	x2, x2, -1
	slli	x2, x2, 2
	add	x1, x1, x2
	# x1 now contains address of the next element to print
	
	la	x2, values
	# x2 contains addres of the last element to print
	
outloop:
	blt	x1, x2, eoutloop
	
	# Load value from array and print it
	lw	x10, 0(x1)
	li	x17, 1
	ecall
	li	x10, '\n'
	li	x17, 11
	ecall
	
	addi	x1, x1, -4 # address of next value
	
	b  	outloop

eoutloop:
