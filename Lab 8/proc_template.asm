# =============================================================
# PROCEDURE WRITING TEMPLATE # 5a
#
# Based on Slide 38 of Procedures and Stacks lecture
#   (slightly more expanded version than the one in the lecture)
#
# Assumptions:
#
#   - this procedure calls other procedures with no more than 4 arguments ($a0-$a3)
#   - any local variables needed are put into registers (not memory)
#
# Write the code for the body of this procedure first,
#   without worrying much about saving/restoring values
#   on/from the stack.
#
# Which registers out of $s0-$s7 does this procedure modify?
#   It needs to save those at the beginning and restore them
#   at the end.
#
# Which registers out of $t0-$t9, $a0-$a3, and $v0-$v1 must
#   be protected from a call to a callee?  It needs to save
#   those right before the call, and restore right after.
#
# =============================================================



.text
.globl proc1                    # Simply means proc1 can be found by code residing in other files

proc1:
    addi    $sp, $sp, -8        # Make room on stack for saving $ra and $fp
    sw      $ra, 4($sp)         # Save $ra
    sw      $fp, 0($sp)         # Save $fp

    addi    $fp, $sp, 4         # Set $fp to the start of proc1's stack frame

                                # From now on:
                                #     0($fp) --> $ra's saved value
                                #    -4($fp) --> caller's $fp's saved value
                    

    # =============================================================
    # Save any $sx registers that proc1 will modify
                                # Save any of the $sx registers that proc1 modifies
    addi    $sp, $sp, -16       # e.g., $s0, $s1, $s2, $s3
    sw      $s0, 12($sp)        # Save $s0
    sw      $s1, 8($sp)         # Save $s1
    sw      $s2, 4($sp)         # Save $s2
    sw      $s3, 0($sp)         # Save $s3

                                # From now on:
                                #    -8($fp) --> $s0's saved value
                                #   -12($fp) --> $s1's saved value
                                #   -16($fp) --> $s2's saved value
                                #   -20($fp) --> $s3's saved value
    # =============================================================



    # =============================================================
    # Create room for temporaries to be protected
    addi    $sp, $sp, -8        # Make room on stack for saving any of the following registers
                                #   whose values are precious, and must survive a
                                #   procedure call from proc1 to another procedure (e.g., proc2).
                                # These registers are $t0-$t9, $a0-$a3, and $v0-$v1.
                                # We do not save their values yet; values are saved right
                                #   before calling the other procedure, and restore upon return.

                                # For example, say we need to protect $t0 and $t1
                                #   during a call to proc2.  So, we allocate 2 words on stack.
                                # From now on:
                                #   -24($fp) --> $t0's saved value
                                #   -28($fp) --> $t1's saved value
    # =============================================================





    # =============================================================
    # BODY OF proc1
    # ...
    # ...

            # =====================================================
            # proc1 CALLS proc2
            #
            # Suppose proc1 needs to call proc2, and protect 
            #   $t0 and $t1 during this call.
            #
            # Suppose there are four arguments to send to proc2:
            #   (0,10,20,30).  Here's how to do it.
            #
            # The same technique applies to protecting any of
            #   $t0-$t9, $a0-$a3, and $v0-$v1.

            sw  $t0, -24($fp)           # Save $t0
            sw  $t1, -28($fp)           # Save $t1
            
            ori $a0, $0,  0             # Put  0 in $a0
            ori $a1, $0, 10             # Put 10 in $a1
            ori $a2, $0, 20             # Put 20 in $a2
            ori $a3, $0, 30             # Put 30 in $a3

            jal proc2

            lw  $t0, -24($fp)           # Restore $t0
            lw  $t1, -28($fp)           # Restore $t1

            # =====================================================

    # ...
    # ...
    # put return values, if any, in $v0-$v1
    # END OF BODY OF proc1
    # =============================================================



    # =============================================================
    # Restore $sx registers
    lw  $s0,  -8($fp)           # Restore $s0
    lw  $s1, -12($fp)           # Restore $s1
    lw  $s2, -16($fp)           # Restore $s2
    lw  $s3, -20($fp)           # Restore $s3
    # =============================================================



    # =============================================================
    # Restore $fp, $ra, and shrink stack back to how we found it,
    #   and return to caller.

return_from_proc1:
    addi    $sp, $fp, 4     # Restore $sp
    lw      $ra, 0($fp)     # Restore $ra
    lw      $fp, -4($fp)    # Restore $fp
    jr      $ra             # Return from procedure

    # =============================================================


end_of_proc1: