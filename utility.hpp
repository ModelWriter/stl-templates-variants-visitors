//  ----------------------------------------------------------------------------
//  Header file for the utility classes.                             utility.hpp
//  Created by Ferhat Erata <ferhat.erata@yale.edu> on December 12, 2019.
//  Copyright (c) 2019 Yale University. All rights reserved.
// -----------------------------------------------------------------------------

#ifndef UTILITY_HPP
#define UTILITY_HPP

// Use -DDEBUG on the g++ command line to build the debug version
#ifdef DEBUG
#define PRINT(a) std::cout << a << std::endl

// Macro to print and then run a line of source code
#define v(a)                                                                   \
    cout << "\n[" #a "]" << endl;                                              \
    a

// Macro to print a variable
#define p(a)                                                                   \
    cout << #a " = " << a << endl;                                             \
    a

// Macro to print destructors
#define divider(a)                                                                   \
    std::cout << "\n Deleting " << #a << " " << this << std::dec << "...";

#else
#define DEBUG 0
// alternative way to define them:
#define v(a) a
#define p(a) a
#define PRINT(a)
#define d(a)
#endif

#include <string>

namespace utility {

// -----------------------------------------------------------------------------
// Prints a neat header on the output.
void banner();

// -----------------------------------------------------------------------------
//  Prints termination message.
void bye();

// -----------------------------------------------------------------------------
//  Generates a separator string
std::string separator();

// -----------------------------------------------------------------------------
// Prints stream state for debugging purposes.
std::string print_stream_state(const std::ios& stream);

// -----------------------------------------------------------------------------
// Fatal class is derived from std::exception; std::exception has virtual
// destructor and virtual "exception::what()" method that returns a C-style
// character string describing the general cause of the current error.
class fatal : public std::exception {
  private:
    const std::string message;

  public:
    explicit fatal(std::string message);

    [[nodiscard]] const char* what() const noexcept override;
};

} // namespace utility

namespace color {
inline const auto red = "\033[0;31m";
inline const auto green = "\033[0;32m";
inline const auto yellow = "\033[0;33m";
inline const auto blue = "\033[0;34m";
inline const auto magenta = "\033[0;35m";
inline const auto cyan = "\033[0;36m";
inline const auto bold = "\033[1m";
inline const auto reset_bold = "\033[21m";
inline const auto underline = "\033[4m";
inline const auto reset_underline = "\033[24m";
inline const auto reset = "\033[0m";
} // namespace color

#endif // UTILITY_HPP
