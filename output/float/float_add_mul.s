#EXP_FUNCTION
#func _ count: 0
.globl f
f:
addiu $sp, $sp, -56
sw $fp, 52($sp)
move $fp, $sp
#func _ count: 4
#PARAMETERLIST
#PARAMETER
#NUM: 3
#EXP_PARAMS
swc1 $f12, 0($fp)
#PARAMETERLIST
#PARAMETER
#NUM: 3
#EXP_PARAMS
swc1 $f14, 4($fp)
#PARAMETERLIST
#PARAMETER
#NUM: 3
#EXP_PARAMS
sw $a2, 8($fp)
#RETURN
#VAR
lwc1 $f0, 0($sp)
swc1 $f0, 12($sp)
#VAR
lwc1 $f0, 4($sp)
swc1 $f0, 20($sp)
#VAR
lwc1 $f0, 8($sp)
swc1 $f0, 24($sp)
#MULFLOAT
lwc1 $f2, 20($sp)
lwc1 $f0, 24($sp)
mul.s $f0, $f2, $f0
swc1 $f0, 16($sp)
#ADDFLOAT
lwc1 $f0, 12($sp)
lwc1 $f2, 16($sp)
nop
add.s $f0, $f0, $f2
swc1 $f0, 0($sp)
move $sp, $fp
lw $fp, 52($sp)
addiu $sp, $sp, 56
jr $31
nop
