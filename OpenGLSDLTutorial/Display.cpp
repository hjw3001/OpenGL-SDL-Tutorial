//
//  Display.cpp
//  FirstSDLOpenGL
//
//  Created by Henry Wagner on 1/22/15.
//  Copyright (c) 2015 Henry Wagner. All rights reserved.
//

#include "Display.h"
#include <iostream>
#include <GL/glew.h>

Display::Display(int width, int height, const std::string& title) {
    std::cout << "Constructor!" << std::endl;
    SDL_Init(SDL_INIT_EVERYTHING);
    
    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    
    m_window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL);
    m_glContext = SDL_GL_CreateContext(m_window);
    
    glewExperimental = GL_TRUE;
    GLenum status = glewInit();
    
    if (status != GLEW_OK) {
        std::cerr << "Glew failed to initialize" << std::endl;
    }
    
    m_isClosed = false;
}

Display::~Display() {
    std::cout << "Destructor!" << std::endl;
    SDL_GL_DeleteContext(m_glContext);
    SDL_DestroyWindow(m_window);
    SDL_Quit();
}

void Display::Clear(float red, float green, float blue, float alpha) {
    glClearColor(red, green, blue, alpha);
    glClear(GL_COLOR_BUFFER_BIT);
}

bool Display::IsClosed() {
    return m_isClosed;
}

void Display::Update() {
    SDL_GL_SwapWindow(m_window);
    
    SDL_Event e;
    
    while (SDL_PollEvent(&e)) {
        if (e.type == SDL_QUIT) {
            m_isClosed = true;
        }
    }
}