#EXP_FUNCTION
#func _ count: 0
.globl f
f:
addiu $sp, $sp, -48
sw $fp, 44($sp)
sw $31, 40($sp)
move $fp, $sp
#func _ count: 4
#PARAMETERLIST
#PARAMETER
#NUM: 2
#PARAM NAME: x
#EXP_PARAMS
sw $a0, 0($fp)
#PARAMETERLIST
#PARAMETER
#NUM: 2
#PARAM NAME: y
#EXP_PARAMS
sw $a1, 4($fp)
#RETURN
#VAR
lw $v0, 0($sp)
sw $v0, 8($sp)
#VAR
lw $v0, 4($sp)
sw $v0, 12($sp)
lw $v0, 8($sp)
move $t0, $v0
lw $v0, 12($sp)
bne $t0, $0, OR1
nop
bne $v0, $0, OR1
nop
OR2: 
move $v0, $0
j OR_END3
OR1: 
li $v0, 0x1
sw $v0, 0($sp)
j OR_END3
OR_END3: 
#RETURN
move $sp, $fp
lw $fp, 44($sp)
addiu $sp, $sp, 48
jr $31
nop
