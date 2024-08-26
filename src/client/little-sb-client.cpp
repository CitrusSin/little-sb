#include "application.h"
#include "window.h"
#include <print>
#include <spdlog/spdlog.h>

auto main(int argc, char *argv[]) -> int
{
  spdlog::set_level(spdlog::level::debug);
  Window::initialize();

  try {
    if (argc != 2) {
      std::println("Usage: little-sb-client <player-name>");
      return 0;
    }

    Application app{"localhost", 1438, argv[1]};
    app.run();
  }
  catch (std::exception &e) {
    spdlog::critical("Exception: {}", e.what());
  }

  Window::deinitialize();

  return 0;
}
