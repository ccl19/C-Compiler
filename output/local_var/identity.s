#EXP_FUNCTION
#func _ count: 0
.globl f
f:
addiu $sp, $sp, -40
sw $fp, 36($sp)
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
lw $fp, 36($sp)
addiu $sp, $sp, 40
jr $31
nop
