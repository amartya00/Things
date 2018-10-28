#include "utils/stringutils.h"

#include <string>
#include <memory>
#include <cstdlib>

std::string SigAbrt::Utils::randomString(const unsigned long len) {
    static const char alphaNumeric[] = "01234567890ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    std::unique_ptr<char> word = std::make_unique<char>(len);
    for (unsigned long i; i < len ; i++) {
        word.get()[i] = alphaNumeric[std::rand() % sizeof(alphaNumeric)];
    }
    std::string retval {word.get()};
    return retval;
}
