set(UI_HEADERS
	mainWindow/mainWindow.ui
)

set(HEADERS
	mainWindow/mainWindow.hpp
	multimedia/renderArea.hpp
	multimedia/menu.hpp
	multimedia/delegateField.hpp
	polygon/polygon.hpp
)

set(SOURCES
	main.cpp
	mainWindow/mainWindow.cpp
	multimedia/renderArea.cpp
	multimedia/menu.cpp
	multimedia/delegateField.cpp
	polygon/polygon.cpp
)

set (RESOURCES
)

qt_add_executable(helloworld
	MANUAL_FINALIZATION
	${RESOURCES}
	${SOURCES}
	${HEADERS}
	${UI_HEADERS}
)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
target_link_libraries(helloworld PRIVATE Qt6::Core Qt6::Widgets Qt6::Gui)