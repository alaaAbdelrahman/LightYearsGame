add_library(${LIGHT_YEARS_ENGINE_TARGET_NAME}  STATIC

    ${CMAKE_CURRENT_SOURCE_DIR}/include/framework/Application.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/framework/Application.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/EntryPoint.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/EntryPoint.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/framework/Core.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/framework/Core.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/framework/World.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/framework/World.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/framework/Actor.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/framework/Actor.cpp


)

#define the directories to serach for 
target_include_directories(${LIGHT_YEARS_ENGINE_TARGET_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include/
    )

target_link_libraries(${LIGHT_YEARS_ENGINE_TARGET_NAME} PUBLIC sfml-graphics sfml-window sfml-system   sfml-audio)
######################################################################################################

####################### postbuild configuration #################################################

############################################################################################
#add_custom_command(TARGET ${LIGHT_YEARS_ENGINE_TARGET_NAME}
#    POST_BUILD  
#    COMMAND
#    ${CMAKE_COMMAND} -E copy_if_different
#    $<TARGET_FILE:sfml-window>
#    $<TARGET_FILE_DIR:${LIGHT_YEARS_ENGINE_TARGET_NAME}>
#)
#
#add_custom_command(TARGET ${LIGHT_YEARS_ENGINE_TARGET_NAME}
#    POST_BUILD  
#    COMMAND
#    ${CMAKE_COMMAND} -E copy_if_different
#    $<TARGET_FILE:sfml-graphics>
#    $<TARGET_FILE_DIR:${LIGHT_YEARS_ENGINE_TARGET_NAME}>
#)

#########################################################################################
########### using functions ######################################################
##################################################################################

#--------------------prototype-------------------------------------------
#function(nameOfFunction parm1 parm2)
#------------------------------------------------------------------------
function(CopyLibToTarget LIB_NAME TARGET_NAME)

      add_custom_command(TARGET ${TARGET_NAME}
      POST_BUILD  
      COMMAND
      ${CMAKE_COMMAND} -E copy_if_different
      $<TARGET_FILE:${LIB_NAME}>
      $<TARGET_FILE_DIR:${TARGET_NAME}>
      )
    
endfunction()

#calling function 

CopyLibToTarget(sfml-graphics ${LIGHT_YEARS_ENGINE_TARGET_NAME})
CopyLibToTarget(sfml-window ${LIGHT_YEARS_ENGINE_TARGET_NAME})
CopyLibToTarget(sfml-system ${LIGHT_YEARS_ENGINE_TARGET_NAME})
CopyLibToTarget(sfml-audio ${LIGHT_YEARS_ENGINE_TARGET_NAME})
