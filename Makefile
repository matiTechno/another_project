# replace ...

all:
        g++ -std=c++14 -O2 -Wall -Wextra -pedantic \
app.cpp glad.c main.cpp imgui/imgui_demo.cpp \
imgui/imgui_draw.cpp imgui/imgui_impl_glfw_gl3.cpp imgui/imgui.cpp \
-I. -I/.../glm-master -I/.../glfw-master/include \
-L/.../glfw-master/src -lglfw3 -ldl \
-framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo \
-o app
