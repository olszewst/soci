//
// Copyright (C) 2004-2008 Maciej Sobczak, Stephen Hutton
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef SOCI_CLOB_H_INCLUDED
#define SOCI_CLOB_H_INCLUDED

#include "soci-config.h"
// std
#include <cstddef>

namespace soci
{
    // basic clob operations

    class session;

    namespace details
    {
        class clob_backend;
    } // namespace details

    class SOCI_DECL clob : public blob
    {
    public:
        explicit clob(session & s);
        ~clob();

        operator std::string() const;
        clob& operator<<(const std::string& data);

        virtual details::clob_backend * get_backend() { return backEnd_; }

    private:
        details::clob_backend * backEnd_;
    };

} // namespace soci

#endif
