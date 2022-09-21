#PARAMETERLIST
#PARAMETER
#NUM: 1
#PARAM NAME: x
#EXP_PARAMS
sw $a0, 8($fp)
#EXP_FUNCTION
#func _ count: 0
.globl f
f:
addiu $sp, $sp, -40
sw $fp, 36($sp)
sw $31, 32($sp)
move $fp, $sp
#func _ count: 4
#RETURN
#CONST
li $a0, 10
jal g
nop
#RETURN
move $sp, $fp
lw $31, 32($sp)
lw $fp, 36($sp)
addiu $sp, $sp, 40
jr $31
nop
