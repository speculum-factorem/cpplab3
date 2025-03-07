buildTask1: task.cpp
	g++ task.cpp -o task

runTask1: task
	./task