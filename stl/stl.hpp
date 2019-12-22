//  ----------------------------------------------------------------------------
//  Header file for the playground class.        playground.hpp
//  Created by Ferhat Erata <ferhat.erata@yale.edu> on December 21, 2019.
//  Copyright (c) 2019 Yale University. All rights reserved.
// -----------------------------------------------------------------------------

#ifndef STL_PLAYGROUND_HPP
#define STL_PLAYGROUND_HPP

#include <iterator>

namespace my {

// -----------------------------------------------------------------------------
// Applies the given function object f to the result of dereferencing every
// iterator in the range [first, last), in order
// https://en.cppreference.com/w/cpp/algorithm/for_each
template <class InputIt, class UnaryFunction>
constexpr UnaryFunction for_each(InputIt first, InputIt last, UnaryFunction f) {
    for (; first != last; ++first) {
        f(*first);
    }
    return f; // implicit move since C++11
}

// -----------------------------------------------------------------------------
// std::transform applies the given function to a range and stores the result in
// another range, beginning at d_first.
// https://en.cppreference.com/w/cpp/algorithm/transform
template <class InputIt, class OutputIt, class UnaryOperation>
OutputIt transform(InputIt first1, InputIt last1, OutputIt d_first,
                   UnaryOperation unary_op) {
    while (first1 != last1) {
        *d_first++ = unary_op(*first1++);
    }
    return d_first;
}

// -----------------------------------------------------------------------------
// std::transform applies the given function to a range and stores the result in
// another range, beginning at d_first.
// https://en.cppreference.com/w/cpp/algorithm/transform
template <class InputIt1, class InputIt2, class OutputIt, class BinaryOperation>
OutputIt transform(InputIt1 first1, InputIt1 last1, InputIt2 first2,
                   OutputIt d_first, BinaryOperation binary_op) {
    while (first1 != last1) {
        *d_first++ = binary_op(*first1++, *first2++);
    }
    return d_first;
}

// -----------------------------------------------------------------------------
// Returns the first element in the range [first, last) that satisfies specific
// criteria:
// 1) find searches for an element equal to value
// https://en.cppreference.com/w/cpp/algorithm/find
template <class InputIt, class T>
constexpr InputIt find(InputIt first, InputIt last, const T& value) {
    for (; first != last; ++first) {
        if (*first == value) {
            return first;
        }
    }
    return last;
}

// -----------------------------------------------------------------------------
// Returns the first element in the range [first, last) that satisfies specific
// criteria:
// 3) find_if searches for an element for which predicate p returns true
// https://en.cppreference.com/w/cpp/algorithm/find
template <class InputIt, class UnaryPredicate>
constexpr InputIt find_if(InputIt first, InputIt last, UnaryPredicate pred) {
    for (; first != last; ++first) {
        if (pred(*first)) {
            return first;
        }
    }
    return last;
}

// -----------------------------------------------------------------------------
// Returns the first element in the range [first, last) that satisfies specific
// criteria:
// 5) find_if_not searches for an element for which predicate q returns false
// https://en.cppreference.com/w/cpp/algorithm/find
template <class InputIt, class UnaryPredicate>
constexpr InputIt find_if_not(InputIt first, InputIt last, UnaryPredicate q) {
    for (; first != last; ++first) {
        if (!q(*first)) {
            return first;
        }
    }
    return last;
}

// -----------------------------------------------------------------------------
// Returns the number of elements in the range [first, last) satisfying specific
// criteria.
// 1) counts the elements that are equal to value.
// https://en.cppreference.com/w/cpp/algorithm/count
template <class InputIt, class T>
typename std::iterator_traits<InputIt>::difference_type
count(InputIt first, InputIt last, const T& value) {
    typename std::iterator_traits<InputIt>::difference_type ret = 0;
    for (; first != last; ++first) {
        if (*first == value) {
            ret++;
        }
    }
    return ret;
}

// -----------------------------------------------------------------------------
// Returns the number of elements in the range [first, last) satisfying specific
// criteria.
// 3) counts elements for which predicate p returns true.
// https://en.cppreference.com/w/cpp/algorithm/count
template <class InputIt, class UnaryPredicate>
typename std::iterator_traits<InputIt>::difference_type
count_if(InputIt first, InputIt last, UnaryPredicate pred) {
    typename std::iterator_traits<InputIt>::difference_type ret = 0;
    for (; first != last; ++first) {
        if (pred(*first)) {
            ret++;
        }
    }
    return ret;
}

// -----------------------------------------------------------------------------
// Searches the range [first, last) for any of the elements in the range
// [s_first, s_last).
// 1) Elements are compared using operator==.
// https://en.cppreference.com/w/cpp/algorithm/find_first_of
template <class InputIt, class ForwardIt>
InputIt find_first_of(InputIt first, InputIt last, ForwardIt s_first,
                      ForwardIt s_last) {
    for (; first != last; ++first) {
        for (ForwardIt it = s_first; it != s_last; ++it) {
            if (*first == *it) {
                return first;
            }
        }
    }
    return last;
}

// -----------------------------------------------------------------------------
// Searches the range [first, last) for any of the elements in the range
// [s_first, s_last).
// 3) Elements are compared using the given binary predicate p.
// https://en.cppreference.com/w/cpp/algorithm/find_first_of
template <class InputIt, class ForwardIt, class BinaryPredicate>
InputIt find_first_of(InputIt first, InputIt last, ForwardIt s_first,
                      ForwardIt s_last, BinaryPredicate pred) {
    for (; first != last; ++first) {
        for (ForwardIt it = s_first; it != s_last; ++it) {
            if (pred(*first, *it)) {
                return first;
            }
        }
    }
    return last;
}

// -----------------------------------------------------------------------------
// 1) Checks if unary predicate p returns true for all elements in the range
// [first, last).
// https://en.cppreference.com/w/cpp/algorithm/all_any_none_of
template <class InputIt, class UnaryPredicate>
constexpr bool all_of(InputIt first, InputIt last, UnaryPredicate p) {
    return my::find_if_not(first, last, p) == last;
}

// -----------------------------------------------------------------------------
// 3) Checks if unary predicate p returns true for at least one element in the
// range [first, last).
// https://en.cppreference.com/w/cpp/algorithm/all_any_none_of
template <class InputIt, class UnaryPredicate>
constexpr bool any_of(InputIt first, InputIt last, UnaryPredicate p) {
    return my::find_if(first, last, p) != last;
}

// -----------------------------------------------------------------------------
// 5) Checks if unary predicate p returns true for no elements in the range
// [first, last).
// https://en.cppreference.com/w/cpp/algorithm/all_any_none_of
template <class InputIt, class UnaryPredicate>
constexpr bool none_of(InputIt first, InputIt last, UnaryPredicate p) {
    return my::find_if(first, last, p) == last;
}

// -----------------------------------------------------------------------------
// Copies the elements in the range, defined by [first, last), to another range
// beginning at d_first.
// 1) Copies all elements in the range [first, last) starting from first and
// proceeding to last - 1. The behavior is undefined if d_first is within the
// range [first, last). In this case, std::copy_backward may be used instead.
// https://en.cppreference.com/w/cpp/algorithm/copy
template <class InputIt, class OutputIt>
OutputIt copy(InputIt first, InputIt last, OutputIt d_first) {
    while (first != last) {
        *d_first++ = *first++;
    }
    return d_first;
}

// -----------------------------------------------------------------------------
// Copies the elements in the range, defined by [first, last), to another range
// beginning at d_first.
// 3) Only copies the elements for which the predicate pred
// returns true. The relative order of the elements that are copied is
// preserved. The behavior is undefined if the source and the destination ranges
// overlap. https://en.cppreference.com/w/cpp/algorithm/copy
template <class InputIt, class OutputIt, class UnaryPredicate>
OutputIt copy_if(InputIt first, InputIt last, OutputIt d_first,
                 UnaryPredicate pred) {
    while (first != last) {
        if (pred(*first))
            *d_first++ = *first;
        first++;
    }
    return d_first;
}

} // namespace my

#endif // STL_PLAYGROUND_HPP
