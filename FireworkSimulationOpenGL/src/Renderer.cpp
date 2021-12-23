#include "Renderer.h"

#include <iostream>

void GLClearError() {
    while (glGetError() != GL_NO_ERROR);
}

bool GLLogCall(const char* function, const char* file, int line) {
    while (GLenum error = glGetError()) {
        std::cout << "[OpenGL Error] (" << error << "): " << function <<
            "\n" << file << ":" << line << std::endl;
        return false;
    }
    return true;
}

void GLWarningCall(const char* message, const WarningType& type, const char* location) {
    switch (type) {
    case WarningType::NOT_FOUND:
        std::cout << "[" << location << "] Warning: '" << message << "' could not be found!\n";
        break;    
    case WarningType::INVALID:
        std::cout << "[" << location << "] Warning: '" << message << "' is invalid!\n";
        break;
    default:
        std::cout << "[" << location << "] Warning: '" << message << "' \n";
        break;
    }
}

void Renderer::Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const {
    shader.Bind();
    va.Bind();
    ib.Bind();
    GLCall(glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, nullptr));
}

void Renderer::Clear() const{
    GLCall(glClear(GL_COLOR_BUFFER_BIT));
}

void Renderer::EnableBlending() const{
    GLCall(glEnable(GL_BLEND));
    GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));
}