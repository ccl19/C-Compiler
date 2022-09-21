#EXP_FUNCTION
#func _ count: 0
.globl g
g:
addiu $sp, $sp, -52
sw $fp, 48($sp)
sw $31, 44($sp)
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
#ADDINT
lw $v0, 8($sp)
move $t0, $v0
lw $v0, 12($sp)
nop
addu $v0, $t0, $v0
sw $v0, 0($sp)
#RETURN
move $sp, $fp
lw $fp, 48($sp)
addiu $sp, $sp, 52
jr $31
nop
#EXP_FUNCTION
#func _ count: 4
.globl f
f:
addiu $sp, $sp, -68
sw $fp, 64($sp)
sw $31, 60($sp)
move $fp, $sp
#func _ count: 8
#RETURN
#CONST
li $a0, 10
#CONST
li $a1, 20
jal g
nop
#RETURN
move $sp, $fp
lw $31, 60($sp)
lw $fp, 64($sp)
addiu $sp, $sp, 68
jr $31
nop
