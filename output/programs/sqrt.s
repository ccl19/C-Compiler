#EXP_FUNCTION
#func _ count: 0
.globl bsqrt
bsqrt:
addiu $sp, $sp, -120
sw $fp, 116($sp)
sw $31, 112($sp)
move $fp, $sp
#func _ count: 4
#PARAMETERLIST
#PARAMETER
#NUM: 3
#PARAM NAME: lo
#EXP_PARAMS
sw $a0, 0($fp)
#PARAMETERLIST
#PARAMETER
#NUM: 3
#PARAM NAME: hi
#EXP_PARAMS
sw $a1, 4($fp)
#PARAMETERLIST
#PARAMETER
#NUM: 3
#PARAM NAME: val
#EXP_PARAMS
sw $a2, 8($fp)
#WHILE
STARTWHILE1: 
#VAR
lw $v0, 0($sp)
sw $v0, 20($sp)
#CONST
li $v0, 1
sw $v0, 24($fp)
#ADDINT
lw $v0, 20($sp)
move $t0, $v0
lw $v0, 24($sp)
nop
addu $v0, $t0, $v0
sw $v0, 12($sp)
#VAR
lw $v0, 4($sp)
sw $v0, 16($sp)
lw $v0, 12($sp)
move $t0, $v0
lw $v0, 16($sp)
slt $v0, $t0, $v0
sw $v0, 20($sp)
lw $t0, 20($sp)
beq $t0, $0, ENDWHILE2
nop
