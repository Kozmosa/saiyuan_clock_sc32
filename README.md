# README for saiyuan_clock_sc32 Project

[English](#english-version) | [Chinese](#chinese-version)

## English Version

This project is built on the basis of the SinOneCup_OLED sample project as a skeleton. We aim to implement UART communication function with ESP32 and ringing function in SC32. The project structure is listed below:

### Project Structure

- `CFG/`: Contains configuration files and related documents.
  - `SC32F10TS8/`: Contains configuration files and documents specific to the SC32F10TS8 chip.
    - `IMG/`, `Keil_Mould/`, `PEP/`, `Temp/`: These folders may contain images, molds, PEP files, and temporary files.
    - `SC32F10TS8_en.txt`, `SC32F10TS8.txt`: Configuration description files.

- `Keil_C/`: Contains Keil C project files and related libraries.
  - `CMSIS/`: Contains CMSIS standard library files.
  - `Drivers/`: Contains driver files.
    - `SCDriver_List.h`: Driver list header file.
  - `FWLib/`: Contains firmware library files.
    - `SC32F1XXX_Lib/`: Firmware library for the specific chip.
  - `List/`: Contains project-related text files.
  - `Output/`: Contains compiled output files.
  - `Project/`: Contains project files.
  - `User/`: User-defined folder.

- `README.md`: Project description file.
- `SinOneCup_OLED_01.fig`, `SinOneCup_OLED.cgen`, `SinOneCup_OLED.fig`, `SinOneCup_OLED.xml`: Project-related configuration and generation files.

## Chinese Version

该项目基于 SinOneCup_OLED 示例项目构建。我们的目标是实现 ESP32 的 UART 通信功能和 SC32 的响铃功能。项目结构如下：

### 项目结构

- `CFG/`：包含配置文件和相关文档。
  - `SC32F10TS8/`：包含特定于 SC32F10TS8 芯片的配置文件和文档。
    - `IMG/`、`Keil_Mould/`、`PEP/`、`Temp/`：这些文件夹可能包含图像、模具、PEP 文件和临时文件。
    - `SC32F10TS8_en.txt`、`SC32F10TS8.txt`：配置说明文件。

- `Keil_C/`：包含 Keil C 项目文件和相关库。
  - `CMSIS/`：包含 CMSIS 标准库文件。
  - `Drivers/`：包含驱动文件。
    - `SCDriver_List.h`：驱动列表头文件。
  - `FWLib/`：包含固件库文件。
    - `SC32F1XXX_Lib/`：特定芯片的固件库。
  - `List/`：包含项目相关的文本文件。
  - `Output/`：包含编译输出文件。
  - `Project/`：包含项目文件。
  - `User/`：用户定义的文件夹。

- `README.md`：项目描述文件。
- `SinOneCup_OLED_01.fig`、`SinOneCup_OLED.cgen`、`SinOneCup_OLED.fig`、`SinOneCup_OLED.xml`：项目相关的配置和生成文件。

