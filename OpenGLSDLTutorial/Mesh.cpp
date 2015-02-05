 //
//  Mesh.cpp
//  FirstSQLOpenGL
//
//  Created by Henry Wagner on 1/24/15.
//  Copyright (c) 2015 Henry Wagner. All rights reserved.

#include "Mesh.h"
#include <vector>
#include <iostream>

Mesh::Mesh(Vertex* vertices, unsigned int numVerticies) {
    m_drawCount = numVerticies;
    
    glGenVertexArrays(1, &m_vertexArrayObject);
    glBindVertexArray(m_vertexArrayObject);
    
    std::vector<glm::vec3> positions;
    std::vector<glm::vec2> textCoords;
    
    glGenBuffers(NUM_BUFFERS, m_vertexArrayBuffers);

    for (unsigned int i = 0; i < numVerticies; i++) {
        positions.push_back(*vertices[i].GetPos());
        textCoords.push_back(*vertices[i].GetTexCoord());
    }
    
    glBindBuffer(GL_ARRAY_BUFFER, m_vertexArrayBuffers[POSITION_VB]);
    glBufferData(GL_ARRAY_BUFFER, numVerticies * sizeof(positions[0]), &positions[0], GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

    glBindBuffer(GL_ARRAY_BUFFER, m_vertexArrayBuffers[TEXCOORD_VB]);
    glBufferData(GL_ARRAY_BUFFER, numVerticies * sizeof(textCoords[0]), &textCoords[0], GL_STATIC_DRAW);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);

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