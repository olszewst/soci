//
// Copyright (C) 2004-2007 Maciej Sobczak, Stephen Hutton
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//

#include "soci-oracle.h"
#include "error.h"
#include "statement.h"
#include <cstring>
#include <sstream>
#include <cstdio>
#include <ctime>
#include <cctype>

#ifdef _MSC_VER
#pragma warning(disable:4355)
#endif

using namespace soci;
using namespace soci::details;
using namespace soci::details::oracle;

oracle_clob_backend::oracle_clob_backend(oracle_session_backend &session)
    : blobBackEnd_(session)
{
  
}
/*
    sword res = OCIDescriptorAlloc(session.envhp_,
        reinterpret_cast<dvoid**>(&lobp_), OCI_DTYPE_LOB, 0, 0);
    if (res != OCI_SUCCESS)
    {
        throw soci_error("Cannot allocate the LOB locator");
    }
}

*/

oracle_clob_backend::~oracle_clob_backend()
{
   // OCIDescriptorFree(lobp_, OCI_DTYPE_LOB);
}


std::size_t oracle_clob_backend::get_len()
{
   return blobBackEnd_.get_len();
}

std::size_t oracle_clob_backend::read(
    std::size_t offset, char *buf, std::size_t toRead)
{
    return blobBackEnd_.read(offset, buf, toRead);
}

std::size_t oracle_clob_backend::write(
    std::size_t offset, char const *buf, std::size_t toWrite)
{
   return blobBackEnd_.write(offset, buf, toWrite);
}

std::size_t oracle_clob_backend::append(char const *buf, std::size_t toWrite)
{
    return blobBackEnd_.append(buf, toWrite);
}

void oracle_clob_backend::trim(std::size_t newLen)
{
    return blobBackEnd_.trim(newLen);
}
