#EXP_FUNCTION
#func _ count: 0
.globl f
f:
addiu $sp, $sp, -32
sw $fp, 28($sp)
move $fp, $sp
#func _ count: 4
#CONST
li $v0, 0
sw $v0, 0($fp)
lw $t0, 0($sp)
beq $t0, $0, ENDIF2
nop
#RETURN
#CONST
li $v0, 11
sw $v0, 0($fp)
#RETURN
move $sp, $fp
lw $fp, 28($sp)
addiu $sp, $sp, 32
jr $31
nop
j ENDIF2
nop
ENDIF2: 
#RETURN
#CONST
li $v0, 10
sw $v0, 0($fp)
#RETURN
move $sp, $fp
lw $fp, 28($sp)
addiu $sp, $sp, 32
jr $31
nop
