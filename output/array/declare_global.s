#ARRAY
#EXP_CONST
#EXP_FUNCTION
#func _ count: 0
.globl f
f:
addiu $sp, $sp, -36
sw $fp, 32($sp)
move $fp, $sp
#func _ count: 4
#RETURN
#CONST
li $v0, 11
sw $v0, 0($fp)
#RETURN
move $sp, $fp
lw $fp, 32($sp)
addiu $sp, $sp, 36
jr $31
nop
