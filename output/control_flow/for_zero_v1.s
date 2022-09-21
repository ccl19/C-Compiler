#EXP_FUNCTION
#func _ count: 0
.globl f
f:
addiu $sp, $sp, -52
sw $fp, 48($sp)
move $fp, $sp
#func _ count: 4
#EXPR_INITIALIZE NAME: x
lw $v0, 4($fp)
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
sw $v0, 12($sp)
#CONST
li $v0, 0
sw $v0, 16($fp)
lw $v0, 12($sp)
move $t0, $v0
lw $v0, 16($sp)
slt $v0, $t0, $v0
sw $v0, 0($sp)
beq $v0, $0, ENDFOR2
nop
#RETURN
#CONST
li $v0, 1
sw $v0, 0($fp)
#RETURN
move $sp, $fp
lw $fp, 48($sp)
addiu $sp, $sp, 52
jr $31
nop
#VAR
lw $v0, 4($sp)
sw $v0, 28($sp)
#CONST
li $v0, 1
sw $v0, 32($fp)
#ADDINT
lw $v0, 28($sp)
move $t0, $v0
lw $v0, 32($sp)
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
#CONST
li $v0, 19937
sw $v0, 0($fp)
#RETURN
move $sp, $fp
lw $fp, 48($sp)
addiu $sp, $sp, 52
jr $31
nop
