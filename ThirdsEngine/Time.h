#pragma once

#include <chrono>

namespace te {

	struct Timer {
		typedef std::chrono::high_resolution_clock clock;
		typedef std::chrono::seconds seconds;
		typedef std::chrono::milliseconds millis;
		typedef std::chrono::nanoseconds nanos;

		void reset() { start = clock::now(); }

		unsigned long long seconds_elapsed() const {
			return std::chrono::duration_cast<seconds>(clock::now() - start).count();
		}

		unsigned long long millis_elapsed() const {
			return std::chrono::duration_cast<millis>(clock::now() - start).count();
		}

		unsigned long long nanos_elapsed() const {
			return std::chrono::duration_cast<nanos>(clock::now() - start).count();
		}

		void add_nanos(long long ns) {
			start += std::chrono::nanoseconds(ns);
		}

	private: clock::time_point start = clock::now();
	};
}