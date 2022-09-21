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
li $v0, 5678
sw $v0, 0($fp)
#HEREint
#EXP_CONST
#IDEN: x
sw $v0, 4($fp)
#RETURN
#VAR
lw $v0, 4($sp)
sw $v0, 0($sp)
b RETURN1
nop
#RETURNNODE
RETURN1:
move $sp, $fp
lw $fp, 48($sp)
addiu $sp, $sp, 52
jr $31
nop
