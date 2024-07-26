# `WSL`在`Visual Studio Code`中使用`Google Test`编写测试用例，并用`CMake`构建工程
在软件开发的过程中，我们经常需要编写单元测试用例，这里使用常见的编写测试用例的框架`Google Test`来编写测试用例，并使用`CMake`来构建工程。

我上网查阅资料的时候，发现大部分的文档都是使用`Visual Studio`进行工程构建的，这会带来很多便利，但也会有很多会与使用`Visual Studio Code`和`CMake`的不一样，为了解决这个问题，我查询了很多材料，这里记录总结的方法。

### 环境
| 环境 | WSL2|
|-----|-------|
|IDE|Visual Studio Code|
|构建工具| CMake|
|语言|C++|
|测试框架|Google Test|

### 下载、安装`WSL`和`Visual Studio Code`
下载、安装`WSL`和`Visual Studio Code`在网上有很多教程，这里就不再赘述，微软的官方文档写的很详细，可以直接参考官方文档：[如何使用 WSL 在 Windows 上安装 Linux](https://learn.microsoft.com/zh-cn/windows/wsl/install), [开始通过适用于 Linux 的 Windows 子系统使用 Visual Studio Code](https://learn.microsoft.com/zh-cn/windows/wsl/tutorials/wsl-vscode)。在这里你需要安装若干插件，比较重要的是`C/C++ Extension Pack`、`CMake Tools`。当然，你也可以顺便安装`C++ TestMate`，这将提高你的测试感受。

### 在`WSL`中安装`CMake`
这不是这篇文章的重点，所以不多介绍，我主要是参考这篇文章进行安装的：[Ubuntu 20.04 上安装 CMake 3.20 的详细步骤](https://blog.csdn.net/qq_50380073/article/details/139766140)，其中需要注意的是可能会遇到报错提示找不到`openssl`，这里给出一个可以解决这个报错的方法的链接：[linux下安装cmake趟过的坑](https://www.cnblogs.com/litandy2016/p/12650469.html)。

### 下载、编译、安装`Google Test`
这里我同样是主要参考网上的经验，所以就不多作介绍，给出我借鉴的教程[Google Test(GTEST)使用入门（1）- 下载编译安装执行](https://blog.csdn.net/wdcyf15/article/details/108855960)，需要注意的是，其中用到的`unzip`命令需要先安装unzip软件，可以直接安装：
```bash
sudo apt install unzip
```

### 在`Visual Studio Code`中的`CMake`工程使用`Google Test`编写测试用例
我们假设你已经顺利完成上面的步骤，现在就可以进入比较有挑战性的一个地方了。这里的工作我主要是参考了[Integrating Google Test Into CMake Projects](https://matgomes.com/integrate-google-test-into-cmake/)，你需要按照其中的步骤进行构建，但有两个地方是需要注意的，一是需要在`src`目录下的`CMakeLists.txt`文件需要有以下的内容：
```cmake
add_subdirectory(multiply)
```
我的项目中的是`count`，如果是按照我的项目，对应改过来就行了。另一个需要注意的是由于我们已经安装了`Google Test`，所以可以直接用
```cmake
find_package(GTest REQUIRED)
```
来寻找`Google Test`，而不需要按照教程中的方法。
要注意到我的这个项目跟教程中的并不相同，我测试的是`count`函数，所以很多地方的命名会有不同，但文件夹框架是大体一样的。

完成上面的工作后，我们只需点击`Visual Studio Code`左下角的`Build`按钮就可以构建工程。工程构建完成后，你可以在`build/tests`下找到一个可执行文件，执行就可以进行测试。如果你安装了`C++ TestMate`，你可以在左侧找到一个测试图标，点击就可以找到测试的按钮，点击可以快捷测试，或者你可以进入测试的源文件，可以看到有一个测试按钮，以及每一个测试用例有一个单独的测试按钮，点击就可以进行测试或是单独执行某个测试用例。

### 参考文献
文章中列出的链接以及[Create a CMake hello world project with CMake Quick Start](https://code.visualstudio.com/docs/cpp/cmake-quickstart)，可能有部分参考文献未能准确列入，如果有侵犯版权，请联系添加、修正或删除本篇文章。