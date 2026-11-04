// libstdc++ 的 <bits/stdc++.h> 在 Apple clang / libc++ 下不存在。
// 這個 shim 讓 clangd 與 Apple clang 也能編譯用了 bits/stdc++.h 的競賽程式碼。
// 用法：compile_flags.txt 或編譯指令加上 -I <repo>/.include
#pragma once

// C compatibility
#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfenv>
#include <cfloat>
#include <cinttypes>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cuchar>
#include <cwchar>
#include <cwctype>

// Containers
#include <array>
#include <bitset>
#include <deque>
#include <forward_list>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <span>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

// Algorithms / iterators / ranges
#include <algorithm>
#include <iterator>
#include <numeric>
#include <ranges>

// Strings / text
#include <charconv>
#include <format>
#include <regex>
#include <string>
#include <string_view>

// I/O
#include <fstream>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <ostream>
#include <sstream>
#include <streambuf>

// Numerics / utility
#include <bit>
#include <chrono>
#include <complex>
#include <concepts>
#include <exception>
#include <functional>
#include <initializer_list>
#include <limits>
#include <memory>
#include <new>
#include <optional>
#include <random>
#include <ratio>
#include <stdexcept>
#include <tuple>
#include <type_traits>
#include <typeindex>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <variant>

// Concurrency
#include <atomic>
#include <condition_variable>
#include <future>
#include <mutex>
#include <thread>
