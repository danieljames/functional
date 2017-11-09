
// Copyright 2005-2009 Daniel James.
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include "./config.hpp"

#ifdef BOOST_HASH_TEST_EXTENSIONS
#  ifdef BOOST_HASH_TEST_STD_INCLUDES
#    include <functional>
#  else
#    include <boost/functional/hash.hpp>
#  endif
#endif

#include <boost/detail/lightweight_test.hpp>

#ifdef BOOST_HASH_TEST_EXTENSIONS

void array_int_test()
{
    std::equal_to<int[4]> equal;
    boost::hash<int[4]> hash;
    int a[4] = {1,2,3,4};
    int b[4] = {5,5,5,5};
    b[0] = 1;
    b[1] = 2;
    b[2] = 3;
    b[3] = 4;
    BOOST_TEST(hash(a) != hash(b));
    BOOST_TEST(!equal(a,b));
    BOOST_TEST(hash(a) == hash(a));
    BOOST_TEST(equal(a,a));
    BOOST_TEST(hash(b) == hash(b));
    BOOST_TEST(equal(b,b));

#if !defined(BOOST_NO_CXX11_NOEXCEPT)
    BOOST_STATIC_ASSERT((noexcept(hash(a))));
#endif
}

#endif // BOOST_HASH_TEST_EXTENSIONS

int main()
{
#ifdef BOOST_HASH_TEST_EXTENSIONS
    array_int_test();
#endif
    return boost::report_errors();
}
