#EXP_FUNCTION
#func _ count: 0
.globl f
f:
addiu $sp, $sp, -48
sw $fp, 44($sp)
move $fp, $sp
#func _ count: 4
#EXPR_INITIALIZE NAME: y
lw $v0, 4($fp)
#ARRAY
#EXPR_ARRAY: x
lw $v0, 36($fp)
#VAR
lw $v0, 36($sp)
sw $v0, 0($sp)
#CONST
li $v0, 13
sw $v0, 0($fp)
#HEREint
#EXP_CONST
#IDEN: y
sw $v0, 4($fp)
#RETURN
#VAR
lw $v0, 4($sp)
sw $v0, 0($sp)
#RETURN
move $sp, $fp
lw $fp, 44($sp)
addiu $sp, $sp, 48
jr $31
nop
