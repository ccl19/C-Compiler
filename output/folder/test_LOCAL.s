#EXP_FUNCTION
#func _ count: 0
.globl ffff
ffff:
addiu $sp, $sp, -44
sw $fp, 40($sp)
sw $31, 36($sp)
move $fp, $sp
#func _ count: 4
#EXPR_INITIALIZE NAME: x
lw $v0, 4($fp)
#CONST
li $v0, 10
sw $v0, 0($fp)
#HEREint
#EXP_CONST
#IDEN: x
sw $v0, 4($fp)
#VAR
lw $v0, 4($sp)
sw $v0, 0($sp)
#RETURN
move $sp, $fp
lw $fp, 40($sp)
addiu $sp, $sp, 44
jr $31
nop
