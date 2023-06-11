#include "Renderer.h"

void Renderer::Update()
{
    
    glfwSwapBuffers(windowContext);
    glfwPollEvents();
}
