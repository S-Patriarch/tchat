// user.cpp -*- C++ -*-

/*
 * Copyright (c) S-Patriarch, 2023
 */

#include "user.h"
#include "/ptl/ptype.h"
#include "/ptl/pcolor.h"
#include <iostream>
#include <string>

namespace chat
{
  auto
  User::set_user(const std::string& __name, const std::string& __login, 
                 const std::string& __password, ptl::__u32 __id) -> void
  {
    _M_name     = __name;
    _M_login    = __login;
    _M_password = __password;
    _M_id       = __id;
  }

  auto
  User::out_user_name() -> void
  {
    ptl::pcolor __c;
    std::cout
      << __c.esc_tb(7)
      << _M_name
      << __c.esc_c()
      << ": ";
  }

} // namespace chat