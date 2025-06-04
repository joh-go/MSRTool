#include <cstdint>
#include <fstream>
#include <vector>

namespace msr_tool {
class MSRFiles {
public:
  explicit MSRFiles(std::size_t cpus);

  ~MSRFiles();

  std::uint64_t ReadMsrFile(std::size_t cpu, std::uint32_t msr_register);

private:
  std::vector<std::ifstream> _files;
};

} // namespace msr_tool
