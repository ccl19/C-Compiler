#EXP_FUNCTION
#func _ count: 0
.globl g
g:
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
#CASESTART
lw $t0, 0($fp)
###OFFSET0
#CONST
li $v0, 1
beq $t0, $v0, CASE1
nop
bne $t0, $v0, CASENOT2
nop
CASE1:
#RETURN
#CONST
li $v0, 10
sw $v0, 4($fp)
#RETURN
move $sp, $fp
lw $fp, 36($sp)
addiu $sp, $sp, 40
jr $31
nop
CASENOT2:
#CASESTART
lw $t0, 0($fp)
###OFFSET0
#CONST
li $v0, 2
beq $t0, $v0, CASE3
nop
bne $t0, $v0, CASENOT4
nop
CASE3:
#RETURN
#CONST
li $v0, 11
sw $v0, 12($fp)
#RETURN
move $sp, $fp
lw $fp, 36($sp)
addiu $sp, $sp, 40
jr $31
nop
CASENOT4:
