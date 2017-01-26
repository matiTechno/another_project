TEMPLATE = app
CONFIG += c++14 strict_c++
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS += -pedantic

LIBS += -lglfw -lGL -ldl

SOURCES += main.cpp \
    glad.c \
    app.cpp \
    imgui/imgui.cpp \
    imgui/imgui_demo.cpp \
    imgui/imgui_draw.cpp \
    imgui/imgui_impl_glfw_gl3.cpp

HEADERS += \
    glad.h \
    app.hpp \
    input.hpp \
    mouse.hpp \
    imgui/imconfig.h \
    imgui/imgui.h \
    imgui/imgui_impl_glfw_gl3.h \
    imgui/imgui_internal.h \
    imgui/stb_rect_pack.h \
    imgui/stb_textedit.h \
    imgui/stb_truetype.h
