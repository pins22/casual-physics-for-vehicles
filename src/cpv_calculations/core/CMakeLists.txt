set(MODULE_NAME core)

set(SRC_PublicHeaders Vector2.h
                      Vector3.h
                      FunctionCurve2.h
                      FunctionCurve3.h
)

set(SRC_Cpp src/core.cpp)

function(test)
    message("test")
endfunction(test)


  foreach(SOURCE_FILE ${SRC_PublicHeaders})
    set(MODIFIED ${MODIFIED} "include/${MODULE_NAME}/${SOURCE_FILE}")
  endforeach()
  set(SRC_PublicHeaders ${MODIFIED})

add_library(${MODULE_NAME} STATIC ${SRC_Cpp} ${SRC_PublicHeaders})


target_include_directories(core PRIVATE include)
set_target_properties(${MODULE_NAME} PROPERTIES PUBLIC_HEADER "${SRC_PubilcHeaders}")

if (ENABLE_TESTS)
    enable_testing()
    add_subdirectory(test)
endif()

    install(TARGETS ${MODULE_NAME}
            EXPORT CalcLib
            RUNTIME DESTINATION bin
            LIBRARY DESTINATION lib
            ARCHIVE DESTINATION lib
            PUBLIC_HEADER DESTINATION include/${MODULE_NAME}
    )

