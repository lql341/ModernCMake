#include <benchmark/benchmark.h>
#include <vector>
#include <iostream>
#include <chrono>


auto BM_test = [](benchmark::State& state, auto Inputs)
{
  for (auto _ : state) {
    benchmark::DoNotOptimize(state.iterations());
  }
    //std::cout << "Inputs = " << Inputs << std::endl;
};
#pragma once

//#include <chrono>
//#define TICK(x) auto bench_##x = std::chrono::steady_clock::now();
//#define TOCK(x) std::cout << #x ": " << std::chrono::duration_cast<std::chrono::duration<double>>(std::chrono::steady_clock::now() - bench_##x).count() << "s" << std::endl;

#include <tbb/tick_count.h>
#define TICK(x) auto bench_##x = tbb::tick_count::now();
#define TOCK(x) std::cout << #x ": " << (tbb::tick_count::now() - bench_##x).seconds() << "s" << std::endl;


int main(int argc, char** argv)
{
    //benchmark::RegisterBenchmark("BM_test", BM_test, 10);
    //benchmark::Initialize(&argc, argv);
    //benchmark::RunSpecifiedBenchmarks();
    //benchmark::Shutdown();

    {
        typedef std::chrono::high_resolution_clock Clock;
        auto then = Clock::now();
        auto now = Clock::now();

        std::cout << "virtual time taken: "
             << std::chrono::duration_cast<std::chrono::nanoseconds>(now - then).count()
             << " nanoseconds" << std::endl;
    }
    {
        auto t1 = std::chrono::high_resolution_clock::now();
        auto t2 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> ms = t2 - t1;
        std::cout << std::fixed << "std::accumulate result " << result
                  << " took " << ms.count() << " ms\n";
    }
    {
          const auto startTime = high_resolution_clock::now();
          const auto endTime = high_resolution_clock::now();
          std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count());
    }
    {
        std::cout << "waiting... " << std::flush;
        const auto start = std::chrono::system_clock::now();
        const auto diff = std::chrono::system_clock::now() - start;
        std::cout << std::chrono::duration<double>(diff).count() << " seconds\n";
    }
    {
        std::chrono::seconds s (1);             // 1 second
        std::chrono::milliseconds ms = std::chrono::duration_cast<std::chrono::milliseconds> (s);
        
        ms += std::chrono::milliseconds(2500);  // 2500 millisecond
        
        s = std::chrono::duration_cast<std::chrono::seconds> (ms);   // truncated
        
        std::cout << "ms: " << ms.count() << std::endl;
        std::cout << "s: " << s.count() << std::endl;
        
        return 0;
    }
    {
        auto t1 = std::chrono::steady_clock::now();
        auto t2 = std::chrono::steady_clock::now();
   //#define TOCK(x) std::cout << #x ": " << std::chrono::duration_cast<std::chrono::duration<double>>(std::chrono::steady_clock::now() - bench_##x).count() << "s" << std::endl;

        
        return 0;
    }	
    return 0;
}