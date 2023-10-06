#include <iostream>
#include <chrono>
#include <memory>
#include <sstream>
#include "threadworker.h"

int main()
{
	Source source(std::cin);
	Sink sink(std::cout);
	ThreadWorker worker(source, sink);
	worker.start();
	std::this_thread::sleep_for(std::chrono::seconds(5));
	worker.stop();

	return 0;
}
