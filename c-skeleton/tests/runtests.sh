echo "Running Unit Tests"

for i in tests/*_tests
do
	if tests -f $i
	then
		if $VALGRIND ./$i 2>> tests/tests.log
		then
			echo $i PASS
		else
			echo "Error in test $i: here's tests/tests.log"
			echo "------------"
			tail tests/tests.log
			exit 1
		fi
	fi
done

echo ""

