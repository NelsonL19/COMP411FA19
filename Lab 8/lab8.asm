# =============================================================
# main PROCEDURE TEMPLATE # 5a
#
# Use with "proc_template.asm" as the template for other procedures
#
# Based on Slide 38 of Procedures and Stack lectures
#   (main is simpler than other procedures because it does not have to
#     clean up anything before exiting)
#
# Assumptions:
#
#   - main calls other procedures with no more than 4 arguments ($a0-$a3)
#   - any local variables needed are put into registers (not memory)
#
# =============================================================



#
# declare global variables here
.data
nPrompt: .asciiz "Enter the number of Bits (N): "



main:


                                # The first value on stack will actually go at 0x2ffc
                                #   because $sp is decremented first.
    addi    $fp, $sp, -4        # Set $fp to the start of main's stack frame



    # =============================================================
    # Create room for temporaries to be protected.
    # Delete this part is no temporaries need to be protected.
    # Example:  if 2 temporary registers need to be saved:

    addi    $sp, $sp, -8        # Make room on stack for saving any of the following registers
                                #   whose values are precious, and must survive a
                                #   procedure call from main to another procedure (e.g., proc1).
                                # These registers are $t0-$t9, $a0-$a3, and $v0-$v1.
                                # We do not save their values yet; values are saved right
                                #   before calling the other procedure, and restored upon return.
                                # See below for example.

                                # For example, say we need to protect $t0 and $t1
                                #   during a call to proc1.  So, we allocate 2 words on stack.
                                # From now on:
                                #    0($fp) --> $t0's saved value
                                #   -4($fp) --> $11's saved value
    # =============================================================
  addi 	$v0, $0, 4  			# system call 4 is for printing a string
  la 	$a0, nPrompt 			# address of nPrompt is in $a0
  syscall 



    # =============================================================
    # BODY OF main
    # ...
    # ...
    # ...
    # ... CODE FOR main HERE
        
            # =====================================================
            # main CALLS proc1
            #
            # Suppose main needs to call proc1, and protect 
            #   $t0 and $t1 during this call.
            #
            # Suppose there are four arguments to send to proc1:
            #   (0, 10, 20, 30).  Here's how to do it.
            #
            # The same technique applies to protecting any of
            #   $t0-$t9, $a0-$a3, and $v0-$v1.

            sw      $t0, 0($fp)     # Save $t0
            sw      $t1, -4($fp)    # Save $t1
            
            ori     $a0, $0,  0     # Put  0 in $a0
            ori     $a1, $0, 10     # Put 10 in $a1
            ori     $a2, $0, 20     # Put 20 in $a2
            ori     $a3, $0, 30     # Put 30 in $a3

            jal     proc1           # call proc1
                                    # valued returned by proc1 will be in $v0-$v1

            lw      $t0, 0($fp)     # Restore $t0
            lw      $t1, -4($fp)    # Restore $t1

            # =====================================================
            

    # ... MORE CODE FOR main HERE
    # ...
    # ...
    # END OF BODY OF main
    # =============================================================

#===================================================================

proc1: 



















addi    $sp, $fp, 4     # Restore $sp
lw      $ra, 0($fp)     # Restore $ra
lw      $fp, -4($fp) 

jr      $ra

#===================================================================

exit_from_main:
    ori     $v0, $0, 10     # System call code 10 for exit
    syscall                 # Exit the program
end_of_main:
