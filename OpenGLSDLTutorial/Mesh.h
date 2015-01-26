//
//  Mesh.h
//  FirstSQLOpenGL
//
//  Created by Henry Wagner on 1/24/15.
//  Copyright (c) 2015 Henry Wagner. All rights reserved.
//

#ifndef __FirstSQLOpenGL__Mesh__
#define __FirstSQLOpenGL__Mesh__

#include <stdio.h>
#include <glm/glm.hpp>
#include <GL/glew.h>

class Vertex {
public:
    Vertex(const glm::vec3& pos) {
        this->pos = pos;
    }
protected:
private:
    glm::vec3 pos;
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
      NUM_BUFFERS
    };
    
    GLuint* m_vertexArrayObject;
    GLuint m_vertexArrayBuffers[NUM_BUFFERS];
    unsigned int m_drawCount;
};

#endif /* defined(__FirstSQLOpenGL__Mesh__) */

