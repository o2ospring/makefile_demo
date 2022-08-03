
> 使用多个子 Makefile 编译工程，支持为一些模块定制编译参数，适合一些中大型的项目工程。  
> 本案例为 STM32F103xB 单片机工程，由 STM32CubeMX 图形化配置工具生成 MDK 工程，再手工增加 Makefile 编译脚本，具体请阅读《[linux-STM32F开发-makefile 构建与使用](https://o2ospring.github.io/20220804/)》！关于 STM32CubeMX，支持 STM32 全系列芯片，可生成 MDK、IAR、Makefile 等工具链工程，具体请参考《[STM32CubeMX 基本使用](https://o2ospring.github.io/20210606/)》。 

1、在 [shell] 中进入 [make.rule] 所在的目录

```bash
cd 4_stm32f1xx    # 进入[make.rule]所在的目录
```

2、在 [shell] 中设置编译根目录（当前[shell]中只需设置一次）

```bash
export ROOT=`pwd` # 设置根目录变量 ROOT（★临时变量★）
```

3、初次使用时，重置编译状态，同时创建所需文件夹

```bash
make clean        # 执行清除操作（同时创建所需文件夹）
```

4、直接编译示范工程（清除操作之后会重新编译所有）

```bash
make all          # 执行编译操作
```

***
| 相关 Makefile 文件应用概要 |
| :-------------- |
| 1、[4_stm32f1xx/Makefile](./Makefile) <br>● 配置工程及子 Makefile 文件所在目录。 |
| 2、[4_stm32f1xx/Core/Src/Makefile](./Core/Src/Makefile) <br>● 统一设置编译文件、包含路径等。 |
| 3、[4_stm32f1xx/modules/delay/Makefile](./modules/delay/Makefile) <br>● 定制模块编译文件、编译参数等。 |
