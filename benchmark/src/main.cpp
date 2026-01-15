#include <chrono>
#include <print>
#include <iostream>

int main(int argc, char** argv)
{
	const auto timeStart = std::chrono::high_resolution_clock::now();



	const auto timeEnd = std::chrono::high_resolution_clock::now();

	auto time = std::chrono::duration_cast<std::chrono::nanoseconds>(timeEnd - timeStart).count();
	std::print("{}ns\n", time);

	return 0;
}
