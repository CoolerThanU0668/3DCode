TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_MACOSX_DEPLOYMENT_TARGET = 10.15

INCLUDEPATH += OGL3D/include
INCLUDEPATH += OGL3D/source
INCLUDEPATH += OGL3D/vendor/glad/include

win32: {
    SOURCES += \
    OGL3D/source/OGL3D/Game/Win32/CWin32Game.cpp \
    OGL3D/source/OGL3D/Graphics/Win32/CWin32GraphicsEngine.cpp \
    OGL3D/source/OGL3D/Window/CWin32Window.cpp\
    OGL3D/vendor/glad/src/glad_wgl.c

    HEADERS+=\
        OGL3D/vendor/glad/include/glad/glad_wgl.h
}
SOURCES += \
    Game/main.cpp \
    OGL3D/source/OGL3D/Game/OGame.cpp \
    OGL3D/source/OGL3D/Graphics/OGraphicsEngine.cpp \
    OGL3D/source/OGL3D/Graphics/OVertexArrayObject.cpp \
    OGL3D/source/OGL3D/Graphics/OShaderProgram.cpp \
    OGL3D/source/OGL3D/Graphics/OUniformBuffer.cpp \
    OGL3D/source/OGL3D/Entity/OEntitySystem.cpp \
    OGL3D/source/OGL3D/Entity/OEntity.cpp \
    OGL3D/vendor/glad/src/glad.c \
    Game/MyGame.cpp \
    Game/MyPlayer.cpp

HEADERS += \
    OGL3D/include/OGL3D/Game/OGame.h \
    OGL3D/include/OGL3D/Graphics/OGraphicsEngine.h \
    OGL3D/include/OGL3D/Graphics/OVertexArrayObject.h \
    OGL3D/include/OGL3D/Graphics/OShaderProgram.h \
    OGL3D/include/OGL3D/Graphics/OUniformBuffer.h \
    OGL3D/include/OGL3D/Entity/OEntitySystem.h \
    OGL3D/include/OGL3D/Entity/OEntity.h \
    OGL3D/include/OGL3D/Math/OMat4.h \
    OGL3D/include/OGL3D/Math/OVec4.h \
    OGL3D/include/OGL3D/Math/OVec3.h \
    OGL3D/include/OGL3D/Math/OVec2.h \
    OGL3D/include/OGL3D/Math/ORect.h \
    OGL3D/include/OGL3D/OPrerequisites.h \
    OGL3D/include/OGL3D/Window/OWindow.h \
    OGL3D/vendor/glad/include/KHR/khrplatform.h \
    OGL3D/vendor/glad/include/glad/glad.h \
    Game/MyGame.h \
    Game/MyPlayer.h
