// Copyright (c) 2015 Ryan Prichard
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to
// deal in the Software without restriction, including without limitation the
// rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
// sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
// IN THE SOFTWARE.

#ifndef STRING_UTIL_H
#define STRING_UTIL_H

#include <stdlib.h>

#include <string>
#include <vector>

size_t winpty_wcsnlen(const wchar_t *s, size_t maxlen);
std::string utf8FromWide(const std::wstring &input);

// Return a vector containing each character in the string.
template <typename T>
std::vector<T> vectorFromString(const std::basic_string<T> &str) {
    return std::vector<T>(str.begin(), str.end());
}

// Return a vector containing each character in the string, followed by a
// NUL terminator.
template <typename T>
std::vector<T> vectorWithNulFromString(const std::basic_string<T> &str) {
    std::vector<T> ret;
    ret.reserve(str.size() + 1);
    ret.insert(ret.begin(), str.begin(), str.end());
    ret.push_back('\0');
    return ret;
}

#endif // STRING_UTIL_H
