
// Copyright 2005-2009 Daniel James.
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <boost/config.hpp>
#include <boost/static_assert.hpp>
#include <boost/type_traits/is_base_and_derived.hpp>

#if !defined(BOOST_NO_CXX11_NOEXCEPT)
#include <boost/type_traits/is_nothrow_move_assignable.hpp>
#include <boost/type_traits/is_nothrow_move_constructible.hpp>
// TODO: Uncomment when my merge request is accepted.
//#include <boost/type_traits/is_nothrow_swappable.hpp>

#endif

template <class T>
void compile_time_tests(T*)
{
#if !defined(_HAS_AUTO_PTR_ETC) || _HAS_AUTO_PTR_ETC
    BOOST_STATIC_ASSERT((boost::is_base_and_derived<
        std::unary_function<T, std::size_t>, BOOST_HASH_TEST_NAMESPACE::hash<T> >::value));
#endif

#if !defined(BOOST_NO_CXX11_NOEXCEPT)
    BOOST_STATIC_ASSERT((boost::is_nothrow_move_assignable<boost::hash<T> >::value));
    BOOST_STATIC_ASSERT((boost::is_nothrow_move_constructible<boost::hash<T> >::value));
    //BOOST_STATIC_ASSERT((boost::is_nothrow_swappable<boost::hash<T> >::value));
#endif
}

