#pragma once
#include <initializer_list>

#include "glad/glad.h"

namespace LatticeViz::GFX
{
    struct VertexAttribDesc
    {
        GLuint index;
        GLint size;
        GLenum type;
        GLboolean normalized;
        GLsizei stride;
        uintptr_t offset;
        GLuint divisor;
    };

    struct VertexArray
    {
        GLuint id = 0;

        static VertexArray Create();

        void Bind() const;
        static void Unbind();

        void EnableVertexAttrib(const VertexAttribDesc& desc) const;
        void EnableVertexAttribs(const std::initializer_list<VertexAttribDesc>& descs) const;

        void BindIndexBuffer(GLuint indexBufferId) const;

        void Destroy();
    };
}
