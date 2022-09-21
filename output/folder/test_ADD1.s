#EXP_FUNCTION
#func _ count: 0
.globl f
f:
addiu $sp, $sp, -40
sw $fp, 36($sp)
move $fp, $sp
#func _ count: 4
#PARAMETERLIST
#PARAMETER
#NUM: 1
#EXP_PARAMS
sw $a0, 0($fp)
#VAR
lw $v0, 0($sp)
sw $v0, 4($sp)
#CONST
li $v0, 10
sw $v0, 8($fp)
#ADDINT
lw $v0, 4($sp)
move $t0, $v0
lw $v0, 8($sp)
nop
addu $v0, $t0, $v0
sw $v0, 0($sp)
#RETURN
move $sp, $fp
lw $fp, 36($sp)
addiu $sp, $sp, 40
jr $31
nop
