//  ----------------------------------------------------------------------------
//  Implementation file for the length class.                         length.cpp
//  Created by Ferhat Erata <ferhat.erata@yale.edu> on December 28, 2019.
//  Copyright (c) 2019 Yale University. All rights reserved.
// -----------------------------------------------------------------------------

#include "length.hpp"

// -----------------------------------------------------------------------------
// additive
constexpr length length::operator+(const length& rhs) {
    // pre-condition: arguments are valid values
    return length(m_value + rhs.m_value);
    // post-condition: checked when return value is constructed.
}

// -----------------------------------------------------------------------------
// serialize a length to output stream
std::ostream& length::write(std::ostream& out) const { return out << m_value; }

// -----------------------------------------------------------------------------
// deserialize a part from input stream
std::istream& length::read(std::istream& in) { return in >> m_value; }

// -----------------------------------------------------------------------------
// equal
constexpr bool length::operator==(const length& rhs) const {
    return m_value == rhs.m_value;
}

// -----------------------------------------------------------------------------
// not equal
constexpr bool length::operator!=(const length& rhs) const {
    return m_value != rhs.m_value;
}

// -----------------------------------------------------------------------------
// less than or equal
constexpr bool length::operator<=(const length& rhs) const {
    return m_value <= rhs.m_value;
}

// -----------------------------------------------------------------------------
// less than
constexpr bool length::operator<(const length& rhs) const {
    return m_value < rhs.m_value;
}

// -----------------------------------------------------------------------------
// greater than
constexpr bool length::operator>(const length& rhs) const {
    return m_value > rhs.m_value;
}

// -----------------------------------------------------------------------------
// greater than or equal
constexpr bool length::operator>=(const length& rhs) const {
    return m_value >= rhs.m_value;
}

// -----------------------------------------------------------------------------
// given a rectangle with dimensions l and w in feet calculate its perimeter in
// feet
length calculate_perimeter(length l, length m) {
    // pre-condition: verify initial facts
    // not necessarily - length types guarantees correctness
    length perimeter = l + l + m + m;
    // post-condition: length type guarantees correctness
    return perimeter;
}

// -----------------------------------------------------------------------------
// given a rectangle with dimensions l and w in feet calculate its perimeter in
// feet
float calculate_perimeter(float l, float w) {
    // pre-condition: verify initial facts
    // variable l contains a valid length
    if (std::isnan(l)) // l contains a valid
        throw std::domain_error("length not valid");
    // variable w contains a valid width
    if (std::isnan(w)) // l contains a valid
        throw std::domain_error("width not valid");
    if (w < 0.0f)
        throw std::domain_error("width must be positive");
    float perimeter = 2 * (l + w);
    if (std::isnan(perimeter))
        throw std::overflow_error("overflow on multiplication");
    // new fact: variable named perimeter contains a valid value for the
    // perimeter of the rectangle
    return perimeter;
}
