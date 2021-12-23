#pragma once

#include <GL/glew.h>

#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Shader.h"

#define ASSERT(x) if (!(x)) __debugbreak();
#define GLCall(x) GLClearError();\
    x;\
    ASSERT(GLLogCall(#x, __FILE__, __LINE__));
#define GLWarning(x, y) GLWarningCall(x, y, __FUNCTION__);

enum WarningType
{
    NOT_FOUND,
    INVALID
};

void GLClearError();
bool GLLogCall(const char* function, const char* file, int line);
void GLWarningCall(const char* message, const WarningType& type, const char* location);

class Renderer {
public:
    void Clear() const;
    void EnableBlending() const;
    void Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const;
};