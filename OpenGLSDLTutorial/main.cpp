#include <iostream>
#include <GL/glew.h>
#include <SDL2/SDL.h>

#include "Display.h"
#include "Shader.h"
#include "Mesh.h"
#include "Texture.h"

static const int DISPLAY_WIDTH = 800;
static const int DISPLAY_HEIGHT = 600;

int main() {
    Display display(DISPLAY_WIDTH, DISPLAY_HEIGHT, "OpenGL Tutorial");

    Vertex vertices[] = { Vertex(glm::vec3(-0.5, -0.5, 0.0), glm::vec2(0.0, 0.0)),
                          Vertex(glm::vec3( 0.0,  0.5, 0.0), glm::vec2(0.5, 1.0)),
                          Vertex(glm::vec3( 0.5, -0.5, 0.0), glm::vec2(1.0, 0.0))};
    
    Mesh mesh(vertices, sizeof(vertices)/sizeof(vertices[0]));
    Shader shader("./res/basicShader");
    Texture texture("./res/bricks.jpg");
        
    while (!display.IsClosed()) {
        display.Clear(0.0f, 0.15f, 0.3f, 1.0f);
        
        shader.Bind();
        texture.Bind(0);
        mesh.Draw();
        
        display.Update();
    }
    
    return 0;
}