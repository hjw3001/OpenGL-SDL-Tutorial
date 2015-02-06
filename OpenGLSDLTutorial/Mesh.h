//
//  Mesh.h
//  FirstSDLOpenGL
//
//  Created by Henry Wagner on 1/24/15.
//  Copyright (c) 2015 Henry Wagner. All rights reserved.

#ifndef __FirstSDLOpenGL__Mesh__
#define __FirstSDLOpenGL__Mesh__

#include <stdio.h>
#include <glm/glm.hpp>
#include <GL/glew.h>

class Vertex {
public:
    Vertex(const glm::vec3& pos, const glm::vec2& textCoord) :
        m_pos(pos),
        m_texCoord(textCoord) {}
    
    inline glm::vec3& GetPos() { return m_pos; }
    inline glm::vec2& GetTexCoord() { return m_texCoord; }
    
protected:
private:
    glm::vec3 m_pos;
    glm::vec2 m_texCoord;
};

class Mesh {
public:
    Mesh(Vertex* vertices, unsigned int numVerticies);
    
    void Draw();
    
    virtual ~Mesh();
    
protected:
private:
    Mesh(const Mesh& other) {}
    void operator=(const Mesh& other) {}
    
    enum {
      POSITION_VB,
      TEXCOORD_VB,
      NUM_BUFFERS
    };
    
    GLuint m_vertexArrayObject;
    GLuint m_vertexArrayBuffers[NUM_BUFFERS];
    unsigned int m_drawCount;
};

#endif /* defined(__FirstSDLOpenGL__Mesh__) */

