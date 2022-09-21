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
#EXP_PARAMS
swc1 $f12, 0($fp)
#PARAMETERLIST
#PARAMETER
#NUM: 2
#EXP_PARAMS
sw $a1, 4($fp)
#FLOAT
#EXP_CONST
sw $v0, 8($fp)
#CONST
li $v0, 0
sw $v0, 0($fp)
#EXP_CONST
sw $v0, 12($fp)
#WHILE
STARTWHILE1: 
#VAR
lw $v0, 12($sp)
sw $v0, 16($sp)
#VAR
lw $v0, 4($sp)
sw $v0, 20($sp)
lw $v0, 16($sp)
move $t0, $v0
lw $v0, 20($sp)
slt $v0, $t0, $v0
sw $v0, 0($sp)
lw $t0, 0($sp)
beq $t0, $0, ENDWHILE2
nop
#INCREMENT
lw $v0, 12($sp)
nop
addiu $v0, $v0, 1
sw $v0, 12($sp)
#VAR
lw $v0, 8($sp)
sw $v0, 32($sp)
#VAR
lw $v0, 0($sp)
sw $v0, 36($sp)
#MULINT
lw $v0, 32($sp)
move $t0, $v0
lw $v0, 36($sp)
mul $v0, $t0, $v0
sw $v0, 0($sp)
#EXP_CONST
sw $v0, 8($fp)
bne $t0, $0, STARTWHILE1
nop
ENDWHILE2: 
#RETURN
#VAR
lw $v0, 8($sp)
sw $v0, 0($sp)
move $sp, $fp
lw $fp, 72($sp)
addiu $sp, $sp, 76
jr $31
nop
