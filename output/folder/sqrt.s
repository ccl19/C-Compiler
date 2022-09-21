#EXP_FUNCTION
#func _ count: 0
.globl bsqrt
bsqrt:
addiu $sp, $sp, -120
sw $fp, 116($sp)
move $fp, $sp
#func _ count: 4
#PARAMETERLIST
#PARAMETER
#NUM: 3
#EXP_PARAMS
sw $a0, 0($sp)
#PARAMETERLIST
#PARAMETER
#NUM: 3
#EXP_PARAMS
sw $a1, 4($sp)
#PARAMETERLIST
#PARAMETER
#NUM: 3
#EXP_PARAMS
sw $a2, 8($sp)
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
bne $t0, $0, STARTWHILE1
nop
ENDWHILE2: 
#VAR
lw $v0, 0($sp)
sw $v0, 36($sp)
#VAR
lw $v0, 0($sp)
sw $v0, 40($sp)
#MULINT
lw $v0, 36($sp)
move $t0, $v0
lw $v0, 40($sp)
mul $v0, $t0, $v0
sw $v0, 28($sp)
#VAR
lw $v0, 8($sp)
sw $v0, 32($sp)
lw $v0, 28($sp)
move $t0, $v0
lw $v0, 32($sp)
slt $v0, $t0, $v0
sw $v0, 0($sp)
lw $t0, 0($sp)
beq $t0, $0, ELSE3
nop
#RETURN
#VAR
lw $v0, 4($sp)
sw $v0, 0($sp)
move $sp, $fp
lw $fp, 116($sp)
addiu $sp, $sp, 120
jr $31
nop
j ENDIF4
nop
ELSE3: 
#RETURN
#VAR
lw $v0, 0($sp)
sw $v0, 0($sp)
move $sp, $fp
lw $fp, 116($sp)
addiu $sp, $sp, 120
jr $31
nop
nop
ENDIF4: 
