#CREATE ENUM:X
#EXP_FUNCTION
#func _ count: 0
.globl g
g:
addiu $sp, $sp, -40
sw $fp, 36($sp)
move $fp, $sp
#func _ count: 4
#RETURN
#VAR
#CONST
li $v0, 1
sw $v0, 4($fp)
#RETURN
move $sp, $fp
lw $fp, 36($sp)
addiu $sp, $sp, 40
jr $31
nop
