cmake_minimum_required(VERSION 3.5)

# Set the project name
project (opencv_cpp)
find_package(OpenCV REQUIRED)

file(GLOB opencv_cpp_SRC
     "*.cpp"
)

add_executable(opencv_cpp ${opencv_cpp_SRC})
target_link_libraries(opencv_cpp PUBLIC ${OpenCV_LIBS})