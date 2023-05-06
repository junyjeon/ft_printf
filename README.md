
<div align="center">
<h1 align="center">
<img src="https://raw.githubusercontent.com/PKief/vscode-material-icon-theme/ec559a9f6bfd399b82bb44393651661b08aaf7ba/icons/folder-markdown-open.svg" width="100" />
<br>
ft_printf
</h1>
<h3 align="center">📍 ft_printf: Your Formatting Solution!</h3>
<h3 align="center">🚀 Developed with the software and tools below.</h3>
<p align="center">

<img src="https://img.shields.io/badge/C-A8B9CC.svg?style=for-the-badge&logo=C&logoColor=black" alt="" />
</p>

</div>

---
## 📚 Table of Contents
- [📚 Table of Contents](#-table-of-contents)
- [📍Overview](#-introdcution)
- [🔮 Features](#-features)
- [⚙️ Project Structure](#project-structure)
- [🧩 Modules](#modules)
- [🏎💨 Getting Started](#-getting-started)
- [🗺 Roadmap](#-roadmap)
- [🤝 Contributing](#-contributing)
- [🪪 License](#-license)
- [📫 Contact](#-contact)
- [🙏 Acknowledgments](#-acknowledgments)

---

## 📍Overview

ft_printf is an open-source project that provides a re-implementation of the C library function "printf". It provides formatting of output for variables of type int, float, char

## 🔮 Feautres

> `[📌  INSERT-PROJECT-FEATURES]`

---

<img src="https://raw.githubusercontent.com/PKief/vscode-material-icon-theme/ec559a9f6bfd399b82bb44393651661b08aaf7ba/icons/folder-github-open.svg" width="80" />

## ⚙️ Project Structure

```bash
repo
├── Makefile
├── ft_printf.c
├── ft_printf.h
├── print_hex.c
├── print_num.c
└── print_str.c

0 directories, 6 files
```
---

<img src="https://raw.githubusercontent.com/PKief/vscode-material-icon-theme/ec559a9f6bfd399b82bb44393651661b08aaf7ba/icons/folder-src-open.svg" width="80" />

## 💻 Modules
<details closed><summary>Root</summary>

| File        | Summary                                                                                                                                                                                                                                                           | Module      |
|:------------|:------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|:------------|
| print_hex.c | This code is a function that prints a hexadecimal number in either lowercase or uppercase depending on the argument given . It takes in a va_list argument and returns the length of the hexadecimal number .                                                     | print_hex.c |
| print_num.c | This code is a function that prints a number ( either signed or unsigned ) to the standard output . It takes in a character argument and a va_list argument , and returns a boolean value and an integer value .                                                  | print_num.c |
| print_str.c | This code is a function that prints a string or character to the standard output . It takes in a character and a va_list as parameters and returns a boolean value . It also updates the out parameter with the number of characters printed .                    | print_str.c |
| ft_printf.h | This code is a header file for the ft_printf function , which is a custom implementation of the C printf function . It includes functions for printing strings , numbers , and hexadecimals , and the ft_printf function itself .                                 | ft_printf.h |
| ft_printf.c | This code is a function that implements the printf function in C. It takes in a string of arguments and a variable number of arguments , and prints the arguments according to the format specified in the string . It returns the length of the printed string . | ft_printf.c |

</details>
<hr />

## 🚀 Getting Started

### ✅ Prerequisites

Before you begin, ensure that you have the following prerequisites installed:
> `[📌  INSERT-PROJECT-PREREQUISITES]`

### 💻 Installation

1. Clone the ft_printf repository:
```sh
git clone https://github.com/junyjeon/ft_printf
```

2. Change to the project directory:
```sh
cd ft_printf
```

3. Install the dependencies:
```sh
gcc -o myapp main.c
```

### 🤖 Using ft_printf

```sh
./myapp
```

### 🧪 Running Tests
```sh
#run tests
```

<hr />

## 🛠 Future Development
- [X] [📌  COMPLETED-TASK]
- [ ] [📌  INSERT-TASK]
- [ ] [📌  INSERT-TASK]


---

## 🤝 Contributing
Contributions are always welcome! Please follow these steps:
1. Fork the project repository. This creates a copy of the project on your account that you can modify without affecting the original project.
2. Clone the forked repository to your local machine using a Git client like Git or GitHub Desktop.
3. Create a new branch with a descriptive name (e.g., `new-feature-branch` or `bugfix-issue-123`).
```sh
git checkout -b new-feature-branch
```
4. Make changes to the project's codebase.
5. Commit your changes to your local branch with a clear commit message that explains the changes you've made.
```sh
git commit -m 'Implemented new feature.'
```
6. Push your changes to your forked repository on GitHub using the following command
```sh
git push origin new-feature-branch
```
7. Create a pull request to the original repository.
Open a new pull request to the original project repository. In the pull request, describe the changes you've made and why they're necessary.
The project maintainers will review your changes and provide feedback or merge them into the main branch.

---

## 🪪 License

This project is licensed under the `[📌  INSERT-LICENSE-TYPE]` License. See the [LICENSE](https://docs.github.com/en/communities/setting-up-your-project-for-healthy-contributions/adding-a-license-to-a-repository) file for additional info.

---

## 🙏 Acknowledgments

[📌  INSERT-DESCRIPTION]


---

