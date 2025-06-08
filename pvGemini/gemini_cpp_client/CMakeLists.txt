# CMakeLists.txt
cmake_minimum_required(VERSION 3.10)
project(GeminiCppClient CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

# Adiciona o diretório atual onde json.hpp está
include_directories(.)

# Adiciona o executável
add_executable(gemini_client main.cpp)

# Encontra e linka a biblioteca cURL
find_package(CURL REQUIRED)

# Adiciona os diretórios de include do cURL
# Isso é importante para o compilador encontrar curl/curl.h
include_directories(${CURL_INCLUDE_DIRS})

# Linka a biblioteca cURL usando a variável de CMake
target_link_libraries(gemini_client PRIVATE ${CURL_LIBRARIES})
