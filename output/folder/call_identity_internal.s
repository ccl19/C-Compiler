#EXP_FUNCTION
#func _ count: 0
.globl g
g:
addiu $sp, $sp, -44
sw $fp, 40($sp)
move $fp, $sp
#func _ count: 4
#PARAMETERLIST
#PARAMETER
#NUM: 1
#PARAM NAME: x
#EXP_PARAMS
sw $a0, 0($fp)
#RETURN
#VAR
lw $v0, 0($sp)
sw $v0, 0($sp)
#RETURN
move $sp, $fp
lw $fp, 40($sp)
addiu $sp, $sp, 44
jr $31
nop
#EXP_FUNCTION
#func _ count: 4
.globl f
f:
addiu $sp, $sp, -60
sw $fp, 56($sp)
sw $31, 52($sp)
move $fp, $sp
#func _ count: 8
#RETURN
#CONST
li $a0, 10
jal g
nop
#RETURN
move $sp, $fp
lw $31, 52($sp)
lw $fp, 56($sp)
addiu $sp, $sp, 60
jr $31
nop
