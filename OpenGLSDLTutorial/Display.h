//
//  Display.h
//  FirstSDLOpenGL
//
//  Created by Henry Wagner on 1/22/15.
//  Copyright (c) 2015 Henry Wagner. All rights reserved.
//

#ifndef __FirstSDLOpenGL__Display__
#define __FirstSDLOpenGL__Display__

#include <string>
#include <SDL2/SDL.h>

class Display {
public:
    Display(int width, int height, const std::string& title);
    
    void Clear(float red, float green, float blue, float alpha);
    void Update();
    bool IsClosed();
    
    virtual ~Display();
    
protected:
private:
    Display(const Display& other) {}
    void operator=(const Display& other) {}
    
    SDL_Window* m_window;
    SDL_GLContext m_glContext;
    bool m_isClosed;
};

#endif /* defined(__FirstSDLOpenGL__Display__) */
