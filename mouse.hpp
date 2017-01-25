#ifndef MOUSE_HPP
#define MOUSE_HPP

#include <input.hpp>
#include <glm/vec2.hpp>

struct Mouse
{
    void begin_new_frame();

    Input<int, std::hash<int>> buttons;
    glm::vec2 position;
    float scroll_delta;
    bool hasEntered;
    bool hasLeft;
};

inline void Mouse::begin_new_frame()
{
    buttons.begin_new_frame();
    scroll_delta = 0.f;
    hasEntered = false;
    hasLeft = false;
}

#endif // MOUSE_HPP
