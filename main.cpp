// main.cpp -*- C++ -*-

/*
 * Copyright (c) S-Patriarch, 2023
 *
 * Итоговый проект по модулю 'Основные конструкции С++'
 * курса 'Разработчик С++'.
 * Терминальный (консольный) чат.
 */

#include "user.h"
#include "/home/chaos/c++/ptl/ptype.h"
#include "/home/chaos/c++/ptl/pconio.h"
#include "/home/chaos/c++/ptl/pcolor.h"
#include "/home/chaos/c++/ptl/pvector.h"
#include <iostream>
#include <exception>
#include <string>

namespace chat
{
  ptl::__u32  ID{ 0 }; // ID пользователя

  /** Определение функций.
   */
  auto
  get_info() -> void;
  auto
  user_authorization(ptl::pvector<chat::User>&) -> void;
  auto
  check_out_message(ptl::pvector<chat::User>&) -> void;
  auto
  in_record_message(ptl::pvector<chat::User>&) -> void;

} // namespace chat 

/*
 * Точка входа...
 */ 
auto
main() -> int
{
  ptl::setlocale_WIN32_rus();

  chat::get_info();

  try
    {
      ptl::pcolor __c;

      /** Создаем динамическое хранилище пользователей чата.
       */
      ptl::pvector<chat::User> __user(chat::ID+1);

      /** Добавляем одного (первого) пользователя с ID:1, чтоб был.
       */
      __user[chat::ID].set_user("Patriarch", "apsk0529-2@mail.ru", 
                                "QQqq1122+", chat::ID+1);


      __user.resize(__user.size() + 1);
      chat::ID = __user.size();
      __user[chat::ID-1].set_user("Chaos", "apsk0529@mail.ru", 
                                  "ZZzz1122+", chat::ID);


      __user.resize(__user.size() + 1);
      chat::ID = __user.size();
      __user[chat::ID-1].set_user("Alex", "Alex", 
                                  "Alex", chat::ID);


      /** Запускаем процедуру авторизации / регистрации пользователя.
       */
      chat::user_authorization(__user);

      /** Приглашаем авторизовавшегося / зарегистрировавшегося 
       *  пользователя к дальнейшей работе в чате.
       */      
      chat::get_info();
      std::cout
        << __c.esc_tb(2)
        << "chat"
        << __c.esc_c()
        << ": Добро пожаловать "
        << __user[chat::ID-1].get_user_name()
        << "..."
        << std::endl;

//-------------------------------------------------------
// Тестовое формирование сообщений
//
__user[2].record_message("Chaos", "Это пробное сообщение");
__user[2].record_message("Patriarch", "Привет. Еще одно сообщение.");
//
//
//-------------------------------------------------------

      chat::check_out_message(__user);

      std::cout << std::endl;

      __user[chat::ID-1].out_user_name();

      chat::in_record_message(__user);

      std::cout << std::endl << std::endl;
    }
  catch (std::exception& __ex)
    {
      std::cout
        << __ex.what()
        << std::endl;
    }

  return 0;
}

namespace chat
{
  /* 
   * Функция выводит информацию об управляющих
   * параметрах работы чата.
   */
  auto
  get_info() -> void
  {
    ptl::clear();

    std::cout
      << "chat 1.0 Терминальный (консольный) чат.\n"
      << "Использование:\n"
      << "User:\n"
      << "к: [имя пользователя] или [управляющий параметр]\n"
      << "ч: [сообщение для пользователя]\n\n"
      << "Управляющие параметры:\n"
      << "  -h, -?  вызов информации о параметрах чата\n"
      << "  -q      завершить работу чата\n"
      << "  -c      сменить пользователя\n"
      << "  -e      редактировать данные пользователя\n"
      << std::endl;
  }

