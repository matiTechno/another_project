#ifndef INPUT_HPP
#define INPUT_HPP

#include <unordered_map>

template<typename T, typename Hash>
class Input
{
public:
    void start_new_frame();
    void pressEvent(T code);
    void releaseEvent(T code);

    bool wasPressed(T code) const;
    bool wasReleased(T code) const;
    bool isPressed(T code) const;

private:
    std::unordered_map<T, bool, Hash> map1;
    std::unordered_map<T, bool, Hash> map2;
    std::unordered_map<T, bool, Hash> map3;
};

template<typename T, typename Hash>
void Input<T, Hash>::start_new_frame()
{
    map1.clear();
    map2.clear();
}

template<typename T, typename Hash>
void Input<T, Hash>::pressEvent(T code)
{
    map1[code] = true;
    map3[code] = true;
}

template<typename T, typename Hash>
void Input<T, Hash>::releaseEvent(T code)
{
    map2[code] = true;
    map3.erase(code);
}

template<typename T, typename Hash>
bool Input<T, Hash>::wasPressed(T code) const
{
    auto i = map1.find(code);

    if(i == map1.end())
        return false;
    else
        return true;
}

template<typename T, typename Hash>
bool Input<T, Hash>::wasReleased(T code) const
{
    auto i = map2.find(code);

    if(i == map2.end())
        return false;
    else
        return true;
}

template<typename T, typename Hash>
bool Input<T, Hash>::isPressed(T code) const
{
    auto i = map3.find(code);

    if(i == map3.end())
        return false;
    else
        return true;
}

#endif // INPUT_HPP
