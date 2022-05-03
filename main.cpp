#include <cstdio>
#include <cstdlib>
// #include "Logging.hpp"
#include "WindowManager.hpp"

using std::unique_ptr;

int main(int argc, char** argv) {
  unique_ptr<WindowManager> wm(WindowManager::Create());
  if (!wm) {
    printf("Unable to initialize window manager\n");
    return -1;
  }

  wm->Run();

  return 0;
}
