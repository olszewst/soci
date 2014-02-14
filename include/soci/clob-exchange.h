//
// Copyright (C) 2004-2008 Maciej Sobczak, Stephen Hutton
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef SOCI_CLOB_EXCHANGE_H_INCLUDED
#define SOCI_CLOB_EXCHANGE_H_INCLUDED

#include "clob.h"
#include "into-type.h"
#include "use-type.h"
// std
#include <string>

namespace soci
{

namespace details
{

template <>
class into_type<clob> : public standard_into_type
{
public:
    into_type(clob & b) : standard_into_type(&b, x_clob) {}
    into_type(clob & b, indicator & ind)
        : standard_into_type(&b, x_clob, ind) {}
};

template <>
class use_type<clob> : public standard_use_type
{
public:
    use_type(clob & b, std::string const & name = std::string())
        : standard_use_type(&b, x_clob, false, name) {}
    use_type(clob const & b, std::string const & name = std::string())
        : standard_use_type(const_cast<clob *>(&b), x_clob, true, name) {}
    use_type(clob & b, indicator & ind,
        std::string const & name = std::string())
        : standard_use_type(&b, x_clob, ind, false, name) {}
    use_type(clob const & b, indicator & ind,
        std::string const & name = std::string())
        : standard_use_type(const_cast<clob *>(&b), x_clob, ind, true, name) {}
};

template <>
struct exchange_traits<soci::clob>
{
    typedef basic_type_tag type_family;
};


} // namespace details

} // namespace soci

#endif // SOCI_CLOB_EXCHANGE_H_INCLUDED
