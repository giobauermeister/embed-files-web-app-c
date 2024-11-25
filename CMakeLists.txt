# Minimum CMake version
cmake_minimum_required(VERSION 3.10)
set(PROJECT_NAME SimpleServer)

# Project name and language
project(${PROJECT_NAME} C)

# Add compiler flags
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -O2")

# Specify the target executable and source files
add_executable(${PROJECT_NAME} src/main.c)

# Add mongoose source files
add_library(mongoose STATIC lib/mongoose/mongoose.c)
set_target_properties(mongoose PROPERTIES C_STANDARD 99)

# Optionally, set the C standard
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Paths to the embedded files
set(WEB_APP_DIR ${CMAKE_SOURCE_DIR}/web-app)
set(EMBED_OUTPUT_DIR ${CMAKE_BINARY_DIR})

# Embed index.html into a header with a clean name
add_custom_command(
    OUTPUT ${EMBED_OUTPUT_DIR}/index_html.h
    COMMAND xxd -i ${WEB_APP_DIR}/index.html > ${EMBED_OUTPUT_DIR}/index_html.h.tmp
    COMMAND sed 's/_home_.*_index_html/index_html/g' ${EMBED_OUTPUT_DIR}/index_html.h.tmp > ${EMBED_OUTPUT_DIR}/index_html.h
    COMMAND rm ${EMBED_OUTPUT_DIR}/index_html.h.tmp
    DEPENDS ${WEB_APP_DIR}/index.html
    COMMENT "Embedding index.html into index_html.h with clean variable names"
)

# Embed favicon.ico into a header with a clean name
add_custom_command(
    OUTPUT ${EMBED_OUTPUT_DIR}/favicon_ico.h
    COMMAND xxd -i ${WEB_APP_DIR}/favicon.ico > ${EMBED_OUTPUT_DIR}/favicon_ico.h.tmp
    COMMAND sed 's/_home_.*_favicon_ico/favicon_ico/g' ${EMBED_OUTPUT_DIR}/favicon_ico.h.tmp > ${EMBED_OUTPUT_DIR}/favicon_ico.h
    COMMAND rm ${EMBED_OUTPUT_DIR}/favicon_ico.h.tmp
    DEPENDS ${WEB_APP_DIR}/favicon.ico
    COMMENT "Embedding favicon.ico into favicon_ico.h with clean variable names"
)

# Add a custom target to ensure these headers are generated before the build
add_custom_target(embed_files
    DEPENDS ${EMBED_OUTPUT_DIR}/index_html.h ${EMBED_OUTPUT_DIR}/favicon_ico.h
)

# Ensure the embed_files target runs before the main executable is built
add_dependencies(${PROJECT_NAME} embed_files)

# Include the generated headers
include_directories(${EMBED_OUTPUT_DIR})

# Include directories
target_include_directories(${PROJECT_NAME} PRIVATE 
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/lib/mongoose
    # ${CMAKE_SOURCE_DIR}/lib/ArduinoJson
)