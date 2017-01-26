#include <app.hpp>
#include <glad.h>
#include <GLFW/glfw3.h>
#include <stdexcept>
#include <iostream>
#include <chrono>
#include <string>
#include <cassert>
#include <imgui/imgui.h>
#include <imgui/imgui_impl_glfw_gl3.h>

void error_callback(int error, const char* description)
{
    std::cout << "[Error: " << error << ", " << description << ']' << std::endl;
}

bool App::instance = false;
Input<int, std::hash<int>> App::keys;
Mouse App::mouse;

App::App():
    isRunning(true)
{
    assert(!instance);
    instance = true;

    glfwSetErrorCallback(error_callback);

    std::cout << "glfw compile time info: " << glfwGetVersionString() << std::endl;

    int major, minor, revision;
    glfwGetVersion(&major, &minor, &revision);
    std::string version = std::to_string(major) + '.' + std::to_string(minor) + '.' + std::to_string(revision);
    std::cout << "runtime glfw version: " + version << std::endl;

    if(!glfwInit())
        throw std::runtime_error("[glfw initialization failed]");

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_SAMPLES, 4);
    window = glfwCreateWindow(640, 480, "My Title", nullptr, nullptr);

    if(!window)
        throw std::runtime_error("[glfw window creation failed]");

    glfwMakeContextCurrent(window);

    if(!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress)))
        throw std::runtime_error("[glad initialization failed]");

    std::cout << "vendor: " << glGetString(GL_VENDOR) << std::endl;
    std::cout << "renderer: " << glGetString(GL_RENDERER) << std::endl;
    std::cout << "gl version: " << glGetString(GL_VERSION) << std::endl;

    glfwSwapInterval(1);

    glfwSetKeyCallback(window, key_callback);
    glfwSetMouseButtonCallback(window, mouse_button_callback);
    glfwSetCursorPosCallback(window, cursor_position_callback);
    glfwSetScrollCallback(window, scroll_callback);
    glfwSetCursorEnterCallback(window, cursor_enter_callback);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetWindowFocusCallback(window, window_focus_callback);
    glfwSetWindowCloseCallback(window, window_close_callback);

    setOpengl();
    run();
}

App::~App()
{
    ImGui_ImplGlfwGL3_Shutdown();
    glfwTerminate();
}

void App::setOpengl()
{

}

void App::run()
{
    ImGui_ImplGlfwGL3_Init(window, true);

    auto currentTime = std::chrono::high_resolution_clock::now();

    while(isRunning)
    {
        processInput();

        ImGui_ImplGlfwGL3_NewFrame(mouse, keys);
        ImGui::ShowTestWindow();

        ImGui::Begin("Another Window");
        ImGui::Text("Hello");
        if(ImGui::Button("exit"))
        {
            isRunning = false;
        }
        ImGui::End();

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
    keys.begin_new_frame();
    mouse.begin_new_frame();

    glfwPollEvents();

    if(glfwWindowShouldClose(window))
        isRunning = false;

    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    glViewport(0, 0, width, height);
}

void App::update(float dt)
{
    (void)dt;
}

void App::render()
{
    glClear(GL_COLOR_BUFFER_BIT);
    ImGui::Render();
    glfwSwapBuffers(window);
}

void App::key_callback(GLFWwindow*, int key, int, int action, int)
{
    if(action == GLFW_PRESS)
        keys.pressEvent(key);
    else if(action == GLFW_RELEASE)
        keys.releaseEvent(key);
}

void App::mouse_button_callback(GLFWwindow*, int button, int action, int)
{
    if(action == GLFW_PRESS)
        mouse.buttons.pressEvent(button);
    else if(action == GLFW_RELEASE)
        mouse.buttons.releaseEvent(button);
}

void App::cursor_position_callback(GLFWwindow*, double xpos, double ypos)
{
    mouse.position.x = static_cast<float>(xpos);
    mouse.position.y = static_cast<float>(ypos);
}

void App::scroll_callback(GLFWwindow*, double, double yoffset)
{
    mouse.scroll_delta = static_cast<float>(yoffset);
}

void App::cursor_enter_callback(GLFWwindow*, int entered)
{
    if(entered)
        mouse.hasEntered = true;
    else
        mouse.hasLeft = true;
}

void App::framebuffer_size_callback(GLFWwindow*, int width, int height)
{
    (void)width;
    (void)(height);
}

void App::window_focus_callback(GLFWwindow*, int focused)
{
    if(focused)
    {

    }
    else
    {

    }
}

void App::window_close_callback(GLFWwindow*)
{

}
