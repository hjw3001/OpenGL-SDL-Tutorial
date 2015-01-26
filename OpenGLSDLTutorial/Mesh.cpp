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
    
    glGenVertexArrays(1, m_vertexArrayObject);
}

Mesh::~Mesh() {
    glDeleteVertexArrays(1, m_vertexArrayObject);
}

void Mesh::Draw() {
    
}