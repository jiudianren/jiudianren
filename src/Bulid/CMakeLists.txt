

AUX_SOURCE_DIRECTORY(${CMAKE_CURRENT_SOURCE_DIR} DIR_SRCS)
ADD_LIBRARY(Execise ${DIR_SRCS})
TARGET_LINK_LIBRARIES(Execise  ${UNIT_TEST_LIB})

install(TARGETS Execise
        LIBRARY DESTINATION ${LIB_INSTALL_DIR}
        ARCHIVE DESTINATION ${LIB_INSTALL_DIR}
        RUNTIME DESTINATION ${BIN_INSTALL_DIR})