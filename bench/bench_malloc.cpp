#include <benchmark/benchmark.h>
#include <cstdlib> // Includes the std::malloc and std::free

static void BM_Malloc(benchmark::State& state) {
    // Dynamic number of elements passed by Google Benchmark
    size_t bytes = state.range(0); // Via state.range(0)
    // Setup here the harness for the actual code
    for (auto _ : state) {
        // Code here gets timed & benchmarked
        void* ptr = std::malloc(bytes); // memory allocating the ptr with the size bytes
        benchmark::DoNotOptimize(ptr);
        std::free(ptr);
    }
}

// Macros are written outside the benchmarking function
BENCHMARK(BM_Malloc)->Range(8, 8<<10); // Register the function as a benchmark (8<<10 is shorthand for 1024 (since 2^10 is 1024 Bytes). The 8 in front is the limiter. In this case to 8KiB (since 8<<10 multiplies 8 * 2^10 to get 8192 Bytes) (if it was 16 then 16KiB)
BENCHMARK_MAIN();   // Running the benchmark
