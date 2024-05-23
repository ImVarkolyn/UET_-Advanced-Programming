#ifndef BASE_OBJECT_H_
#define BASE_OBJECT_H_

#include "CommonFunc.h"
#include <bits/stdc++.h>

class BaseObject
{
public:
    BaseObject();
    ~BaseObject();
    void SetRect(const int& x, const int& y) {rect.x = x, rect.y = y;}
    SDL_Rect GetRect() const {return rect;}
    SDL_Texture* GetObject() const {return p_object;}

    /// Load anh bit map
    virtual bool LoadImg(std::string path, SDL_Renderer* screen);
// virtual: base class member function that you can redefine in a derived class to achieve polymorphism
    void Render(SDL_Renderer* des, const SDL_Rect* clip = NULL);
    void Free();
protected:
    SDL_Texture* p_object;
    SDL_Rect rect;
};
#endif // Base_Object_h_
