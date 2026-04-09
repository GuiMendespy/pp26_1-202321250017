#include <cstdlib>

int main() {
    system("gnome-terminal -- bash -c './app; exec bash'");
    return 0;
}