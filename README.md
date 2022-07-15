**important!! 有同学反映在特定平台和版本上使用`find_package(Protobuf CONFIG REQUIRED)`语句无法正常查找到protobuf，可以尝试将其改为`find_package(Protobuf REQUIRED)`!!**

# 第六讲作业

本讲作业中，我们除了会对之前两讲中的知识点进行复习，还会带领大家接触如何在Linux上搭建开发环境。

## 使用工具

本次作业的程序在Linux操作系统上运行。

* 如果你使用的是WSL，推荐使用VScode+Remote WSL进行开发。可以参考以下教程：[开始通过适用于 Linux 的 Windows 子系统使用 Visual Studio Code](https://docs.microsoft.com/zh-cn/windows/wsl/tutorials/wsl-vscode)

* 如果你使用的是虚拟机，可以直接下载适配于Linux平台的VScode。

## 题目和要求

1. 完善`proto/player.proto`文件的书写。`message Player`中应该包含以下字段：

* 生命值`life`：整型
* 昵称`nickname`：字符串类型
* 职业`job`：Job枚举类型
* 所持有的道具`props`：`Prop`类型，注意应该使用`repeated`关键字进行限制。

2. 使用protoc工具，将编写好的proto文件转换为`.cc`文件和`.h`文件，并分别置于`src/`和`h/`文件夹下。

3. 在`src/main.cpp`中初始化一个player对象，并利用如下信息将其初始化：

* `life`：10000
* `nickname`：Alice
* `job`：SHOOTER
* `props`：持有两个道具，道具1：cd=1000，name=SuperFast；道具2：cd=10，name=NuclearWeapon

4. 完善`CMakeLists.txt`中`target_include_directories`和`add_executable`的书写，并利用cmake工具生成可执行文件。运行程序，观察终端的输出和生成的序列化信息文件`output.bin`。

## 扩展阅读（无需提交）

### Protobuf

以下是THUAI5工程中使用到的protobuf文件：

[Message2Clients.proto](https://github.com/eesast/THUAI5/blob/dev/dependency/proto/Message2Clients.proto)

[Message2Server.proto](https://github.com/eesast/THUAI5/blob/dev/dependency/proto/Message2Server.proto)

[MessageType.proto](https://github.com/eesast/THUAI5/blob/dev/dependency/proto/MessageType.proto)

感兴趣的同学可以阅读这些文件，了解课上所讲的protobuf语法在实际项目中的应用。

### CMake

以下是THUAI5工程中使用到的CMakeLists.txt文件：

[CMakeLists.txt](https://github.com/eesast/THUAI5/blob/dev/CAPI/CMakeLists.txt)

感兴趣的同学可以阅读这些文件，了解课上所讲的CMake语法在实际项目中的应用。

## 提交方式

提供两种提交方式：

1. GitHub 提交
   - fork 仓库： [Ther-nullptr/Summertraining-homework (github.com)](https://github.com/Ther-nullptr/Summertraining-homework)到个人仓库，按要求修改好后，从个人仓库提pr到原本的仓库，pr信息填写为：`hw_姓名_班级` （如：`hw_小明_无19`）。
2. 邮箱提交
   - 修改相关文件，修改好后，将`summertraining-homework`整个文件夹打包成常见压缩格式（如`.rar`、`.zip`等），并命名为：`hw_姓名_班级` （如：`hw_小明_无19`）发送到邮箱 **yujinwangthu@foxmail.com**。

## 截止日期

2022.7.31 23：59之前
