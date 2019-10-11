.data 0x0010

a: .space 2 # int a[] = {0,0}


.text 0x3000 # what is this?

main:

	addi $t0, $0, 1
	addi $t1, $0, 2
	la $t2, a
	
	sw $t0, 0($t2)	# a[0] = 1
	sw $t1, 4($t2)	# a[1] = 2
	
	or $a0, $0, $t2	# what is this?
	
	jal swap
	
 	jal print

	j exit
	
	
swap:	# nice and easy swap
	
	lw $t3, 0($a0)	# temp1 ($t3) = a[0]
	lw $t4, 4($a0)  # temp2 ($t4) = a[1]
	sw $t4, 0($a0)	# a[0] = temp2
	sw $t3, 4($a0)  # a[1] = temp1
	
	jr $ra
	

print: #simple function to print the value of the first element in array a

	lw $t0, 0($a0)
	addi $v0, $0, 1  			
  	add $a0, $0, $t0
  	syscall 
  	
  	jr $ra
	

exit:	# go bye bye
	ori $v0, $0, 10 
 	syscall 
