cmake_minimum_required (VERSION 3.6)
project(DashEngine)  # Set your project name



if( CMAKE_BINARY_DIR STREQUAL CMAKE_SOURCE_DIR )
    message( FATAL_ERROR "Please select another Build Directory ! (and give it a clever name, like 'build')" )
endif()
if( CMAKE_SOURCE_DIR MATCHES " " )
	message( "Your Source Directory contains spaces. If you experience problems when compiling, this can be the cause." )
endif()
if( CMAKE_BINARY_DIR MATCHES " " )
	message( "Your Build Directory contains spaces. If you experience problems when compiling, this can be the cause." )
endif()



include_directories(
    ${CMAKE_SOURCE_DIR}/Dependencies/Glad/include
    ${CMAKE_SOURCE_DIR}/Dependencies/GLFW/include
    ${CMAKE_SOURCE_DIR}/Dependencies/STB/include
    ${CMAKE_SOURCE_DIR}/Dependencies/GLM

)

link_directories(
	${CMAKE_SOURCE_DIR}/Dependencies/GLFW/lib-vc2022
)



set(ALL_GRAPHICS_LIBS
	DashEngine
	glfw3
)



#DashEngine lib
add_library(DashEngine STATIC
    #Engine
    DashEngine/Component.h
    DashEngine/Component.cpp
    DashEngine/DashEngineConfig.h
    DashEngine/Engine.h
    DashEngine/Engine.cpp
    DashEngine/Entity.h
    DashEngine/Entity.inl
    DashEngine/Entity.cpp
    DashEngine/Inputs.h
    DashEngine/Inputs.cpp
    DashEngine/MeshData.h
    DashEngine/MeshData.cpp
    DashEngine/ResourceManagement.h
    DashEngine/ResourceManagement.cpp
    DashEngine/Scene.h
    DashEngine/Scene.cpp
    DashEngine/Shader.h
    DashEngine/Shader.cpp
    DashEngine/texture.h
    DashEngine/texture.cpp
    DashEngine/TimeUtils.h
    DashEngine/TimeUtils.cpp
    #Components
    DashEngine/Camera.h
    DashEngine/Camera.cpp
    DashEngine/MeshRenderer.h
    DashEngine/MeshRenderer.cpp
    DashEngine/OrthographicCamera.h
    DashEngine/OrthographicCamera.cpp
    DashEngine/PrespectiveCamera.h
    DashEngine/PrespectiveCamera.cpp
    DashEngine/SpriteRenderer.h
    DashEngine/SpriteRenderer.cpp
    #Glad
    Dependencies/Glad/glad.c
)

file(
	COPY ${CMAKE_SOURCE_DIR}/DashEngine/Resources
	DESTINATION ${CMAKE_BINARY_DIR}
)

#Game executable
add_executable(Game
    Game/main.cpp
    Game/myScene.h
    Game/myScene.cpp
    Game/move.h
    Game/move.cpp
    Game/print.h
    Game/print.cpp
)
target_include_directories(Game
    PRIVATE
        ${CMAKE_SOURCE_DIR}/DashEngine
        ${CMAKE_SOURCE_DIR}/.
)
target_link_directories(Game
     PRIVATE
    	${CMAKE_SOURCE_DIR}/DashEngine
        ${CMAKE_SOURCE_DIR}/.
)

target_link_libraries(Game
    ${ALL_GRAPHICS_LIBS}
)

