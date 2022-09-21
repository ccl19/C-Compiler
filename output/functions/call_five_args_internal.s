#EXP_FUNCTION
#func _ count: 0
.globl g
g:
addiu $sp, $sp, -76
sw $fp, 72($sp)
sw $31, 68($sp)
move $fp, $sp
#func _ count: 4
#PARAMETERLIST
#PARAMETER
#NUM: 5
#PARAM NAME: a
#EXP_PARAMS
sw $a0, 0($fp)
#PARAMETERLIST
#PARAMETER
#NUM: 5
#PARAM NAME: b
#EXP_PARAMS
sw $a1, 4($fp)
#PARAMETERLIST
#PARAMETER
#NUM: 5
#PARAM NAME: c
#EXP_PARAMS
sw $a2, 8($fp)
#PARAMETERLIST
#PARAMETER
#NUM: 5
#PARAM NAME: d
#EXP_PARAMS
sw $a3, 12($fp)
#PARAMETERLIST
#PARAMETER
#NUM: 5
#PARAM NAME: e
#EXP_PARAMS
#RETURN
#VAR
lw $v0, 0($sp)
sw $v0, 44($sp)
#VAR
lw $v0, 4($sp)
sw $v0, 48($sp)
#ADDINT
lw $v0, 44($sp)
move $t0, $v0
lw $v0, 48($sp)
nop
addu $v0, $t0, $v0
sw $v0, 36($sp)
#VAR
lw $v0, 8($sp)
sw $v0, 40($sp)
#ADDINT
lw $v0, 36($sp)
move $t0, $v0
lw $v0, 40($sp)
nop
addu $v0, $t0, $v0
sw $v0, 28($sp)
#VAR
lw $v0, 12($sp)
sw $v0, 32($sp)
#ADDINT
lw $v0, 28($sp)
move $t0, $v0
lw $v0, 32($sp)
nop
addu $v0, $t0, $v0
sw $v0, 20($sp)
#VAR
lw $v0, 16($sp)
sw $v0, 24($sp)
#ADDINT
lw $v0, 20($sp)
move $t0, $v0
lw $v0, 24($sp)
nop
addu $v0, $t0, $v0
sw $v0, 0($sp)
#RETURN
move $sp, $fp
lw $fp, 72($sp)
addiu $sp, $sp, 76
jr $31
nop
#EXP_FUNCTION
#func _ count: 4
.globl f
f:
addiu $sp, $sp, -92
sw $fp, 88($sp)
sw $31, 84($sp)
move $fp, $sp
#func _ count: 8
#RETURN
#CONST
li $a0, 1
#CONST
li $a1, 2
#CONST
li $a2, 3
#CONST
li $a3, 4
#CONST
li $v0, 5
sw $v0, 16($sp)
jal g
nop
#RETURN
move $sp, $fp
lw $31, 84($sp)
lw $fp, 88($sp)
addiu $sp, $sp, 92
jr $31
nop
