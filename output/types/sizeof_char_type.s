#EXP_FUNCTION
#func _ count: 0
.globl f
f:
addiu $sp, $sp, -32
sw $fp, 28($sp)
move $fp, $sp
#func _ count: 4
#RETURN
li $v0, 1
#RETURN
move $sp, $fp
lw $fp, 28($sp)
addiu $sp, $sp, 32
jr $31
nop
