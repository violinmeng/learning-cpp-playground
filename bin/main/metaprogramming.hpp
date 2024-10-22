#pragma once

#include <deque>
#include <iostream>
#include <set>
#include <vector>

namespace MetaProgramming {

template<typename It,
  std::enable_if_t<
    !std::is_same<std::random_access_iterator_tag, typename std::iterator_traits<It>::iterator_category>::value,
    bool> = true>
size_t myDistance(It first, It last)
{
  size_t result = 0;
  while (first != last) {
    ++first;
    ++result;
  }
  return result;
}

template<typename It,
  std::enable_if_t<
    std::is_same<std::random_access_iterator_tag, typename std::iterator_traits<It>::iterator_category>::value,
    bool> = true>
size_t myDistance(It first, It last)
{
  return last - first;
}

void vectorDistance()
{
  std::vector<std::string> names{ "Anna", "Ethan", "Nikhil", "Avery" };
  auto iter_anna = std::find(names.begin(), names.end(), "Anna");
  auto iter_avery = std::find(names.begin(), names.end(), "Avery");

  std::cout << "vector: " << myDistance(iter_anna, iter_avery) << "\n";
}

void dequeDistance()
{
  std::deque<std::string> names{ "Anna", "Ethan", "Nikhil", "Avery" };
  auto iter_anna = std::find(names.begin(), names.end(), "Anna");
  auto iter_avery = std::find(names.begin(), names.end(), "Avery");

  std::cout << "deque: " << myDistance(iter_anna, iter_avery) << "\n";
}
void setDistance()
{
  std::set<std::string> names{ "Anna", "Ethan", "Nikhil", "Avery" };
  auto iter_anna = names.find("Anna");
  auto iter_avery = names.find("Avery");

  std::cout << "set: " << myDistance(iter_anna, iter_avery) << "\n";
}
void metaProgrammingClientCode()
{
  vectorDistance();
  dequeDistance();
  setDistance();
}

void computationOnTypes()
{
  using S = int;
  using c_ref = const S &;
  using result = std::remove_reference<c_ref>::type;
  constexpr bool equals = std::is_same<result, const int>::value;
  std::cout << "result is equal to const int :" << equals << "\n";
}

}// namespace MetaProgramming
