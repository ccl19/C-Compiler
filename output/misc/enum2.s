#CREATE ENUM:X
#CONST
#HEREint
#EXP_CONST
#IDEN: vv
#CONST
#HEREint
#EXP_CONST
#IDEN: yy
#EXP_FUNCTION
#func _ count: 0
.globl g
g:
addiu $sp, $sp, -48
sw $fp, 44($sp)
move $fp, $sp
#func _ count: 4
li $v0, 13
sw $v0, 0($fp)
sw $v0, 4($fp)
li $v0, 10
sw $v0, 0($fp)
sw $v0, 12($fp)
#RETURN
#VAR
lw $v0, 4($sp)
sw $v0, 0($sp)
#VAR
lw $v0, 12($sp)
sw $v0, 4($sp)
#ADDINT
lw $v0, 0($sp)
move $t0, $v0
lw $v0, 4($sp)
nop
addu $v0, $t0, $v0
sw $v0, 0($sp)
#RETURN
move $sp, $fp
lw $fp, 44($sp)
addiu $sp, $sp, 48
jr $31
nop
