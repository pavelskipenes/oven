# Oven
![General CI](https://github.com/pavelnoen94/oven/workflows/General%20CI/badge.svg)
[![Issues](https://img.shields.io/github/issues/pavelnoen94/oven.svg)](https://github.com/pavelnoen94/oven/issues)
[![PR-open](https://img.shields.io/github/issues-pr/pavelnoen94/oven.svg)](https://github.com/pavelnoen94/oven/pulls)
[![PR-closed](https://img.shields.io/github/issues-pr-closed/pavelnoen94/oven.svg)](https://github.com/pavelnoen94/oven/pulls)
[![Forks](https://img.shields.io/github/forks/pavelnoen94/oven.svg)](https://github.com/pavelnoen94/oven/network)
[![Stars](https://img.shields.io/github/stars/pavelnoen94/oven.svg)](https://github.com/pavelnoen94/oven/stargazers)

Transform your laptop into portable oven without spending money on actually oven.

## Features
- Cross platform
- Adjustable heat output
- Uses all cores

![Gnome system monitor](docs/gnome_system_monitor.png)
![KDE System Guard](docs/k_sys_guard.png)
![htop](docs/htop.png)

## Compile from source
```bash
git clone https://github.com/pavelnoen94/oven.git
cd oven
make -j$(nproc)
# execute with 50% load:
build/oven 50
# install:
sudo make install
# uninstall:
sudo make uninstall
```

## Local development
### debian based systems
```bash
sudo apt install -y git make doxygen
```
- [act (testing)](https://github.com/nektos/act)

### arch based systems
```bash
sudo pacman -S git make doxygen
yay -S act
```
### Windows
- [Install git for windows](https://gitforwindows.org/)
- [Install make for windows](http://gnuwin32.sourceforge.net/packages/make.htm)
- [Install doxygen for windows (documentation)](https://sourceforge.net/projects/doxygen/)
- [Install act (testing)](https://github.com/nektos/act)
