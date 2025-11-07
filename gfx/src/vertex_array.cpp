#include <gfx/vertex_array.h>
#include <cassert>

namespace LatticeViz::GFX
{
    VertexArray VertexArray::Create()
    {
        VertexArray va;
        glGenVertexArrays(1, &va.id);
        assert(va.id != 0 && "Failed to generate VAO");
        return va;
    }

    void VertexArray::Bind() const
    {
        glBindVertexArray(id);
    }

    void VertexArray::Unbind()
    {
        glBindVertexArray(0);
    }

    void VertexArray::EnableVertexAttrib(const VertexAttribDesc& desc) const
    {
        glEnableVertexAttribArray(desc.index);
        glVertexAttribPointer(
            desc.index,
            desc.size,
            desc.type,
            desc.normalized,
            desc.stride,
            reinterpret_cast<const void*>(desc.offset)
        );

        if (desc.divisor != 0)
        {
            glVertexAttribDivisor(desc.index, desc.divisor);
        }
        else
        {
            glVertexAttribDivisor(desc.index, 0);
        }
    }

    void VertexArray::EnableVertexAttribs(const std::initializer_list<VertexAttribDesc>& descs) const
    {
        for (const auto& desc : descs)
        {
            EnableVertexAttrib(desc);
        }
    }

    void VertexArray::BindIndexBuffer(GLuint indexBufferId) const
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferId);
    }

    void VertexArray::Destroy()
    {
        if (id != 0)
        {
            glDeleteVertexArrays(1, &id);
            id = 0;
        }
    }
}
