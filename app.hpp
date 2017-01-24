#ifndef APP_HPP
#define APP_HPP

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

    GLFWwindow* window;
    bool isRunning;
};

#endif // APP_HPP
