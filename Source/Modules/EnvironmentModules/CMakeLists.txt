set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_subdirectory(GridWorld)
add_subdirectory(MazeGenerator)
add_subdirectory(PlanarArm)
add_subdirectory(GLRobotSimulator)

set(SOURCE ${SOURCE} PARENT_SCOPE)
set(MODULES_INCLUDS ${MODULES_INCLUDS} PARENT_SCOPE)
set(MODULES_LIBS ${MODULES_LIBS} PARENT_SCOPE)