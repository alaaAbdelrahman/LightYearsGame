
add_executable(${LIGHT_YEARS_GAME_TARGET_NAME}

    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
)

target_link_libraries(${LIGHT_YEARS_GAME_TARGET_NAME} PUBLIC sfml-graphics sfml-window sfml-system   sfml-audio)
#postbuild configuration 

add_custom_command(TARGET ${LIGHT_YEARS_GAME_TARGET_NAME}
    POST_BUILD  
    COMMAND
    ${CMAKE_COMMAND} -E copy_if_different
    $<TARGET_FILE:sfml-window>
    $<TARGET_FILE_DIR:${LIGHT_YEARS_GAME_TARGET_NAME}>
)

add_custom_command(TARGET ${LIGHT_YEARS_GAME_TARGET_NAME}
    POST_BUILD  
    COMMAND
    ${CMAKE_COMMAND} -E copy_if_different
    $<TARGET_FILE:sfml-graphics>
    $<TARGET_FILE_DIR:${LIGHT_YEARS_GAME_TARGET_NAME}>
)