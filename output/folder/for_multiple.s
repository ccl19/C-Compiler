#EXP_FUNCTION
#func _ count: 0
.globl f
f:
addiu $sp, $sp, -72
sw $fp, 68($sp)
sw $31, 64($sp)
move $fp, $sp
#func _ count: 4
#EXPR_INITIALIZE NAME: x
lw $v0, 4($fp)
#EXPR_INITIALIZE NAME: y
lw $v0, 8($fp)
#CONST
li $v0, 0
sw $v0, 0($fp)
#HEREint
#EXP_CONST
#IDEN: y
sw $v0, 8($fp)
#CONST
li $v0, 0
sw $v0, 0($fp)
#HEREint
#EXP_CONST
#IDEN: x
sw $v0, 4($fp)
STARTFOR1: 
#VAR
lw $v0, 4($sp)
sw $v0, 24($sp)
#CONST
li $v0, 10
sw $v0, 28($fp)
lw $v0, 24($sp)
move $t0, $v0
lw $v0, 28($sp)
slt $v0, $t0, $v0
sw $v0, 0($sp)
beq $v0, $0, ENDFOR2
nop
#VAR
lw $v0, 8($sp)
sw $v0, 36($sp)
#CONST
li $v0, 1
sw $v0, 40($fp)
lw $v0, 36($sp)
move $t0, $v0
lw $v0, 40($sp)
subu $v0, $t0, $v0
sw $v0, 0($sp)
#HEREint
#EXP_CONST
#IDEN: y
sw $v0, 8($fp)
#VAR
lw $v0, 4($sp)
sw $v0, 52($sp)
#CONST
li $v0, 1
sw $v0, 56($fp)
#ADDINT
lw $v0, 52($sp)
move $t0, $v0
lw $v0, 56($sp)
nop
addu $v0, $t0, $v0
sw $v0, 0($sp)
#HEREint
#EXP_CONST
#IDEN: x
sw $v0, 4($fp)
j STARTFOR1
nop
ENDFOR2: 
#RETURN
#VAR
lw $v0, 8($sp)
sw $v0, 0($sp)
#RETURN
move $sp, $fp
lw $fp, 68($sp)
addiu $sp, $sp, 72
jr $31
nop
