#include <gtest/gtest.h>
#include <thread>

#include "msr_tool/MSRFiles.h"

TEST(MSRFiles, Constructor) {
  const std::size_t thread_count = std::thread::hardware_concurrency();

  msr_tool::MSRFiles msr_files{thread_count};
}
