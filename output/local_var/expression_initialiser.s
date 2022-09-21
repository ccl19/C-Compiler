#EXP_FUNCTION
#func _ count: 0
.globl f
f:
addiu $sp, $sp, -48
sw $fp, 44($sp)
move $fp, $sp
#func _ count: 4
#CONST
li $v0, 10
sw $v0, 0($fp)
#HEREint
#EXP_CONST
#IDEN: y
sw $v0, 4($fp)
#CONST
li $v0, 20
sw $v0, 8($fp)
#VAR
lw $v0, 4($sp)
sw $v0, 12($sp)
#ADDINT
lw $v0, 8($sp)
move $t0, $v0
lw $v0, 12($sp)
nop
addu $v0, $t0, $v0
sw $v0, 0($sp)
#HEREint
#EXP_CONST
#IDEN: x
sw $v0, 20($fp)
#RETURN
#VAR
lw $v0, 20($sp)
sw $v0, 0($sp)
#RETURN
move $sp, $fp
lw $fp, 44($sp)
addiu $sp, $sp, 48
jr $31
nop
