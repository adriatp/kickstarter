all:
	g++ main.cpp -g -o run

	./run < test_data/test_set_1/ts1_input.txt > test_data/test_set_1/results.txt
	diff test_data/test_set_1/results.txt test_data/test_set_1/ts1_output.txt

	./run < test_data/test_set_2/ts2_input.txt > test_data/test_set_2/results.txt
	diff test_data/test_set_2/results.txt test_data/test_set_2/ts2_output.txt
