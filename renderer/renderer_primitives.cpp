#include "renderer.h"
#include <bgfx/bgfx.h>
#include <bx/bx.h>

namespace Dodger {
  namespace Renderer {

    bgfx::ProgramHandle loadProgram(const char* vsName, const char* fsName) {
    }

    // POS COLOR VERTEX
    struct PosColorVertex {
      float m_x;
      float m_y;
      float m_z;
      uint32_t m_abgr;

      static void init() {
        ms_decl
          .begin()
          .add(bgfx::Attrib::Position, 3, bgfx::AttribType::Float)
          .add(bgfx::Attrib::Color0,   4, bgfx::AttribType::Uint8, true)
          .end();
      };

      static bgfx::VertexDecl ms_decl;
    };


    bgfx::VertexDecl PosColorVertex::ms_decl;

    static PosColorVertex s_cubeVertices[] = {
       {-1.0f,  1.0f,  1.0f, 0xff000000 },
       { 1.0f,  1.0f,  1.0f, 0xff0000ff },
       {-1.0f, -1.0f,  1.0f, 0xff00ff00 },
       { 1.0f, -1.0f,  1.0f, 0xff00ffff },
       {-1.0f,  1.0f, -1.0f, 0xffff0000 },
       { 1.0f,  1.0f, -1.0f, 0xffff00ff },
       {-1.0f, -1.0f, -1.0f, 0xffffff00 },
       { 1.0f, -1.0f, -1.0f, 0xffffffff },
    };


    static const uint16_t s_cubeTriList[] =
      {
       0, 1, 2, // 0
       1, 3, 2,
       4, 6, 5, // 2
       5, 6, 7,
       0, 2, 4, // 4
       4, 2, 6,
       1, 5, 3, // 6
       5, 7, 3,
       0, 4, 1, // 8
       4, 5, 1,
       2, 3, 6, // 10
       6, 3, 7,
      };

    bgfx::VertexBufferHandle m_vbh;
    bgfx::IndexBufferHandle m_ibh;
    bgfx::ProgramHandle m_program;

    void InitializePrimitives() {
      PosColorVertex::init();

      m_vbh = bgfx::createVertexBuffer(// Static data can be passed with bgfx::makeRef
                                       bgfx::makeRef(s_cubeVertices, sizeof(s_cubeVertices) ),
                                       PosColorVertex::ms_decl);

      m_ibh = bgfx::createIndexBuffer(// Static data can be passed with bgfx::makeRef
                                      bgfx::makeRef(s_cubeTriList, sizeof(s_cubeTriList) ));
      // m_program = loadProgram("vs_cubes", "fs_cubes");
    }
  }
}
