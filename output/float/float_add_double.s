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
#des: 0
sdc1 $f12, 0($fp)
#PARAMETERLIST
#PARAMETER
#NUM: 2
#EXP_PARAMS
#des: 8
sdc1 $f14, 8($fp)
#RETURN
#VAR
ldc1 $f0, 0($sp)
sdc1 $f0, 16($sp)
#VAR
ldc1 $f0, 8($sp)
sdc1 $f0, 24($sp)
#ADDDOUBLE
ldc1 $f0, 16($sp)
ldc1 $f2, 24($sp)
add.d $f0, $f2, $f0
sdc1 $f0, 0($sp)
move $sp, $fp
lw $fp, 44($sp)
addiu $sp, $sp, 48
jr $31
nop
