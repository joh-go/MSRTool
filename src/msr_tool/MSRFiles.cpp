#include "msr_tool/MSRFiles.h"
#include <sstream>

namespace msr_tool {

MSRFiles::MSRFiles(const std::size_t cpus) {
  files.resize(cpus);

  for (std::size_t i = 0; i < cpus; i++) {
    std::ostringstream ss{};
    ss << "/dev/cpu/" << i << "/msr";

    files[i].open(ss.str(), std::ios::binary);

    if (!files[i].is_open()) {
      std::ostringstream error_message;
      error_message << "Can't open MSR file for cpu: " << i << "!";
      throw std::runtime_error(error_message.str());
    }
  }
}

MSRFiles::~MSRFiles() {
  for (std::ifstream &file : files) {
    file.close();
  }
}

} // namespace msr_tool