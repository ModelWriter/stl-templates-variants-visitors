//  ----------------------------------------------------------------------------
//  Header file for the playground class.        playground.hpp
//  Created by Ferhat Erata <ferhat.erata@yale.edu> on December 21, 2019.
//  Copyright (c) 2019 Yale University. All rights reserved.
//  https://en.cppreference.com/w/cpp/algorithm
//  http://www.cplusplus.com/reference/algorithm/
// -----------------------------------------------------------------------------

#ifndef STL_PLAYGROUND_HPP
#define STL_PLAYGROUND_HPP

#include <iterator>

namespace my {

// -----------------------------------------------------------------------------
// Checks whether lhs is greater than rhs.
// https://en.cppreference.com/w/cpp/utility/functional/greater
template <class T = void> struct greater {
    constexpr bool operator()(const T& lhs, const T& rhs) const {
        return lhs > rhs;
    }
};

// -----------------------------------------------------------------------------
// Checks whether lhs is less than rhs.
// https://en.cppreference.com/w/cpp/utility/functional/less
template <class T = void> struct less {
    constexpr bool operator()(const T& lhs, const T& rhs) const {
        return lhs < rhs;
    }
};

// -----------------------------------------------------------------------------
// Checks whether lhs is greater than or equal to rhs.
// https://en.cppreference.com/w/cpp/utility/functional/greater_equal
template <class T = void> struct greater_equal {
    constexpr bool operator()(const T& lhs, const T& rhs) const {
        return lhs >= rhs;
    }
};

// -----------------------------------------------------------------------------
// Checks if lhs is less than or equal to rhs.
// https://en.cppreference.com/w/cpp/utility/functional/less_equal
template <class T = void> struct less_equal {
    constexpr bool operator()(const T& lhs, const T& rhs) const {
        return lhs <= rhs;
    }
};

// -----------------------------------------------------------------------------
// Checks whether lhs is not equal to rhs.
// https://en.cppreference.com/w/cpp/utility/functional/not_equal_to
template <class T = void> struct not_equal_to {
    constexpr bool operator()(const T& lhs, const T& rhs) const {
        return lhs != rhs;
    }
};

// -----------------------------------------------------------------------------
// Checks whether lhs is not equal to rhs.
// https://en.cppreference.com/w/cpp/utility/functional/equal_to
template <class T = void> struct equal_to {
    constexpr bool operator()(const T& lhs, const T& rhs) const {
        return lhs == rhs;
    }
};

// -----------------------------------------------------------------------------
// Returns the sum of lhs and rhs.
// https://en.cppreference.com/w/cpp/utility/functional/plus
template <class T = void> struct plus {
    constexpr T operator()(const T& lhs, const T& rhs) const {
        return lhs + rhs;
    }
};

// -----------------------------------------------------------------------------
// Returns the difference between lhs and rhs.
// https://en.cppreference.com/w/cpp/utility/functional/minus
template <class T = void> struct minus {
    constexpr T operator()(const T& lhs, const T& rhs) const {
        return lhs - rhs;
    }
};

// -----------------------------------------------------------------------------
// Returns the product of lhs and rhs.
// https://en.cppreference.com/w/cpp/utility/functional/multiplies
template <class T = void> struct multiplies {
    constexpr T operator()(const T& lhs, const T& rhs) const {
        return lhs * rhs;
    }
};

// -----------------------------------------------------------------------------
// Returns the product of lhs and rhs.
// https://en.cppreference.com/w/cpp/utility/functional/divides
template <class T = void> struct divides {
    constexpr T operator()(const T& lhs, const T& rhs) const {
        return lhs / rhs;
    }
};

// -----------------------------------------------------------------------------
// Returns the remainder of the division of lhs by rhs.
// https://en.cppreference.com/w/cpp/utility/functional/modulus
template <class T = void> struct modulus {
    constexpr T operator()(const T& lhs, const T& rhs) const {
        return lhs % rhs;
    }
};

// -----------------------------------------------------------------------------
// Returns the negation of arg.
// https://en.cppreference.com/w/cpp/utility/functional/negate
template <class T = void> struct negate {
    constexpr T operator()(const T& arg) const { return -arg; }
};

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

// -----------------------------------------------------------------------------
// 1) Assigns each element in range [first, last) a value generated by the given
// function object g.
// https://en.cppreference.com/w/cpp/algorithm/generate
template <class ForwardIt, class Generator>
void generate(ForwardIt first, ForwardIt last, Generator gen) {
    while (first != last) {
        *first++ = gen();
    }
}

// -----------------------------------------------------------------------------
// Removes all elements satisfying specific criteria from the range [first,
// last) and returns a past-the-end iterator for the new end of the range.
// 1) Removes all elements that are equal to value, using operator== to compare
// them.
// https://en.cppreference.com/w/cpp/algorithm/remove
template <class ForwardIt, class T>
ForwardIt remove(ForwardIt first, ForwardIt last, const T& value) {
    first = my::find(first, last, value);
    if (first != last)
        for (ForwardIt i = first; ++i != last;)
            if (!(*i == value))
                *first++ = std::move(*i);
    return first;
}

// -----------------------------------------------------------------------------
// Removes all elements satisfying specific criteria from the range [first,
// last) and returns a past-the-end iterator for the new end of the range.
// 3) Removes all elements for which predicate p returns true.
// https://en.cppreference.com/w/cpp/algorithm/remove
template <class ForwardIt, class UnaryPredicate>
ForwardIt remove_if(ForwardIt first, ForwardIt last, UnaryPredicate pred) {
    first = my::find_if(first, last, pred);
    if (first != last)
        for (ForwardIt i = first; ++i != last;)
            if (!pred(*i))
                *first++ = std::move(*i);
    return first;
}

// -----------------------------------------------------------------------------
// Finds the greatest element in the range [first, last).
// 1) Elements are compared using operator<.
// https://en.cppreference.com/w/cpp/algorithm/max_element
template <class ForwardIt>
ForwardIt max_element(ForwardIt first, ForwardIt last) {
    if (first == last)
        return last;

    ForwardIt largest = first;
    ++first;
    for (; first != last; ++first) {
        if (*largest < *first) {
            largest = first;
        }
    }
    return largest;
}

// -----------------------------------------------------------------------------
// Finds the greatest element in the range [first, last).
// 3) Elements are compared using the given binary comparison function comp.
// https://en.cppreference.com/w/cpp/algorithm/max_element
template <class ForwardIt, class Compare>
ForwardIt max_element(ForwardIt first, ForwardIt last, Compare comp) {
    if (first == last)
        return last;

    ForwardIt largest = first;
    ++first;
    for (; first != last; ++first) {
        if (comp(*largest, *first)) {
            largest = first;
        }
    }
    return largest;
}

// -----------------------------------------------------------------------------
// Finds the smallest element in the range [first, last).
// 1) Elements are compared using operator<.
// https://en.cppreference.com/w/cpp/algorithm/min_element
template <class ForwardIt>
ForwardIt min_element(ForwardIt first, ForwardIt last) {
    if (first == last)
        return last;

    ForwardIt smallest = first;
    ++first;
    for (; first != last; ++first) {
        if (*first < *smallest) {
            smallest = first;
        }
    }
    return smallest;
}

// -----------------------------------------------------------------------------
// Finds the smallest element in the range [first, last).
// 3) Elements are compared using the given binary comparison function comp.
// https://en.cppreference.com/w/cpp/algorithm/min_element
template <class ForwardIt, class Compare>
ForwardIt min_element(ForwardIt first, ForwardIt last, Compare comp) {
    if (first == last)
        return last;

    ForwardIt smallest = first;
    ++first;
    for (; first != last; ++first) {
        if (comp(*first, *smallest)) {
            smallest = first;
        }
    }
    return smallest;
}

// -----------------------------------------------------------------------------
// Returns the greater of the given values.
// 1-2) Returns the greater of a and b.
// https://en.cppreference.com/w/cpp/algorithm/max
template <class T> const T& max(const T& a, const T& b) {
    return (a < b) ? b : a;
}

template <class T, class Compare>
const T& max(const T& a, const T& b, Compare comp) {
    return (comp(a, b)) ? b : a;
}

// -----------------------------------------------------------------------------
// Returns the greater of the given values.
// 3-4) Returns the greatest of the values in initializer list ilist.
// https://en.cppreference.com/w/cpp/algorithm/max
template <class T> T max(std::initializer_list<T> ilist) {
    return *my::max_element(ilist.begin(), ilist.end());
}

template <class T, class Compare>
T max(std::initializer_list<T> ilist, Compare comp) {
    return *my::max_element(ilist.begin(), ilist.end(), comp);
}

// -----------------------------------------------------------------------------
// Returns the greater of the given values.
// 1-2) Returns the smaller of a and b.
// https://en.cppreference.com/w/cpp/algorithm/max
template <class T> const T& min(const T& a, const T& b) {
    return (b < a) ? b : a;
}

template <class T, class Compare>
const T& min(const T& a, const T& b, Compare comp) {
    return (comp(b, a)) ? b : a;
}

// -----------------------------------------------------------------------------
// Returns the greater of the given values.
// 3-4) Returns the smallest of the values in initializer list ilist.
// https://en.cppreference.com/w/cpp/algorithm/min
template <class T> T min(std::initializer_list<T> ilist) {
    return *my::min_element(ilist.begin(), ilist.end());
}

template <class T, class Compare>
T min(std::initializer_list<T> ilist, Compare comp) {
    return *my::min_element(ilist.begin(), ilist.end(), comp);
}

// -----------------------------------------------------------------------------
// Finds the smallest and greatest element in the range [first, last).
// 3) Elements are compared using the given binary comparison function comp.
// https://en.cppreference.com/w/cpp/algorithm/minmax_element
template <class ForwardIt, class Compare>
std::pair<ForwardIt, ForwardIt> minmax_element(ForwardIt first, ForwardIt last,
                                               Compare comp) {
    auto min = first, max = first;

    if (first == last || ++first == last)
        return {min, max};

    if (comp(*first, *min)) {
        min = first;
    } else {
        max = first;
    }

    while (++first != last) {
        auto i = first;
        if (++first == last) {
            if (comp(*i, *min))
                min = i;
            else if (!(comp(*i, *max)))
                max = i;
            break;
        } else {
            if (comp(*first, *i)) {
                if (comp(*first, *min))
                    min = first;
                if (!(comp(*i, *max)))
                    max = i;
            } else {
                if (comp(*i, *min))
                    min = i;
                if (!(comp(*first, *max)))
                    max = first;
            }
        }
    }
    return {min, max};
}

// -----------------------------------------------------------------------------
// Finds the smallest and greatest element in the range [first, last).
// 1) Elements are compared using operator<.
// https://en.cppreference.com/w/cpp/algorithm/minmax_element
template <class ForwardIt>
std::pair<ForwardIt, ForwardIt> minmax_element(ForwardIt first,
                                               ForwardIt last) {
    using value_type = typename std::iterator_traits<ForwardIt>::value_type;
    return my::minmax_element(first, last, my::less<value_type>());
}

// -----------------------------------------------------------------------------
// Examines the range [first, last) and finds the largest range beginning at
// first in which the elements are sorted in ascending order.
//
// A sequence is sorted with respect to a comparator comp if for any iterator it
// pointing to the sequence and any non-negative integer n such that it + n is a
// valid iterator pointing to an element of the sequence, comp(*(it + n), *it)
// evaluates to false.
// 3) Elements are compared using the given binary comparison function comp.
// https://en.cppreference.com/w/cpp/algorithm/is_sorted_until
template <class ForwardIt, class Compare>
ForwardIt is_sorted_until(ForwardIt first, ForwardIt last, Compare comp) {
    if (first != last) {
        ForwardIt next = first;
        while (++next != last) {
            if (comp(*next, *first))
                return next;
            first = next;
        }
    }
    return last;
}

// -----------------------------------------------------------------------------
// Examines the range [first, last) and finds the largest range beginning at
// first in which the elements are sorted in ascending order.
//
// A sequence is sorted with respect to a comparator comp if for any iterator it
// pointing to the sequence and any non-negative integer n such that it + n is a
// valid iterator pointing to an element of the sequence, comp(*(it + n), *it)
// evaluates to false.
// 1) Elements are compared using operator<.
// https://en.cppreference.com/w/cpp/algorithm/is_sorted_until

struct less_iter {
    template <typename Iterator1, typename Iterator2>
    constexpr bool operator()(Iterator1 it1, Iterator2 it2) const {
        return *it1 < *it2;
    }
};

constexpr inline less_iter __iter_less_iter() { return less_iter(); }

template <class ForwardIt>
ForwardIt is_sorted_until(ForwardIt first, ForwardIt last) {
    return my::is_sorted_until(first, last, my::__iter_less_iter());
}

// -----------------------------------------------------------------------------
// Checks if the elements in range [first, last) are sorted in non-descending
// order.
//
// A sequence is sorted with respect to a comparator comp if for any iterator it
// pointing to the sequence and any non-negative integer n such that it + n is a
// valid iterator pointing to an element of the sequence, comp(*(it + n), *it)
// evaluates to false.
// 1) Elements are compared using operator<.
template <class ForwardIt> bool is_sorted(ForwardIt first, ForwardIt last) {
    return my::is_sorted_until(first, last) == last;
}

// -----------------------------------------------------------------------------
// Checks if the elements in range [first, last) are sorted in non-descending
// order.
//
// A sequence is sorted with respect to a comparator comp if for any iterator it
// pointing to the sequence and any non-negative integer n such that it + n is a
// valid iterator pointing to an element of the sequence, comp(*(it + n), *it)
// evaluates to false.
// 3) Elements are compared using the given binary comparison function comp.
template <class ForwardIt, class Compare>
bool is_sorted(ForwardIt first, ForwardIt last, Compare comp) {
    return my::is_sorted_until(first, last, comp) == last;
}
// -----------------------------------------------------------------------------
// Calculates the number of elements between first and last.
// If it is a random-access iterator, the function uses operator- to calculate
// this. Otherwise, the function uses the increase operator (operator++)
// repeatedly.
// http://www.cplusplus.com/reference/iterator/distance/
template <typename InputIterator>
inline constexpr typename std::iterator_traits<InputIterator>::difference_type
distance(InputIterator first, InputIterator last) {

    typename std::iterator_traits<InputIterator>::difference_type n = 0;
    while (first != last) {
        ++first;
        ++n;
    }
    return n;
}

} // namespace my

#endif // STL_PLAYGROUND_HPP
