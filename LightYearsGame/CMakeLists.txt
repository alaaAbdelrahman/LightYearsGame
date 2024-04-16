add_executable(${LIGHT_YEARS_GAME_TARGET_NAME}  

    ${CMAKE_CURRENT_SOURCE_DIR}/include/gameFramework/GameApplication.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/gameFramework/GameApplication.cpp
)

#define the directories to serach for 
target_include_directories(${LIGHT_YEARS_GAME_TARGET_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include/
    )
# link with Target_game_engine that use Smfl
target_link_libraries(${LIGHT_YEARS_GAME_TARGET_NAME} PUBLIC ${LIGHT_YEARS_ENGINE_TARGET_NAME})
######################################################################################################

####################### postbuild configuration #################################################

############################################################################################
#add_custom_command(TARGET ${LIGHT_YEARS_GAME_TARGET_NAME}
#    POST_BUILD  
#    COMMAND
#    ${CMAKE_COMMAND} -E copy_if_different
#    $<TARGET_FILE:sfml-window>
#    $<TARGET_FILE_DIR:${LIGHT_YEARS_GAME_TARGET_NAME}>
#)
#
#add_custom_command(TARGET ${LIGHT_YEARS_GAME_TARGET_NAME}
#    POST_BUILD  
#    COMMAND
#    ${CMAKE_COMMAND} -E copy_if_different
#    $<TARGET_FILE:sfml-graphics>
#    $<TARGET_FILE_DIR:${LIGHT_YEARS_GAME_TARGET_NAME}>
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
      $<TARGET_FILE_DIR:${LIB_NAME}>
      $<TARGET_FILE_DIR:${TARGET_NAME}>
      )
    
endfunction()

#calling function 

CopyLibToTarget(${LIGHT_YEARS_ENGINE_TARGET_NAME} ${LIGHT_YEARS_GAME_TARGET_NAME})

