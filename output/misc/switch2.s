#EXP_FUNCTION
#func _ count: 0
.globl g
g:
addiu $sp, $sp, -76
sw $fp, 72($sp)
move $fp, $sp
#func _ count: 4
#PARAMETERLIST
#PARAMETER
#NUM: 1
#PARAM NAME: t
#EXP_PARAMS
sw $a0, 0($fp)
#EXPR_INITIALIZE NAME: x
lw $v0, 8($fp)
#CONST
li $v0, 0
sw $v0, 4($fp)
#HEREint
#EXP_CONST
#IDEN: x
sw $v0, 8($fp)
#CASESTART
lw $t0, 0($fp)
###OFFSET0
#CONST
li $v0, 0
beq $t0, $v0, CASE1
nop
bne $t0, $v0, CASENOT2
nop
CASE1:
#CONST
li $v0, 1
sw $v0, 16($fp)
#HEREint
#EXP_CONST
#IDEN: x
sw $v0, 8($fp)
#BREAK
b DEFAULT1
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
#CONST
li $v0, 2
sw $v0, 28($fp)
#HEREint
#EXP_CONST
#IDEN: x
sw $v0, 8($fp)
CASENOT4:
#CASESTART
lw $t0, 0($fp)
###OFFSET0
#CONST
li $v0, 1
beq $t0, $v0, CASE5
nop
bne $t0, $v0, CASENOT6
nop
CASE5:
#VAR
lw $v0, 8($sp)
sw $v0, 44($sp)
#CONST
li $v0, 1
sw $v0, 48($fp)
#ADDINT
lw $v0, 44($sp)
move $t0, $v0
lw $v0, 48($sp)
nop
addu $v0, $t0, $v0
sw $v0, 0($sp)
#HEREint
#EXP_CONST
#IDEN: x
sw $v0, 8($fp)
#BREAK
b DEFAULT1
nop
CASENOT6:
#DEFAULT
#VAR
lw $v0, 0($sp)
sw $v0, 60($sp)
#CONST
li $v0, 1
sw $v0, 64($fp)
#ADDINT
lw $v0, 60($sp)
move $t0, $v0
lw $v0, 64($sp)
nop
addu $v0, $t0, $v0
sw $v0, 0($sp)
#HEREint
#EXP_CONST
#IDEN: x
sw $v0, 8($fp)
DEFAULT1:
#RETURN
#VAR
lw $v0, 8($sp)
sw $v0, 0($sp)
#RETURN
move $sp, $fp
lw $fp, 72($sp)
addiu $sp, $sp, 76
jr $31
nop
