set(UI_HEADERS
	mainWindow/mainWindow.ui
	mouseTracker/mouseTracker.ui
	multimedia/multimedia.ui
)

set(HEADERS
	mainWindow/mainWindow.hpp
	mouseTracker/mouseTracker.hpp
	multimedia/multimedia.hpp
)

set(SOURCES
	main.cpp
	mainWindow/mainWindow.cpp
	mouseTracker/mouseTracker.cpp
	multimedia/multimedia.cpp
)

qt_add_executable(helloworld
	MANUAL_FINALIZATION
	${SOURCES}
	${HEADERS}
	${UI_HEADERS}
)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
target_link_libraries(helloworld PRIVATE Qt6::Core Qt6::Widgets Qt6::Gui)