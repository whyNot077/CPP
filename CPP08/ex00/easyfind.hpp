#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <stdexcept>
#include <vector>
#include <list>

template <typename T>
typename T::const_iterator easyfind(T const& container, int value);

#include "easyfind.tpp"

#endif
