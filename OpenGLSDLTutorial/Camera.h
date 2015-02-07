//
//  Camera.h
//  OpenGLSDLTutorial
//
//  Created by Henry Wagner on 2/6/15.
//  Copyright (c) 2015 Henry Wagner. All rights reserved.
//

#ifndef OpenGLSDLTutorial_Camera_h
#define OpenGLSDLTutorial_Camera_h

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>

class Camera {
public:
    Camera(const glm::vec3& pos, float fov, float aspect, float zNear, float zFar) {
        m_perspective = glm::perspective(fov, aspect, zNear, zFar);
        m_position = pos;
        m_forward = glm::vec3(0,0,1);
        m_up = glm::vec3(0,1,0);
    }
    
    inline glm::mat4 GetViewProjection() const {
        return m_perspective * glm::lookAt(m_position, m_position + m_forward, m_up);
    }
protected:
private:
    glm::mat4 m_perspective;
    glm::vec3 m_position;
    glm::vec3 m_forward;
    glm::vec3 m_up;
};

#endif
