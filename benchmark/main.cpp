#include <benchmark/benchmark.h>

#include "dlm/matrix2x2.hpp"

static void BM_MatrixAddNoLoops(benchmark::State& state) {
  dlm::matrix::Matrix2x2F m1;
  dlm::matrix::Matrix2x2F m2;

  for (auto _ : state) {
    m1 + m2;
  }
}
// Register the function as a benchmark
BENCHMARK(BM_MatrixAddNoLoops);

// Define another benchmark
static void BM_MatrixAddWithLoops(benchmark::State& state) {
  dlm::matrix::Matrix2x2F m1;
  dlm::matrix::Matrix2x2F m2;

  for (auto _ : state) {
    m1.AddLoop(m2);
  }
}
BENCHMARK(BM_MatrixAddWithLoops);

BENCHMARK_MAIN();
