#EXP_FUNCTION
#func _ count: 0
.globl f
f:
addiu $sp, $sp, -60
sw $fp, 56($sp)
sw $31, 52($sp)
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
#EXPR_INITIALIZE NAME: z
lw $v0, 12($fp)
#VAR
lw $v0, 0($sp)
sw $v0, 12($sp)
#VAR
lw $v0, 4($sp)
sw $v0, 16($sp)
lw $v0, 12($sp)
move $t0, $v0
lw $v0, 16($sp)
slt $v0, $t0, $v0
beq $t0, $v0, EQUAL1
j LESSEND2
EQUAL1: 
li $v0, 0x1
LESSEND2: 
sw $v0, 0($sp)
#HEREint
#EXP_CONST
#IDEN: z
sw $v0, 12($fp)
#RETURN
#VAR
lw $v0, 12($sp)
sw $v0, 0($sp)
#RETURN
move $sp, $fp
lw $fp, 56($sp)
addiu $sp, $sp, 60
jr $31
nop
