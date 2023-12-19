# Specify the minimum required version of CMake
cmake_minimum_required(VERSION 3.10)

# Define your project
project(LunarEngine)

# Add paths to the compiler's header search path
include_directories(${PROJECT_SOURCE_DIR}/ext/include)
include_directories(${PROJECT_SOURCE_DIR}/ext/libs)

# List all the source files required to build the target
file(GLOB_RECURSE SOURCE_FILES
        ${PROJECT_SOURCE_DIR}/Graphics/*.cpp
        ${PROJECT_SOURCE_DIR}/RendererAPI/*.cpp
        # Add paths to other source files here
)

# Define the targets (executables or libraries) you want to build
add_executable(LunarEngine ${SOURCE_FILES})

# If you're using packages like GLFW, GLM, etc., use find_package() to locate them
# find_package(glfw3 REQUIRED)
# find_package(glm REQUIRED)

# Link the libraries to your target
# target_link_libraries(LunarEngine glfw glm)

# Optionally, you can set specific compiler options
target_compile_options(LunarEngine PRIVATE -Wall -Wextra)
