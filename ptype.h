// -*- C++ -*-

/*
 * Copyright (c) S-Patriarch, 2023
 *
 * Описание библиотеки для псевдонимов предопределенных типов данных.
 */

/**
 *  (PTL) Patriarch library : ptype.h
 */

#pragma once
#ifndef _PTL_PTYPE
#define _PTL_PTYPE

namespace ptl
{
  typedef signed short int       __s16; // 32 767
  typedef unsigned short int     __u16; // 65 535

  typedef signed int             __s32; // 2.14748e+09
  typedef unsigned int           __u32; // 4.29497e+09

  typedef signed long long int   __s64; // 9.22337e+18
  typedef unsigned long long int __u64; // 1.84467e+19

} // namespace ptl

#endif // _PTL_PTYPE