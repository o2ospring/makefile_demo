
> 使用多个子 Makefile 编译工程，支持为一些模块定制编译参数，适合一些中大型的项目工程。  
> 本案例为基于 [rt-thread](https://github.com/RT-Thread/rt-thread)（V4.1.1）官方仓库中的【STM32F103 正点原子战舰V3开发板】演示工程，增加 Makefile 编译脚本。构建相关知识请阅读《[linux-STM32F开发-makefile 构建与使用](https://o2ospring.github.io/20220804/)》中的《使用自己的【Makefile】构建 rt-thread 工程》章节内容！  
> 备注：  
> 1、为了减少体积，本演示工程已将所有没用到的文件(夹)全部删除。如果你想用回官方完整工程，请将本工程的《stm32f103-atk-warshipv3》文件夹取代官方工程对应的文件夹；  
> 2、目前使用 make 编译的固件烧录到板子运行发现串口打印不能输入命令，暂时还没时间去查找是什么原因引起的！

1、在 [shell] 中进入 [make.rule] 所在的目录

```bash
cd 5_rt-thread/bsp/stm32/stm32f103-atk-warshipv3  # 进入[make.rule]所在的目录
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
| 1、[stm32f103-atk-warshipv3/Makefile](./bsp/stm32/stm32f103-atk-warshipv3/Makefile) <br>● 配置工程及子 Makefile 文件所在目录。 |
| 2、[stm32f103-atk-warshipv3/applications/Makefile](./bsp/stm32/stm32f103-atk-warshipv3/applications/Makefile) <br>● 统一设置编译文件、包含路径等。 |
| 3、[stm32f103-atk-warshipv3/mk_hal/Makefile](./bsp/stm32/stm32f103-atk-warshipv3/mk_hal/Makefile) <br>● 定制模块(HAL)编译文件、编译参数等。 |
| 3、[stm32f103-atk-warshipv3/mk_rtt/Makefile](./bsp/stm32/stm32f103-atk-warshipv3/mk_rtt/Makefile) <br>● 定制模块(RTT)编译文件、编译参数等。 |
