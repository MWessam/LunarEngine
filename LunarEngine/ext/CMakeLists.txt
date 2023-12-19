# Specify the name and source files of your executable
add_executable(LunarEngine ../LunarEngine/main.cpp)

# Link the glm and glfw libraries to your executable
target_link_libraries(LunarEngine glm::glm glfw)

# Add the glad, stb, and KHR libraries as submodules
add_subdirectory(glad)
add_subdirectory(stb)
add_subdirectory(KHR)

# Link the glad, stb, and KHR libraries to your executable
target_link_libraries(LunarEngine glad stb KHR)
