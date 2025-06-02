#include <fstream>
#include <vector>

namespace msr_tool {
class MSRFiles {
public:
  explicit MSRFiles(std::size_t cpus);

  ~MSRFiles();

private:
  std::vector<std::ifstream> files;
};

} // namespace msr_tool
