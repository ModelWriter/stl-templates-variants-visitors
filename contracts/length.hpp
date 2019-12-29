//  ----------------------------------------------------------------------------
//  Header file for the length class.                                 length.hpp
//  Created by Ferhat Erata <ferhat.erata@yale.edu> on December 28, 2019.
//  Copyright (c) 2019 Yale University. All rights reserved.
// -----------------------------------------------------------------------------

#ifndef CONTRACTS_LENGTH_HPP
#define CONTRACTS_LENGTH_HPP

#include <cmath>
#include <iostream>
#include <stdexcept>

// -----------------------------------------------------------------------------
// define special type for the concept of "length" in terms of float
class length {
  private:
    float m_value;

  public:
    constexpr explicit length(float f = 0.0f) : m_value(f) {
        if (std::isnan(f) // value must be a valid floating value
            || f < 0.0f)  // which is not negative
            throw std::domain_error("length constructor requires non-negative "
                                    "floating point value.");
    }

    // equality comparable
    constexpr bool operator==(const length& rhs) const;
    constexpr bool operator!=(const length& rhs) const;
    // ordered
    constexpr bool operator<=(const length& rhs) const;
    constexpr bool operator<(const length& rhs) const;
    constexpr bool operator>(const length& rhs) const;
    constexpr bool operator>=(const length& rhs) const;
    // additive
    constexpr length operator+(const length& rhs);
    // has identity because can be constructed with 0.0f

    [[nodiscard]] std::ostream& write(std::ostream& out) const;

    std::istream& read(std::istream& in);

    friend std::ostream& operator<<(std::ostream& os, const length& length);
};

// -----------------------------------------------------------------------------
// given a rectangle with dimensions l and w in feet calculate its perimeter in
// feet
length calculate_perimeter(length l, length m);

// -----------------------------------------------------------------------------
// given a rectangle with dimensions l and w in feet calculate its perimeter in
// feet
float calculate_perimeter(float l, float w);

// -----------------------------------------------------------------------------
// serialize a length to output stream
inline std::ostream& operator<<(std::ostream& os, const length& length) {
    return length.write(os);
}

// -----------------------------------------------------------------------------
// deserialize a part from input stream
inline std::istream& operator>>(std::istream& in, length& value) {
    return value.read(in);
}

#endif // CONTRACTS_LENGTH_HPP
