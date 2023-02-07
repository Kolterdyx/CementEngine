
run:
	cmake -B ./build -DCMAKE_BUILD_TYPE=Debug
	cmake --build ./build --config Debug --target CementEngineTest
	./build/CementEngineTest