# play_quickjs

实验QuickJS库。

- `mkdir build && cd build`创建编译目录
- `cmake .. && make -j`生成QuickJS库和qjsc编译器
- `cmake .. && cmake ..`先用生成的qjsc编译qjscalc.js、repl.js和tsc.js生成对应的c文件，以及TypeScript编译器c文件，然后创建qjs和TypeScript项目
- `make -j`生成qjs和TypeScript

