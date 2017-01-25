#ifndef APP_HPP
#define APP_HPP

#include <input.hpp>
#include <mouse.hpp>
class GLFWwindow;

class App
{
public:

    App();
    App(const App&) = delete;
    const App& operator=(const App&) = delete;
    ~App();

private:

    void setOpengl();
    void run();
    void processInput();
    void update(float frameTime);
    void render();

    // glfw callbacks
    static void key_callback(GLFWwindow*, int key, int, int action, int);
    static void cursor_position_callback(GLFWwindow*, double xpos, double ypos);
    static void cursor_enter_callback(GLFWwindow*, int entered);
    static void scroll_callback(GLFWwindow*, double, double yoffset);
    static void mouse_button_callback(GLFWwindow*, int button, int action, int);
    static void framebuffer_size_callback(GLFWwindow*, int width, int height);
    static void window_focus_callback(GLFWwindow*, int focused);
    static void window_close_callback(GLFWwindow*);

    GLFWwindow* window;
    bool isRunning;
    static bool instance;
    static Input<int, std::hash<int>> keys;
    static Mouse mouse;
};

#endif // APP_HPP
