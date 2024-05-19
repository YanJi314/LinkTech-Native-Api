#include <Windows.h>
#include <iostream>
#include <string>
#include <map>

std::map<std::string, int> keyMap = {
    {"ctrl", VK_CONTROL},
    {"shift", VK_SHIFT},
    {"alt", VK_MENU},
    {"a", 'A'},
    {"b", 'B'},
    {"c", 'C'},
    {"d", 'D'},
    {"e", 'E'},
    {"f", 'F'},
    {"g", 'G'},
    {"h", 'H'},
    {"i", 'I'},
    {"j", 'J'},
    {"k", 'K'},
    {"l", 'L'},
    {"m", 'M'},
    {"n", 'N'},
    {"o", 'O'},
    {"p", 'P'},
    {"q", 'Q'},
    {"r", 'R'},
    {"s", 'S'},
    {"t", 'T'},
    {"u", 'U'},
    {"v", 'V'},
    {"w", 'W'},
    {"x", 'X'},
    {"y", 'Y'},
    {"z", 'Z'},
    {"0", '0'},
    {"1", '1'},
    {"2", '2'},
    {"3", '3'},
    {"4", '4'},
    {"5", '5'},
    {"6", '6'},
    {"7", '7'},
    {"8", '8'},
    {"9", '9'},
    {"pageup", VK_PRIOR},
    {"pagedown", VK_NEXT},
    {"up", VK_UP},
    {"down", VK_DOWN},
    {"left", VK_LEFT},
    {"right", VK_RIGHT},
    {"f1", VK_F1},
    {"f2", VK_F2},
    {"f3", VK_F3},
    {"f4", VK_F4},
    {"f5", VK_F5},
    {"f6", VK_F6},
    {"f7", VK_F7},
    {"f8", VK_F8},
    {"f9", VK_F9},
    {"f10", VK_F10},
    {"f11", VK_F11},
    {"f12", VK_F12},
    {"volumeup", VK_VOLUME_UP},
    {"volumedown", VK_VOLUME_DOWN},
    {"backspace", VK_BACK},
    {"enter", VK_RETURN},
    {"tab", VK_TAB}
};

int main(int argc, char *argv[]) {
    INPUT inputs[6] = {};

    for (int i = 1; i < argc; ++i) {
        std::string key = argv[i];
        if (keyMap.find(key) != keyMap.end()) {
            inputs[i-1].type = INPUT_KEYBOARD;
            inputs[i-1].ki.wVk = keyMap[key];
        } else {
            std::cerr << "Unknown key: " << key << std::endl;
            return 1;
        }
    }

    // Press keys down
    for (int i = 0; i < argc - 1; ++i) {
        if (inputs[i].type == INPUT_KEYBOARD) {
            SendInput(1, &inputs[i], sizeof(INPUT));
        }
    }

    // Release keys
    for (int i = 0; i < argc - 1; ++i) {
        if (inputs[i].type == INPUT_KEYBOARD) {
            inputs[i].ki.dwFlags = KEYEVENTF_KEYUP;
            SendInput(1, &inputs[i], sizeof(INPUT));
        }
    }

    return 0;
}




// g++ -o keySimulator.exe keySimulator.cpp -luser32 -std=c++11
