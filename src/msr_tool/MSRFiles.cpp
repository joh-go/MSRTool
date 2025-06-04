#include "msr_tool/MSRFiles.h"

#include <sstream>

namespace msr_tool {

MSRFiles::MSRFiles(const std::size_t cpus) {
  _files.resize(cpus);

  for (std::size_t i = 0; i < cpus; i++) {
    std::ostringstream ss{};
    ss << "/dev/cpu/" << i << "/msr";

    _files[i].open(ss.str(), std::ios::binary);

    if (!_files[i].is_open()) {
      std::ostringstream error_message;
      error_message << "Can't open MSR file for cpu: " << i << "!";
      throw std::runtime_error(error_message.str());
    }
  }
}

MSRFiles::~MSRFiles() {
  for (std::ifstream &file : _files) {
    file.close();
  }
}

std::uint64_t MSRFiles::ReadMsrFile(const std::size_t cpu,
                                    const std::uint32_t msr_register) {
  std::uint64_t data{0};

  if (cpu >= _files.size()) {
    return data;
  }
  return data;
}
} // namespace msr_tool