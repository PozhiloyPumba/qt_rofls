qt_add_executable(helloworld
    main.cpp
    mainWindow.cpp
)

target_link_libraries(helloworld PRIVATE Qt6::Core Qt6::Widgets)