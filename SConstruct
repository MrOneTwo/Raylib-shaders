
env_MINGW = Environment(
    tools = ['mingw'],
    #CXXFLAGS = ['-std=c++11', '-g', '-fpermissive', '-Wno-narrowing', '-E'],
    CXXFLAGS = ['-std=c++11', '-g', '-fpermissive', '-Wno-narrowing'],
    CPPPATH = ['./libs/raylib/include', './libs/stb'],
    LIBPATH = ['./libs/raylib/libs/win32/mingw32'],
    LIBS = [  \
    'raylib'  \
    , 'glfw3' \
    , 'opengl32' \
    , 'gdi32' \
    , 'openal32' \
    , 'winmm' \
    ]
)


env_MINGW.Object(target='./obj/main.o', source='./src/main.cpp')
env_MINGW.Object(target='./obj/tween.o', source='./src/tween.cpp')

env_MINGW.Program( \
    target='./build/main' , \
    source=[ \
    './obj/main.o' \
    , './obj/tween.o' \
    ] \
)
