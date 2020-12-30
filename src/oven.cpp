/**
 * @file oven.cpp
 * @author Pavel Skipenes (pavelgs@stud.ntnu.no)
 * @brief Heat up your cold room in the winter. Or anytime really
 * @version 0.1
 * @date 23-12-2020
 *
 * @copyright Copyright (c) 2020
 *
 */
#include <atomic>
#include <chrono>
#include <csignal>
#include <thread>
#include <vector>

#include "core_count.h"
#include "oven.h"

static std::atomic<bool> terminate_threads(false);
static void oven_thread(int load_rate, std::atomic<bool> *terminate_ptr);
static void signalHandler(int signum);

void oven(int load_rate) {
	signal(SIGINT, signalHandler);
	std::vector<std::thread> threads(get_core_count());

	for (auto &thread : threads) {
		thread = std::thread(oven_thread, load_rate, &terminate_threads);
	}

	for (auto &thread : threads) {
		thread.join();
	}
}

void signalHandler(int signum) {
	(void)signum; // suppress unused parameter warning
	terminate_threads = true;
}

void oven_thread(int load_rate, std::atomic<bool> *terminate_ptr) {
	using namespace std::chrono_literals;
	const std::chrono::milliseconds CYCLE_TIME = 100ms;

	while (!terminate_ptr->load()) {
		auto start = std::chrono::high_resolution_clock::now();
		auto now = std::chrono::high_resolution_clock::now();
		auto diff = now - start;

		while (true) {
			now = std::chrono::high_resolution_clock::now();
			diff = now - start;

			if (diff > (float)load_rate / 100 * CYCLE_TIME) {
				break;
			}
			// TODO: useless power-consuming non-memory instructions
		}
		std::this_thread::sleep_for(CYCLE_TIME - diff);
	}
}
