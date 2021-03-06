//
//  Shader.h
//  FirstSDLOpenGL
//
//  Created by Henry Wagner on 1/23/15.
//  Copyright (c) 2015 Henry Wagner. All rights reserved.
//

#ifndef __FirstSDLOpenGL__Shader__
#define __FirstSDLOpenGL__Shader__

#include <stdio.h>
#include <string>
#include <GL/glew.h>
#include "Transform.h"
#include "Camera.h"

class Shader {
public:
    Shader(const std::string& filename);
    
    void Bind();
    void Update(const Transform& transform, const Camera& camera);

    virtual ~Shader();

protected:
private:
    static const unsigned int NUM_SHADERS = 2;
    Shader(const Shader& other) {}
    void operator=(const Shader& other) {}
    
    std::string LoadShader(const std::string& fileName);
    void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage);
    GLuint CreateShader(const std::string& text, unsigned int shaderType);
    
    enum {
        TRANSFORM_U,
        NUM_UNIFORMS
    };
    
    GLuint m_program;
    GLuint m_shaders[NUM_SHADERS];
    GLuint m_uniforms[NUM_UNIFORMS];
};


#endif /* defined(__FirstSDLOpenGL__Shader__) */
