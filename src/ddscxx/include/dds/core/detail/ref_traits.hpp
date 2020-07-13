/*
 *                         Vortex Lite
 *
 *   This software and documentation are Copyright 2006 to 2015 PrismTech
 *   Limited and its licensees. All rights reserved. See file:
 *
 *                     $LITE_HOME/LICENSE
 *
 *   for full copyright notice and license terms.
 *
 */
#ifndef CYCLONEDDS_DDS_CORE_DETAIL_REF_TRAITS_HPP_
#define CYCLONEDDS_DDS_CORE_DETAIL_REF_TRAITS_HPP_

/**
 * @file
 */

// Implementation

#include <dds/core/types.hpp>
#include <dds/core/Exception.hpp>

/* Compiling explicitly w/ C++ 11 support */
#if defined(OSPL_USE_CXX11)
#  include <memory>
#  include <type_traits>
#  define OSPL_CXX11_STD_MODULE ::std

/* Compiling to use Tech Report 1 headers */
#elif defined(OSPL_USE_TR1)
#  ifdef _MSC_VER
#    include <memory>
#    include <type_traits>
#  else
#    include <tr1/memory>
#    include <tr1/type_traits>
#  endif
#  define OSPL_CXX11_STD_MODULE ::std::tr1

/* Compiling with boost */
#elif defined(OSPL_USE_BOOST)
#  include <boost/shared_ptr.hpp>
#  include <boost/weak_ptr.hpp>
#  include <boost/type_traits.hpp>
#  define OSPL_CXX11_STD_MODULE ::boost

#else
#  error "macros.hpp header not included or other unexpected misconfiguration"
#endif

template <typename T1, typename T2>
struct dds::core::is_base_of :
#if defined (OSPL_USE_BOOST) && ! defined (BOOST_TT_IS_BASE_OF_HPP_INCLUDED)
#   include "boost/type_traits/is_base_and_derived.hpp"
        ::boost::detail::is_base_and_derived_impl<T1, T2> { }; // Really old boost had no is_base_of
#else
    public OSPL_CXX11_STD_MODULE::is_base_of<T1, T2> { };
#endif

template <typename T1, typename T2>
struct dds::core::is_same : public OSPL_CXX11_STD_MODULE::is_same<T1, T1> { };

template <typename T>
struct dds::core::smart_ptr_traits
{
    typedef OSPL_CXX11_STD_MODULE::shared_ptr<T> ref_type;
    typedef OSPL_CXX11_STD_MODULE::weak_ptr<T>   weak_ref_type;
};

template <typename TO, typename FROM>
TO dds::core::polymorphic_cast(FROM& from)
{
    typename TO::DELEGATE_REF_T dr =
        OSPL_CXX11_STD_MODULE::dynamic_pointer_cast< typename TO::DELEGATE_T>(from.delegate());
    TO to(dr);

    if(to == dds::core::null)
    {
        throw dds::core::InvalidDowncastError("Attempted invalid downcast.");
    }
    return to;
}

// End of implementation

#endif /* CYCLONEDDS_DDS_CORE_DETAIL_REF_TRAITS_HPP_ */
