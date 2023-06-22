// -*- C++ -*-

/*
 * Copyright (c) S-Patriarch, 2023
 *
 * Описание библиотеки для работы с исключениями - exception.
 */

/**
 *  (PTL) Patriarch library : pexcept.h
 */

#pragma once
#if !defined(_PTL_PEXCEPT_H)
#define _PTL_PEXCEPT_H

#include <exception>

/* 
 * Пример использования данного класса исключений.
 * В коде программы бросается исключение следующим образом.
 * @code
 *   throw ptl::pexception( "E: Message to exception." );
 * @endcode
 * 
 * Ловится данное исключение следующим образом.
 * @code
 *   try
 *     {
 *     throw ...
 *     }
 *   catch ( std::exception& ex )
 *     {
 *     std::cout << "Поймано исключение: " 
 *               << ex.what() 
 *               << std::endl;
 *     }
 * @endcode
 */

namespace ptl
  {

  class pexception final 
    : public std::exception
    {
    private:
      const char*  _M_message{ }; // Сообщение для исключения

    public:
      pexception( const char* __message )
        : std::exception(), 
        _M_message( __message ) 
        { }

      ~pexception() 
        { }

      /* 
       * Перегрузка метода what() стандартного класса exception.
       */
      virtual const char*
      what() const noexcept override
        { return _M_message; }
    };

  } // namespace ptl

#endif // _PTL_PEXCEPT_H