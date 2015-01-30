 //
//  Mesh.cpp
//  FirstSQLOpenGL
//
//  Created by Henry Wagner on 1/24/15.
//  Copyright (c) 2015 Henry Wagner. All rights reserved.
//

#include "Mesh.h"

Mesh::Mesh(Vertex* vertices, unsigned int numVerticies) {
    m_drawCount = numVerticies;
    
    glGenVertexArrays(1, &m_vertexArrayObject);
    glBindVertexArray(m_vertexArrayObject);
    
    glGenBuffers(NUM_BUFFERS, m_vertexArrayBuffers);
    glBindBuffer(GL_ARRAY_BUFFER, m_vertexArrayBuffers[POSITION_VB]);
    glBufferData(GL_ARRAY_BUFFER, numVerticies * sizeof(vertices[0]), vertices, GL_STATIC_DRAW);
    
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
    
    glBindVertexArray(0);
}

Mesh::~Mesh() {
    glDeleteBuffers(NUM_BUFFERS, m_vertexArrayBuffers);
    glDeleteVertexArrays(1, &m_vertexArrayObject);
}

void Mesh::Draw() {
    glBindVertexArray(m_vertexArrayObject);
    
    glDrawArrays(GL_TRIANGLES, 0, m_drawCount);
    
    glBindVertexArray(0);
}