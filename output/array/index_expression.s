#EXP_FUNCTION
#func _ count: 0
.globl f
f:
addiu $sp, $sp, -104
sw $fp, 100($sp)
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
#EXPR_INITIALIZE NAME: acc
lw $v0, 40($fp)
#CONST
li $v0, 8
sw $v0, 0($fp)
#HEREint
#EXP_CONST
#IDEN: i
sw $v0, 4($fp)
STARTFOR1: 
#VAR
lw $v0, 4($sp)
sw $v0, 48($sp)
#CONST
li $v0, 16
sw $v0, 52($fp)
lw $v0, 48($sp)
move $t0, $v0
lw $v0, 52($sp)
slt $v0, $t0, $v0
sw $v0, 0($sp)
beq $v0, $0, ENDFOR2
nop
#ARRAYASSIGNMENT
li $t0, 36
#VAR
lw $v0, 4($sp)
sw $v0, 60($sp)
#CONST
li $v0, 8
sw $v0, 64($fp)
lw $v0, 60($sp)
move $t0, $v0
lw $v0, 64($sp)
subu $v0, $t0, $v0
sw $v0, 0($sp)
li $t1, 4
mul $v0, $t1, $v0
add $t2, $v0, $sp
add $t3, $t0, $t2
move $v0, $t3
sw $v0, 72($fp)
#VAR
lw $v0, 4($sp)
sw $v0, 0($sp)
lw $t1, 72($fp)
sw $v0, 0($t1)
#INCREMENT
lw $v0, 4($fp)
nop
addiu $v0, $v0, 1
sw $v0, 4($fp)
j STARTFOR1
nop
ENDFOR2: 
#CONST
li $v0, 0
sw $v0, 0($fp)
#HEREint
#EXP_CONST
#IDEN: acc
sw $v0, 40($fp)
#CONST
li $v0, 0
sw $v0, 0($fp)
#HEREint
#EXP_CONST
#IDEN: i
sw $v0, 4($fp)
STARTFOR3: 
#VAR
lw $v0, 4($sp)
sw $v0, 96($sp)
#CONST
li $v0, 8
sw $v0, 100($fp)
lw $v0, 96($sp)
move $t0, $v0
lw $v0, 100($sp)
slt $v0, $t0, $v0
sw $v0, 0($sp)
beq $v0, $0, ENDFOR4
nop
#VAR
lw $v0, 40($sp)
sw $v0, 108($sp)
#VAR
lw $v0, 36($sp)
sw $v0, 112($sp)
#ADDINT
lw $v0, 108($sp)
move $t0, $v0
lw $v0, 112($sp)
nop
addu $v0, $t0, $v0
sw $v0, 0($sp)
#HEREint
#EXP_CONST
#IDEN: acc
sw $v0, 40($fp)
#INCREMENT
lw $v0, 4($fp)
nop
addiu $v0, $v0, 1
sw $v0, 4($fp)
j STARTFOR3
nop
ENDFOR4: 
#RETURN
#VAR
lw $v0, 40($sp)
sw $v0, 0($sp)
#RETURN
move $sp, $fp
lw $fp, 100($sp)
addiu $sp, $sp, 104
jr $31
nop
