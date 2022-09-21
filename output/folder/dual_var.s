#EXP_FUNCTION
#func _ count: 0
.globl f
f:
addiu $sp, $sp, -56
sw $fp, 52($sp)
move $fp, $sp
#func _ count: 4
#EXPR_INITIALIZE NAME: x
lw $v0, 4($fp)
#EXPR_INITIALIZE NAME: y
lw $v0, 8($fp)
#CONST
li $v0, 1234
sw $v0, 0($fp)
#HEREint
#EXP_CONST
#IDEN: x
sw $v0, 4($fp)
#VAR
lw $v0, 4($sp)
sw $v0, 0($sp)
#HEREint
#EXP_CONST
#IDEN: y
sw $v0, 8($fp)
#RETURN
#VAR
lw $v0, 8($sp)
sw $v0, 0($sp)
b RETURN1
nop
#RETURNNODE
RETURN1:
move $sp, $fp
lw $fp, 52($sp)
addiu $sp, $sp, 56
jr $31
nop
