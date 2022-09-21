#EXP_FUNCTION
#func _ count: 0
.globl f
f:
addiu $sp, $sp, -36
sw $fp, 32($sp)
sw $31, 28($sp)
move $fp, $sp
#func _ count: 4
jal g
nop
#RETURN
move $sp, $fp
lw $31, 28($sp)
lw $fp, 32($sp)
addiu $sp, $sp, 36
jr $31
nop
