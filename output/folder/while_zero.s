#EXP_FUNCTION
#func _ count: 0
.globl f
f:
addiu $sp, $sp, -32
sw $fp, 28($sp)
sw $31, 24($sp)
move $fp, $sp
#func _ count: 4
#WHILE
STARTWHILE1: 
#CONST
li $v0, 0
sw $v0, 8($fp)
lw $t0, 8($sp)
beq $t0, $0, ENDWHILE2
nop
bne $t0, $0, STARTWHILE1
nop
ENDWHILE2: 
#RETURN
#CONST
li $v0, 19937
sw $v0, 0($fp)
#RETURN
move $sp, $fp
lw $fp, 28($sp)
addiu $sp, $sp, 32
jr $31
nop
