# https://eax.me/cmake/
cmake_minimum_required(VERSION 3.16) # Проверка версии CMake.
									# Если версия установленой программы
									# старее указаной, произайдёт аварийный выход.

project(sigAlarm LANGUAGES C)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED on)
set(CXX_EXTENSIONS NO)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")

add_executable(${PROJECT_NAME} main.c )		# Создает исполняемый файл с именем main
