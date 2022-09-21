#!/bin/bash

set -o pipefail

# HOW TO RUN
# ./test_all.sh

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

if [[ ! -d "output" ]] ; then
  mkdir output
fi

for DIRECT in compiler_tests/*; do
    DIR=${DIRECT:15}
    if [[ ! -d output/${DIR} ]] ; then
        mkdir output/${DIR}
    fi
    for FILE in compiler_tests/${DIR}/*_driver.c; do
        
        DRIVERNAME=$(basename $FILE)
        echo "DRIVER: ${DRIVERNAME}"
        TEST=${DRIVERNAME%_*}
        echo ""
        echo "========================================="
        echo "             TEST: ${TEST}"
        echo "========================================="
        echo "Input : ${TEST}"

    set +e
        echo "Compiling ${DIR}/${TEST}"
        bin/c_compiler -S "compiler_tests/${DIR}/${TEST}.c" -o "output/${DIR}/${TEST}.s" || true
        
        echo "Assembling"
        mips-linux-gnu-gcc -mfp32 -o "output/${DIR}/${TEST}.o" -c "output/${DIR}/${TEST}.s" || true

        echo "Linking"
        mips-linux-gnu-gcc -mfp32 -static -o "output/${DIR}/${TEST}" "output/${DIR}/${TEST}.o" "compiler_tests/${DIR}/${DRIVERNAME}" || true
        set -e

        mips-linux-gnu-gcc -static -o "output/${DIR}/ref_${TEST}" "compiler_tests/${DIR}/${TEST}.c" "compiler_tests/${DIR}/${DRIVERNAME}" || true

        echo "Simulating"
        set +e
        qemu-mips "output/${DIR}/ref_${TEST}"
        REFRESULT=${?}
        set -e

        echo "Simulating"
        set +e
        qemu-mips "output/${DIR}/${TEST}"
        RESULT=${?}
        set -e

        if [[ ${RESULT} -eq ${REFRESULT} ]] ; then
        >&2 echo "Testcase ${TEST} passed successfully"
        PASSED=$(( ${PASSED}+1 ));
        else
        >&2 echo "Testcase ${TEST} failed"
        fi
        CHECKED=$(( ${CHECKED}+1 ));
        # "${GOT_LINE}" >> output/$1/${TEST}.txt

    done
done


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
