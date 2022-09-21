#EXP_FUNCTION
#func _ count: 0
.globl g
g:
addiu $sp, $sp, -36
sw $fp, 32($sp)
sw $31, 28($sp)
move $fp, $sp
#func _ count: 4
#RETURN
#CONST
li $v0, 20
sw $v0, 0($fp)
#RETURN
move $sp, $fp
lw $fp, 32($sp)
addiu $sp, $sp, 36
jr $31
nop
#EXP_FUNCTION
#func _ count: 4
.globl f
f:
addiu $sp, $sp, -52
sw $fp, 48($sp)
sw $31, 44($sp)
move $fp, $sp
#func _ count: 8
#RETURN
jal g
nop
#RETURN
move $sp, $fp
lw $31, 44($sp)
lw $fp, 48($sp)
addiu $sp, $sp, 52
jr $31
nop
