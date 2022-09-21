#FUNCTION
.globl f
f:
addiu $sp, $sp, -20
sw $fp, 16($sp)
move $fp, $sp
#RETURN
li $v0, 10
sw $v0, 0($fp)
move $sp, $fp
lw $fp, 16($sp)
addiu $sp, $sp, 20
jr $31
nop
