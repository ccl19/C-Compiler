#EXP_FUNCTION
#func _ count: 0
.globl f
f:
addiu $sp, $sp, -48
sw $fp, 44($sp)
move $fp, $sp
#func _ count: 4
#PARAMETERLIST
#PARAMETER
#NUM: 2
#PARAM NAME: x
#EXP_PARAMS
sw $a0, 0($fp)
#PARAMETERLIST
#PARAMETER
#NUM: 2
#PARAM NAME: y
#EXP_PARAMS
sw $a1, 4($fp)
#RETURN
#VAR
lw $v0, 0($sp)
sw $v0, 8($sp)
#VAR
lw $v0, 4($sp)
sw $v0, 12($sp)
lw $v0, 8($sp)
move $t0, $v0
lw $v0, 12($sp)
slt $v0, $t0, $v0
sw $v0, 0($sp)
#RETURN
move $sp, $fp
lw $fp, 44($sp)
addiu $sp, $sp, 48
jr $31
nop
