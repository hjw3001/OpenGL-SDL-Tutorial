//
//  Shader.h
//  FirstSQLOpenGL
//
//  Created by Henry Wagner on 1/23/15.
//  Copyright (c) 2015 Henry Wagner. All rights reserved.
//

#ifndef __FirstSQLOpenGL__Shader__
#define __FirstSQLOpenGL__Shader__

#include <stdio.h>
#include <string>
#include <GL/glew.h>

class Shader {
public:
    Shader(const std::string& filename);
    
    void Bind();

    virtual ~Shader();

protected:
private:
    static const unsigned int NUM_SHADERS = 2;
    Shader(const Shader& other) {}
    void operator=(const Shader& other) {}
    
    std::string LoadShader(const std::string& fileName);
    void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage);
    GLuint CreateShader(const std::string& text, unsigned int shaderType);
    
    GLuint m_program;
    GLuint m_shaders[NUM_SHADERS];
};


#endif /* defined(__FirstSQLOpenGL__Shader__) */
