#EXP_FUNCTION
#func _ count: 0
.globl f
f:
addiu $sp, $sp, -40
sw $fp, 36($sp)
move $fp, $sp
#func _ count: 4
#CONST
li $v0, 12345
sw $v0, 0($fp)
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
lw $fp, 36($sp)
addiu $sp, $sp, 40
jr $31
nop
