.data 0x0 

pattern: .space 32
	
newline:	.asciiz "\n"
nPrompt:	.asciiz "Enter the number of bits (N):\n"

.text 0x3000

main: 

ori     $sp, $0, 0x3000     	# Initialize stack pointer to the top word below .text
                                # The first value on stack will actually go at 0x2ffc
                                #   because $sp is decremented first.
addi    $fp, $sp, -4        	# Set $fp to the start of main's stack frame 
 

la	$s2, pattern	#loading Pattern Array into $a0


addi 	$v0, $0, 4		# system call 4 is for printing a string
la 	$a0, nPrompt 		# address of nPrompt is in $a0
syscall



addi	$v0, $0, 5	#Reading in a integer
syscall			#$s0 will function as the number of bits, 
			#$s1 will be unsigned int n
add	$a1, $0, $v0	#Setting up N
add	$a2, $0, $a1	#Setting up n


addi $t0, $0, 0 

add $t7, $s2, $a1
sb $t0, 0($t7)






jal	bingen
j	exit


bingen:


#STACK

addi    $sp, $sp, -8  
sw	$ra, 4($sp)
sw	$fp, 0($sp)
addi	$fp, $sp, 4

addi $sp, $sp, -8


sw $a2, 4($sp)	
sw $t1, 0($sp)	#saves $t1 to the stack

slt $t0, $0, $a2
beq $t0, $0, print

sub $t1, $a1, $a2
add $t3, $t1, $s2

addi $t7, $0, 48
sb  $t7, 0($t3)

addi $a2, $a2, -1

jal bingen


#==================================================================

add $t3, $t1, $s2
addi $t8, $0, 49
sb  $t8, 0($t3)
jal bingen
j restoreStack

print: 

la	$a0, 0($s2)
addi	$v0, $0, 4
syscall

la	$a0, newline
addi	$v0, $0, 4
syscall
j restoreStack


restoreStack:

lw $a2, -8($fp)
lw $t1, -12($fp)

addi $sp, $fp, 4
lw $ra, 0($fp)
lw $fp, -4($fp)
jr $ra


exit:

li	$v0, 10
syscall
