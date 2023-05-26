// cst.h -*- C++ -*-

/*
 * Copyright (c) S-Patriarch, 2023
 *
 * Заголовочный файл с определением констант.
 */

#pragma once
#ifndef _CHAT_CST
#define _CHAT_CST

#include "/home/chaos/c++/ptl/ptype.h"

namespace chat
{
  constexpr ptl::__u16
  _Quantity_Messages { 100 };

  constexpr ptl::__u16
  _Help   { 10 };

  constexpr ptl::__u16
  _Change { 20 };

  constexpr ptl::__u16
  _Quit   { 30 };

  constexpr ptl::__u16
  _Ok     { 1000 };

} // namespace chat 

#endif // _CHAT_CST