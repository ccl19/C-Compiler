#EXP_FUNCTION
#func _ count: 0
.globl f
f:
addiu $sp, $sp, -48
sw $fp, 44($sp)
move $fp, $sp
#func _ count: 4
#EXPR_INITIALIZE NAME: x
lw $v0, 4($fp)
#CONST
li $v0, 1
sw $v0, 0($fp)
#HEREint
#EXP_CONST
#IDEN: x
sw $v0, 4($fp)
#WHILE
STARTWHILE1: 
#VAR
lw $v0, 4($sp)
sw $v0, 20($sp)
lw $t0, 20($sp)
beq $t0, $0, ENDWHILE2
nop
#CONST
li $v0, 0
sw $v0, 20($fp)
#HEREint
#EXP_CONST
#IDEN: x
sw $v0, 4($fp)
bne $t0, $0, STARTWHILE1
nop
ENDWHILE2: 
#RETURN
#CONST
li $v0, 19937
sw $v0, 0($fp)
#RETURN
move $sp, $fp
lw $fp, 44($sp)
addiu $sp, $sp, 48
jr $31
nop
