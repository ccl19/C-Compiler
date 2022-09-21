#EXP_FUNCTION
#func _ count: 0
.globl f
f:
addiu $sp, $sp, -68
sw $fp, 64($sp)
move $fp, $sp
#func _ count: 4
#EXPR_INITIALIZE NAME: i
lw $v0, 4($fp)
#ARRAY
#EXPR_ARRAY: x
lw $v0, 36($fp)
#VAR
lw $v0, 36($sp)
sw $v0, 0($sp)
#CONST
li $v0, 0
sw $v0, 0($fp)
#HEREint
#EXP_CONST
#IDEN: i
sw $v0, 4($fp)
STARTFOR1: 
#VAR
lw $v0, 4($sp)
sw $v0, 44($sp)
#CONST
li $v0, 8
sw $v0, 48($fp)
lw $v0, 44($sp)
move $t0, $v0
lw $v0, 48($sp)
slt $v0, $t0, $v0
sw $v0, 0($sp)
beq $v0, $0, ENDFOR2
nop
#ARRAYASSIGNMENT
li $t0, 36
#VAR
lw $v0, 4($sp)
sw $v0, 0($sp)
li $t1, 4
mul $v0, $t1, $v0
add $t2, $v0, $sp
add $t3, $t0, $t2
move $v0, $t3
sw $v0, 56($fp)
#VAR
lw $v0, 4($sp)
sw $v0, 0($sp)
lw $t1, 56($fp)
sw $v0, 0($t1)
#INCREMENT
lw $v0, 4($fp)
nop
addiu $v0, $v0, 1
sw $v0, 4($fp)
j STARTFOR1
nop
ENDFOR2: 
#RETURN
#VAR
lw $v0, 36($sp)
sw $v0, 0($sp)
#RETURN
move $sp, $fp
lw $fp, 64($sp)
addiu $sp, $sp, 68
jr $31
nop
