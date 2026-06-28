// Ad Maiorem Dei Gloriam!
#ifndef OS_DEFINES_HPP
#define OS_DEFINES_HPP


#ifdef _WIN32 // WINDOWS
#define OS_CONSOLE_CLEAR() system("cls");
#else // UNIX
#define OS_CONSOLE_CLEAR() system("clear");
#endif



#endif