  /*
   * Функция авторизации пользователя.
   * Устанавливает ID авторизованного или вновь зарегистрированного
   * пользователя.
   */
  auto
  user_authorization(ptl::pvector<chat::User>& __user) -> void
  {
    std::string __name{ };
    std::string __login{ };
    std::string __password{ };

    ptl::pcolor __c;

    std::cout
      << __c.esc_tb(2)
      << "chat"
      << __c.esc_c()
      << ": Авторизация пользователя..."
      << std::endl;

    /** Ввод логина пользователя.
     */
    std::cout
      << "Логин:"
      << std::endl;

    std::cout << __c.esc_tb(7);
    std::cin.clear();
    std::cin >> __login;
    std::cout << __c.esc_c();

    /** Проверка введенного логина на наличие.
     */
    for (ptl::__u32 __i{0}; __i < __user.size(); ++__i)
      {
        bool __flag{ false };
        if (__user[__i].get_user_login() == __login)
          {
            chat::ID = __user[__i].get_user_id();
            __flag   = true;
          }
        if (__flag) break;
      }

    if (chat::ID != 0)
      {
        /** Если введенный логин найден среди зарегистрированных
         *  пользователей чата, то проводим идентификацию пароля
         *  данного пользователя.
         */

        /** Ввод пароля пользователя.
         */
        std::cout
          << "Пароль:"
          << std::endl;

        std::cout << __c.esc_tb(7);
        std::cin.clear();
        std::cin >> __password;
        std::cout << __c.esc_c();

        /** Проверка введенного пароля на идентичность.
         */
        while (__user[chat::ID-1].get_user_password() != __password)
          {
            std::cout
              << __c.esc_tb(2)
              << "\nchat"
              << __c.esc_c()
              << ": Пароль введен не верно..."
              << std::endl;

            std::cout
              << "Пароль:"
              << std::endl;

            std::cout << __c.esc_tb(7);
            std::cin.clear();
            std::cin >> __password;
            std::cout << __c.esc_c();
          }
      }
    else
      { 
        /** Если введенный логин не найден среди зарегистрированных
         *  пользователей чата, то проводим процедуру регистрацию в
         *  качестве нового пользователя.
         */

        std::cout
          << __c.esc_tb(2)
          << "\nchat"
          << __c.esc_c()
          << ": Пользователь с таким логином не зарегистрирован.\n"
          << "Пройдите регистрацию в качестве нового пользователя..."
          << std::endl;

        std::cout
          << __c.esc_tb(2)
          << "\nchat"
          << __c.esc_c()
          << ": Регистрация пользователя..."
          << std::endl;

        std::cout
          << "Имя:"
          << std::endl;
        std::cout << __c.esc_tb(7);
        std::cin.clear();
        std::cin >> __name;
        std::cout << __c.esc_c();

        /** Ввод логина и его проверка на наличие.
         */
        bool __flag{ false };
        do
          {
            std::cout
              << "Логин:"
              << std::endl;
            std::cout << __c.esc_tb(7);
            std::cin.clear();
            std::cin >> __login;
            std::cout << __c.esc_c();

            for (ptl::__u32 __i{0}; __i < __user.size(); ++__i)
              {
                if (__user[__i].get_user_login() != __login)
                  __flag = true;
                else
                  {
                    std::cout
                      << __c.esc_tb(2)
                      << "\nchat"
                      << __c.esc_c()
                      << ": Такой логин уже существует..."
                      << std::endl;
                    __flag = false;
                    break;
                  }
              }
          }
        while (!__flag);

        std::cout
          << "Пароль:"
          << std::endl;
        std::cout << __c.esc_tb(7);
        std::cin.clear();
        std::cin >> __password;
        std::cout << __c.esc_c();

        /** Прописываем нового пользователя в динамическое
         *  хранилище пользователей.
         */
        __user.resize(__user.size() + 1);
        chat::ID = __user.size();
        __user[chat::ID-1].set_user(__name, __login, __password, chat::ID);
      }
  }

  /*
   * Функция проверяет наличие сообщений для авторизованного 
   * пользователя и при их наличии выводит в терминал.
   */
  auto
  check_out_message(ptl::pvector<chat::User>& __user) -> void
  {
    ptl::pcolor __c;

    if (__user[chat::ID-1].get_msg_quantity() != 0)
      {
        std::cout
          << __c.esc_tb(2)
          << "chat"
          << __c.esc_c()
          << ": Для вас есть сообщения..."
          << std::endl;

        __user[chat::ID-1].out_message();
        __user[chat::ID-1].clear_msg_quantity();
      }
    else
      {
        std::cout
          << __c.esc_tb(2)
          << "chat"
          << __c.esc_c()
          << ": Для вас нет сообщений..."
          << std::endl;
      }
  }

  /*
   * Функция запрашивает для кого сообщение, само сообщение и
   * пулученную информацию отписывает пользователю для
   * которого она предназначена.
   */
  auto
  in_record_message(ptl::pvector<chat::User>& __user) -> void
  {
    std::string __whom{ };
    std::cout << "\nк: ";
    std::cin.clear();
    std::cin >> __whom;

    std::string __what{ };
    std::cout << "ч: ";
    std::cin.clear();
    std::cin >> __what;

    /** Проверка логина и запись сообщения.
     */
    for (ptl::__u32 __i{0}; __i < __user.size(); ++__i)
      {
        bool __flag{ false };
        if (__user[__i].get_user_name() == __whom)
          {
            __user[__i].record_message(__user[__i].get_user_name(), __what);
            __flag = true;
          }
        if (__flag) break;
      }
  }

} // namespace chat