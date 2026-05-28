#include <OGL3D/Graphics/OGraphicsEngine.h>
#include <OGL3D/Graphics/OVertexArrayObject.h>
#include <OGL3D/Graphics/OUniformBuffer.h>
#include <OGL3D/Graphics/OShaderProgram.h>
#include <glad/glad.h>
#include <glad/glad_wgl.h>
#include <assert.h>
#include <OGL3D/Window/OWindow.h>
#include <stdexcept>

OGraphicsEngine::OGraphicsEngine()
{
    WNDCLASSEX windowClass = {};
    windowClass.style = CS_OWNDC;
    windowClass.lpfnWndProc = DefWindowProcA;
    windowClass.lpszClassName = L"OGL3DDummyWindow";
    windowClass.cbSize = sizeof(WNDCLASSEX);

    auto classId = RegisterClassEx(&windowClass);

    HWND dummyWindow = CreateWindowEx(
        0,
        MAKEINTATOM(classId),
        L"OGL3DDummyWindow",
        0,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        0,
        0,
        windowClass.hInstance,
        0);

    assert(dummyWindow);

    HDC dummyDC = GetDC(dummyWindow);

    PIXELFORMATDESCRIPTOR pfd = {};
    pfd.nSize = sizeof(pfd);
    pfd.nVersion = 1;
    pfd.iPixelType = PFD_TYPE_RGBA;
    pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
    pfd.cColorBits = 32;
    pfd.cAlphaBits = 8;
    pfd.iLayerType = PFD_MAIN_PLANE;
    pfd.cDepthBits = 24;
    pfd.cStencilBits = 8;

    int pixelFormat = ChoosePixelFormat(dummyDC, &pfd);
    SetPixelFormat(dummyDC, pixelFormat, &pfd);


    HGLRC dummyContext = wglCreateContext(dummyDC);
    assert(dummyContext);

    bool res = wglMakeCurrent(dummyDC, dummyContext);
    assert(res);

    if (!gladLoadWGL(dummyDC))
        OGL3D_ERROR("OGraphicsEngine - gladLoadWGL failed");

    if (!gladLoadGL())
        OGL3D_ERROR("OGraphicsEngine - gladLoadGL failed");

    wglMakeCurrent(dummyDC, 0);
    wglDeleteContext(dummyContext);
    ReleaseDC(dummyWindow, dummyDC);
    DestroyWindow(dummyWindow);
}


OGraphicsEngine::~OGraphicsEngine()
{
}

OVertexArrayObjectPtr OGraphicsEngine::createVertexArrayObject(const OVertexBufferDesc& vbDesc)
{
    return std::make_shared<OVertexArrayObject>(vbDesc);
}

OVertexArrayObjectPtr OGraphicsEngine::createVertexArrayObject(const OVertexBufferDesc& vbDesc, const OIndexBufferDesc& ibDesc)
{
    return std::make_shared<OVertexArrayObject>(vbDesc, ibDesc);
}

OUniformBufferPtr OGraphicsEngine::createUniformBuffer(const OUniformBufferDesc& desc)
{
    return std::make_shared<OUniformBuffer>(desc);
}

OShaderProgramPtr OGraphicsEngine::createShaderProgram(const OShaderProgramDesc& desc)
{
    return std::make_shared<OShaderProgram>(desc);
}

void OGraphicsEngine::clear(const OVec4& color)
{
    glClearColor(color.x, color.y, color.z, color.w);
    glClear(GL_COLOR_BUFFER_BIT);
}

void OGraphicsEngine::setFaceCulling(const OCullType& type)
{
    auto cullType = GL_BACK;

    if (type == OCullType::FrontFace) cullType = GL_FRONT;
    else if (type == OCullType::BackFace) cullType = GL_BACK;
    else if (type == OCullType::Both) cullType = GL_FRONT_AND_BACK;

    glEnable(GL_CULL_FACE);
    glCullFace(cullType);
}

void OGraphicsEngine::setWindingOrder(const OWindingOrder& order)
{
    auto orderType = GL_CW;

    if (order == OWindingOrder::ClockWise) orderType = GL_CW;
    else if (order == OWindingOrder::CounterClockWise) orderType = GL_CCW;

    glFrontFace(orderType);
}

void OGraphicsEngine::setViewport(const ORect& size)
{
    glViewport(size.left,size.top,size.width,size.height);
}

void OGraphicsEngine::setVertexArrayObject(const OVertexArrayObjectPtr& vao)
{
    glBindVertexArray(vao->getId());
}

void OGraphicsEngine::setUniformBuffer(const OUniformBufferPtr& buffer, ui32 slot)
{
    glBindBufferBase(GL_UNIFORM_BUFFER, slot, buffer->getId());
}

void OGraphicsEngine::setShaderProgram(const OShaderProgramPtr& program)
{
    glUseProgram(program->getId());
}

void OGraphicsEngine::drawTriangles(const OTriangleType& triangleType, ui32 vertexCount, ui32 offset)
{
    auto glTriType = GL_TRIANGLES;

    switch (triangleType)
    {
    case OTriangleType::TriangleList: { glTriType = GL_TRIANGLES; break; }
    case OTriangleType::TriangleStrip: { glTriType = GL_TRIANGLE_STRIP; break; }
    }

    glDrawArrays(glTriType, offset, vertexCount);
}

void OGraphicsEngine::drawIndexedTriangles(const OTriangleType& triangleType, ui32 indicesCount)
{
    auto glTriType = GL_TRIANGLES;

    switch (triangleType)
    {
    case OTriangleType::TriangleList: { glTriType = GL_TRIANGLES; break; }
    case OTriangleType::TriangleStrip: { glTriType = GL_TRIANGLE_STRIP; break; }
    }

    glDrawElements(glTriType, indicesCount, GL_UNSIGNED_INT, nullptr);
}
