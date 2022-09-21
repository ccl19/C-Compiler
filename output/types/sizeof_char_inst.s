#EXP_FUNCTION
#func _ count: 0
.globl f
f:
addiu $sp, $sp, -40
sw $fp, 36($sp)
move $fp, $sp
#func _ count: 4
#RETURN
li $v0, 1
#RETURN
move $sp, $fp
lw $fp, 36($sp)
addiu $sp, $sp, 40
jr $31
nop
