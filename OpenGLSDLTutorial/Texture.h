//
//  Texture.h
//  OpenGLSDLTutorial
//
//  Created by Henry Wagner on 1/30/15.
//  Copyright (c) 2015 Henry Wagner. All rights reserved.
//

#ifndef __OpenGLSDLTutorial__Texture__
#define __OpenGLSDLTutorial__Texture__

#include <string>
#include <GL/glew.h>

class Texture {
public:
    Texture(const std::string& filename);
    
    void Bind(unsigned int unit);
    
    virtual ~Texture();
    
protected:
private:
    Texture(const Texture& other) {}
    void operator=(const Texture& other) {}
    
    GLuint m_texture;
};

#endif /* defined(__OpenGLSDLTutorial__Texture__) */
