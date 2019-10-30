.data
  AA:     .space 400  		# int AA[100]
  BB:     .space 400  		# int BB[100]
  CC:     .space 400  		# int CC[100]
  m:      .space 4   		# m is an int whose value is at most 10
                     		# actual size of the above matrices is mxm
   

      # You may add more variables here if you need to
.data 0x0
  product: .space 400
  mPrompt:	.asciiz "Give me an integer to represent the size of each matrices, from 1 to 10:\n"
  aaPrompt:	.asciiz "Enter AA Values:\n"
  bbPrompt:	.asciiz "Enter BB Values:\n"
  ccPrompt:	.asciiz "CC Values are:\n"
  newline:	.asciiz "\n"

.text 0x3000

main:


#------- INSERT YOUR CODE HERE for main -------
#
#  Best is to convert the C program line by line
#    into its assembly equivalent. 
#
#
#  1.  First, read m (the matrices will then be size mxm).
#  2.  Next, read matrix A followed by matrix B.
#  3.  Compute matrix product.  You will need triple-nested loops for this.
#  4.  Print the result, one row per line, with one (or more) space(s) between
#      values within a row.
#  5.  Exit.
#
#----------------------------------------------

  addi 	$v0, $0, 4  			# system call 4 is for printing a string
  la 	$a0, mPrompt 			# address of mPrompt is in $a0
  syscall           			# print the string

  addi	$v0, $0, 5			# system call 5 is for reading an integer
  syscall 				# integer value read is in $v0
  add	$8, $0, $v0			# copy the width into $8

 addi 	$v0, $0, 4  			# system call 4 is for printing a string
  la 	$a0, aaPrompt 			# address of mPrompt is in $a0
  syscall           			# print the string
  
  
 ALoop:
 
 
 
 BLoop:
 
 MultiLoopi:
  
 MultiLoopj:
 
 MultiLoopk: 

 CLoop:


exit:                     # this is code to terminate the program -- don't mess with this!
  addi $v0, $0, 10      	# system call code 10 for exit
  syscall               	# exit the program



#------- If you used functions, place here -------
#
#  If you do use functions, be sure to do all the proper stack management.
#
#--------------------------------------------------
