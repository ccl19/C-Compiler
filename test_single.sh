#!/bin/bash

set -o pipefail

# HOW TO RUN
# ./test_single.sh "relative path of testcase WITHOUT .c" "name of testcase"
# EG ./test_single.sh compiler_tests/default/test_RETURN test_RETURN

# Try to find a portable way of getting rid of
# any stray carriage returns
if which dos2unix ; then
    DOS2UNIX="dos2unix"
elif which fromdos ; then
    DOS2UNIX="fromdos"
else
    >&2 echo "warning: dos2unix is not installed."
    # This should work on Linux and MacOS, it matches all the carriage returns with sed and removes
    # them.  `tr` is used instead of `sed` because some versions of `sed` don't recognize the
    # carriage return symbol.  Something similar could be implemented with `sed` if necessary or
    # worst case it could be disabled by substituting it with `cat`.  One other thing to note is
    # that there are no quotes around the \r, which is so that it gets converted by bash.
    DOS2UNIX="tr -d \r"
    # DOS2UNIX="sed -e s/\r//g"
    # DOS2UNIX="cat"
fi

echo "========================================"
echo " Cleaning the temporaries and outputs"
make clean
echo " Force building bin/c_compiler"
make bin/c_compiler -B
if [[ "$?" -ne 0 ]]; then
    echo "Build failed.";
fi
echo ""

echo "========================================="
echo "                TESTING"
echo " "

PASSED=0
CHECKED=0
f=$1



DRIVERNAME=$1_driver.c
echo "DRIVER: ${DRIVERNAME}"
TESTPATH=$1
echo "TESTPATH: ${TESTPATH}"
TEST=$2

if [[ ! -d "output/single" ]] ; then
  mkdir output/single
fi

echo ""
echo "========================================="
echo "              TEST: ${TEST}"
echo "========================================="
echo "Input : ${TEST}"

set +e
echo "Compiling ${TEST}"
bin/c_compiler -S "${TESTPATH}.c" -o "output/single/${TEST}.s" || true
echo "Assembling"
mips-linux-gnu-gcc -mfp32 -o "output/single/${TEST}.o" -c "output/single/${TEST}.s" || true
# GOT_LINE=$?
echo "Linking"
mips-linux-gnu-gcc -mfp32 -static -o "output/single/${TEST}" "output/single/${TEST}.o" "${DRIVERNAME}" || true
set -e

mips-linux-gnu-gcc -static -o "output/single/ref_${TEST}" "${TESTPATH}.c" "${DRIVERNAME}" || true

echo "Simulating Driver"
set +e
qemu-mips "output/single/ref_${TEST}"
REFRESULT=${?}
echo "Ref Result: ${REFRESULT}"
set -e

echo "Simulating Testcase"
set +e
qemu-mips "output/single/${TEST}"
RESULT=${?}
echo "Result: ${RESULT}"
set -e

if [[ ${RESULT} -eq ${REFRESULT} ]] ; then
    >&2 echo "Testcase ${TEST} passed successfully"
    PASSED=$(( ${PASSED}+1 ));
else
    >&2 echo "Testcase ${TEST} failed"
fi
CHECKED=$(( ${CHECKED}+1 ));


echo "########################################"
echo "Passed ${PASSED} out of ${CHECKED} checks".
echo ""

RELEASE=$(lsb_release -d)
if [[ $? -ne 0 ]]; then
    echo ""
    echo "Warning: This appears not to be a Linux environment"
    echo "         Make sure you do a final run on a lab machine or an Ubuntu VM"
else
    grep -q "Ubuntu 20.04" <(echo $RELEASE)
    FOUND=$?

    if [[ $FOUND -ne 0 ]]; then
        echo ""
        echo "Warning: This appears not to be the target environment"
        echo "         Make sure you do a final run on a lab machine or an Ubuntu VM"
    fi
fi
