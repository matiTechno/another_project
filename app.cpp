#include <app.hpp>
#include <glad.h>
#include <GLFW/glfw3.h>
#include <stdexcept>
#include <iostream>
#include <chrono>

void error_callback(int error, const char* description)
{
    std::cout << "[Error: " << error << ", " << description << ']' << std::endl;
}

App::App():
    isRunning(true)
{
    glfwSetErrorCallback(error_callback);

    if(!glfwInit())
        throw std::runtime_error("[glfw initialization failed]");

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    window = glfwCreateWindow(640, 480, "My Title", nullptr, nullptr);

    if(!window)
        throw std::runtime_error("[glfw window creation failed]");

    glfwMakeContextCurrent(window);

    if(!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress)))
        throw std::runtime_error("[glad initialization failed]");

    glfwSwapInterval(1);

    setOpengl();
    run();
}

App::~App()
{
    glfwTerminate();
}

void App::setOpengl()
{

}

void App::run()
{
    auto currentTime = std::chrono::high_resolution_clock::now();

    while(isRunning)
    {
        processInput();

        auto newTime = std::chrono::high_resolution_clock::now();
        auto frameTime = std::chrono::duration_cast<std::chrono::duration<float>>(newTime - currentTime).count();
        currentTime = newTime;
        //std::cout << frameTime << std::endl;

        update(frameTime);

        render();
    }
}

void App::processInput()
{
    glfwPollEvents();

    if(glfwWindowShouldClose(window))
        isRunning = false;
}

void App::update(float dt)
{
    (void)dt;
}

void App::render()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(window);
}
