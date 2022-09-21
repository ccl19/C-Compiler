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
#CONST
li $v0, 1
sw $v0, 0($fp)
#HEREint
#EXP_CONST
#IDEN: x
sw $v0, 4($fp)
#VAR
lw $v0, 4($sp)
sw $v0, 12($sp)
#VAR
lw $v0, 4($sp)
sw $v0, 16($sp)
#ADDINT
lw $v0, 12($sp)
move $t0, $v0
lw $v0, 16($sp)
nop
addu $v0, $t0, $v0
sw $v0, 0($sp)
#HEREint
#EXP_CONST
#IDEN: x
sw $v0, 4($fp)
#RETURN
#VAR
lw $v0, 4($sp)
sw $v0, 0($sp)
#RETURN
move $sp, $fp
lw $fp, 52($sp)
addiu $sp, $sp, 56
jr $31
nop
