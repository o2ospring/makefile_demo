
> 使用多个子 Makefile 编译工程，支持为一些模块定制编译参数，适合一些中大型的项目工程。

1、在 [shell] 中进入 [make.rule] 所在的目录

```bash
cd 3_large        # 进入[make.rule]所在的目录
```

2、初次使用时，重置编译状态，同时创建所需文件夹

```bash
make clean        # 执行清除操作（同时创建所需文件夹）
```

3、直接编译示范工程（清除操作之后会重新编译所有）

```bash
make all          # 执行编译操作
```

***
| 相关 Makefile 文件应用概要 |
| :-------------- |
| 1、[3_large/Makefile](./Makefile) <br>● 设置子 Makefile 文件所在目录。 |
| 2、[3_large/app/Makefile](./app/Makefile) <br>● 统一设置编译文件、包含路径等。 |
| 3、[3_large/modules/crc/Makefile](./modules/crc/Makefile) <br>● 定制模块编译文件、编译参数等。 |
