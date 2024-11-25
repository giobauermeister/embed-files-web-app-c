# Minimum CMake version
cmake_minimum_required(VERSION 3.10)
set(PROJECT_NAME SimpleServer)

# Project name and language
project(${PROJECT_NAME} C)

# Add compiler flags
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -O2")

# Specify the target executable and source files
add_executable(${PROJECT_NAME} src/main.c src/web_server.c src/embedded_files.c)

# Add mongoose source files
add_library(mongoose STATIC lib/mongoose/mongoose.c)
set_target_properties(mongoose PROPERTIES C_STANDARD 99)

# Optionally, set the C standard
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Paths to the embedded files
set(WEB_APP_DIR ${CMAKE_SOURCE_DIR}/web-app)
set(EMBED_OUTPUT_DIR ${CMAKE_BINARY_DIR})
set(EMBED_HEADER ${EMBED_OUTPUT_DIR}/embedded_files.h)

# Collect all files in the web-app directory, including subdirectories
file(GLOB_RECURSE WEB_FILES "${WEB_APP_DIR}/*")

# Generate the embedded_files.h header file using the shell script
add_custom_command(
    OUTPUT ${EMBED_HEADER}
    COMMAND ${CMAKE_SOURCE_DIR}/generate_embedded_files.sh ${EMBED_HEADER} ${WEB_FILES}
    DEPENDS ${WEB_FILES}
    COMMENT "Generating embedded_files.h with all embedded files"
)

# Add a custom target to ensure this header is generated before the build
add_custom_target(embed_files DEPENDS ${EMBED_HEADER})

# Ensure the embed_files target runs before the main executable is built
add_dependencies(${PROJECT_NAME} embed_files)

# Include the generated headers
include_directories(${EMBED_OUTPUT_DIR})

# Link the embedded resource library
target_link_libraries(${PROJECT_NAME} PRIVATE mongoose)

# Include directories
target_include_directories(${PROJECT_NAME} PRIVATE 
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/lib/mongoose
)
