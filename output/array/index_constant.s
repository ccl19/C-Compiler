#EXP_FUNCTION
#func _ count: 0
.globl f
f:
addiu $sp, $sp, -44
sw $fp, 40($sp)
move $fp, $sp
#func _ count: 4
#ARRAY
#EXPR_ARRAY: x
lw $v0, 32($fp)
#VAR
#ARRAYASSIGNMENT
li $t0, 32
#CONST
li $v0, 0
sw $v0, 0($fp)
li $t1, 4
mul $v0, $t1, $v0
add $t2, $v0, $sp
add $t3, $t0, $t2
move $v0, $t3
sw $v0, 36($fp)
#CONST
li $v0, 23
sw $v0, 0($fp)
lw $t1, 36($fp)
sw $v0, 0($t1)
#RETURN
#VAR
#RETURN
move $sp, $fp
lw $fp, 40($sp)
addiu $sp, $sp, 44
jr $31
nop
