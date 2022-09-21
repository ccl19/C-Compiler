#EXP_FUNCTION
#func _ count: 0
.globl f
f:
addiu $sp, $sp, -40
sw $fp, 36($sp)
sw $31, 32($sp)
move $fp, $sp
#func _ count: 4
#EXPR_INITIALIZE NAME: x
lw $v0, 4($fp)
#RETURN
li $v0, 4
#RETURN
move $sp, $fp
lw $fp, 36($sp)
addiu $sp, $sp, 40
jr $31
nop
