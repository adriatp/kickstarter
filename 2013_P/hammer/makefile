all:
	g++ main.cpp -g -o run
	./run < test_data/sample_test_set_1/sample_ts1_input.txt > test_data/sample_test_set_1/results.txt
	diff test_data/sample_test_set_1/results.txt test_data/sample_test_set_1/sample_ts1_output.txt
compile:
	g++ main.cpp -g -o run
run:
	./run
