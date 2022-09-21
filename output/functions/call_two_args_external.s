#PARAMETERLIST
#PARAMETER
#NUM: 2
#PARAM NAME: x
#EXP_PARAMS
sw $a0, 8($fp)
#PARAMETERLIST
#PARAMETER
#NUM: 2
#PARAM NAME: y
#EXP_PARAMS
sw $a1, 16($fp)
#EXP_FUNCTION
#func _ count: 0
.globl f
f:
addiu $sp, $sp, -44
sw $fp, 40($sp)
sw $31, 36($sp)
move $fp, $sp
#func _ count: 4
#RETURN
#CONST
li $a0, 10
#CONST
li $a1, 20
jal g
nop
#RETURN
move $sp, $fp
lw $31, 36($sp)
lw $fp, 40($sp)
addiu $sp, $sp, 44
jr $31
nop
