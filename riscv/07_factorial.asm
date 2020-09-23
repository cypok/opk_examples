	li	a0, 5
	call	print_facts
	li      a7, 10
        ecall


# Print first N factorials.
print_facts:
	addi	sp, sp, -16
	sw	ra, 0(sp)
	sw	s0, 4(sp)
	sw	s1, 8(sp)

        mv      s0, a0	# total count
        li      s1, 0   # current ordinal
        
loop:   bge     s1, s0, pf_end
        addi    s1, s1, 1
        mv	a0, s1
        call    print_int
        mv	a0, s1
        call	fact
        call    print_int
        b       loop
        
pf_end:	lw	s1, 8(sp)
	lw	s0, 4(sp)
	lw	ra, 0(sp)
	addi	sp, sp, 16
	ret

        
print_int:
        li      a7, 1
        ecall
        li      a0, '\n'
        li      a7, 11
        ecall
        ret	


# fact(n) = if (n > 0) fact(n-1) * n
#           else 1
fact: 	addi	sp, sp, -16
	sw	ra, 4(sp)
	sw	s0, 0(sp)
	blez 	a0, norec
	mv	s0, a0
	addi	a0, a0, -1
	call	fact
	mul	a0, a0, s0
	b	f_end

norec:	li	a0, 1
	
f_end:	lw	s0, 0(sp)
	lw 	ra, 4(sp)
	addi	sp, sp, 16
	ret
