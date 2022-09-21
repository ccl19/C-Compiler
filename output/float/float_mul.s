#EXP_FUNCTION
#func _ count: 0
.globl f
f:
addiu $sp, $sp, -48
sw $fp, 44($sp)
move $fp, $sp
#func _ count: 4
#PARAMETERLIST
#PARAMETER
#NUM: 2
#EXP_PARAMS
swc1 $f12, 0($fp)
#PARAMETERLIST
#PARAMETER
#NUM: 2
#EXP_PARAMS
swc1 $f14, 4($fp)
#RETURN
#VAR
lwc1 $f0, 0($sp)
swc1 $f0, 8($sp)
#VAR
lwc1 $f0, 4($sp)
swc1 $f0, 12($sp)
#MULFLOAT
lwc1 $f2, 8($sp)
lwc1 $f0, 12($sp)
mul.s $f0, $f2, $f0
swc1 $f0, 0($sp)
move $sp, $fp
lw $fp, 44($sp)
addiu $sp, $sp, 48
jr $31
nop
