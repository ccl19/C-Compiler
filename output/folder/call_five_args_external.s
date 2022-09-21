#PARAMETERLIST
#PARAMETER
#NUM: 5
#PARAM NAME: a
#EXP_PARAMS
sw $a0, 8($fp)
#PARAMETERLIST
#PARAMETER
#NUM: 5
#PARAM NAME: b
#EXP_PARAMS
sw $a1, 16($fp)
#PARAMETERLIST
#PARAMETER
#NUM: 5
#PARAM NAME: c
#EXP_PARAMS
sw $a2, 24($fp)
#PARAMETERLIST
#PARAMETER
#NUM: 5
#PARAM NAME: d
#EXP_PARAMS
sw $a3, 32($fp)
#PARAMETERLIST
#PARAMETER
#NUM: 5
#PARAM NAME: e
#EXP_PARAMS
#EXP_FUNCTION
#func _ count: 0
.globl f
f:
addiu $sp, $sp, -56
sw $fp, 52($sp)
sw $31, 48($sp)
move $fp, $sp
#func _ count: 4
#RETURN
#CONST
li $a0, 1
#CONST
li $a1, 2
#CONST
li $a2, 3
#CONST
li $a3, 4
#CONST
li $v0, 5
sw $v0, 16($sp)
jal g
nop
#RETURN
move $sp, $fp
lw $31, 48($sp)
lw $fp, 52($sp)
addiu $sp, $sp, 56
jr $31
nop
