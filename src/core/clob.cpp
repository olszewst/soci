//
// Copyright (C) 2004-2008 Maciej Sobczak, Stephen Hutton
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//

#define SOCI_SOURCE
#include "clob.h"
#include "session.h"

#include <cstddef>

using namespace soci;

clob::clob(session & s)
    : blob(s)
{
    clobBackEnd_ = s.make_clob_backend();
}

clob::~clob()
{
    delete clobBackEnd_;
}

details::clob_backend * clob::get_backend()
{ 
    return clobBackEnd_; 
}