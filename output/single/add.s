#FUNCTION
.globl f
f:
addiu $sp, $sp, -36
sw $fp, 32($sp)
move $fp, $sp
#PARAMETER
#PARAMETER
#PARAMS
sw $a0, 4($sp)
#PARAMETER
#PARAMETER
#PARAMS
sw $a1, 12($sp)
#RETURN
#VAR
lw $v0, 4($fp)
sw $v0, 16($fp)
#VAR
lw $v0, 12($fp)
sw $v0, 20($fp)
lw $v0, 16($sp)
move $t0, $v0
lw $v0, 20($sp)
nop
addu $v0, $t0, $v0
sw $v0, 24($sp)
move $sp, $fp
lw $fp, 32($sp)
addiu $sp, $sp, 36
jr $31
nop
