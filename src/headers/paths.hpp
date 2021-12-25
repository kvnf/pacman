#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;

//paths
fs::path PROJECT_PATH = (std::string)fs::current_path().parent_path();
fs::path SPRITES_PATH = PROJECT_PATH  / "resources" / "sprites";
