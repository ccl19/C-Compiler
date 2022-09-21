#EXP_FUNCTION
#func _ count: 0
.globl f
f:
addiu $sp, $sp, -76
sw $fp, 72($sp)
move $fp, $sp
#func _ count: 4
#PARAMETERLIST
#PARAMETER
#NUM: 2
#PARAM NAME: x
#EXP_PARAMS
swc1 $f12, 0($fp)
#PARAMETERLIST
#PARAMETER
#NUM: 2
#PARAM NAME: n
#EXP_PARAMS
sw $a1, 4($fp)
#FLOAT
li.s $f0, 1
swc1 $f0, 0($fp)
#HEREfloat
#EXP_CONST
#IDEN: acc
swc1 $f0, 12($fp)
#CONST
li $v0, 0
sw $v0, 12($fp)
#HEREint
#EXP_CONST
#IDEN: i
sw $v0, 20($fp)
#WHILE
STARTWHILE1: 
#VAR
lw $v0, 20($sp)
sw $v0, 24($sp)
#VAR
lw $v0, 4($sp)
sw $v0, 28($sp)
lw $v0, 24($sp)
move $t0, $v0
lw $v0, 28($sp)
slt $v0, $t0, $v0
sw $v0, 32($sp)
lw $t0, 32($sp)
beq $t0, $0, ENDWHILE2
nop
#INCREMENT
lw $v0, 20($fp)
nop
addiu $v0, $v0, 1
sw $v0, 20($fp)
#VAR
lw $v0, 12($sp)
sw $v0, 40($sp)
#VAR
lw $v0, 0($sp)
sw $v0, 44($sp)
#MULINT
lw $v0, 40($sp)
move $t0, $v0
lw $v0, 44($sp)
mul $v0, $t0, $v0
sw $v0, 32($sp)
#HEREint
#EXP_CONST
#IDEN: acc
sw $v0, 12($fp)
bne $t0, $0, STARTWHILE1
nop
ENDWHILE2: 
#RETURN
#VAR
lw $v0, 12($sp)
sw $v0, 0($sp)
#RETURN
move $sp, $fp
lw $fp, 72($sp)
addiu $sp, $sp, 76
jr $31
nop
