# Data of your program
.data

# msg - label
# ASCII - encode string as ASCII characters
# \0 - zero byte
msg:	.ascii	"Hello world!\0"

# Text (assembly code) of your program
.text
	# Load Address
	la 	x10, msg
	# x10 contains address of string msg
	
	# Load Immediate
	li	x17, 4	# 4 = PrintString
	# x17 contains value 4
	
	# Environment Call
	# If x17 is 4, then call PrintString(x10)
	ecall
