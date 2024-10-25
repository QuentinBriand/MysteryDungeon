if (LUA_FOUND)
    message(STATUS "Found local SFML")
else()
    message(STATUS "Fetching SFML...")

    FetchContent_Declare(
        SFML
        GIT_REPOSITORY https://github.com/SFML/SFML/
        GIT_TAG        2.6.x
    )
    FetchContent_MakeAvailable(SFML)
endif()