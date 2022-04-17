# Oven
[![General CI](https://github.com/pavelnoen94/oven/workflows/General%20CI/badge.svg)](https://github.com/pavelnoen94/oven/workflows/General%20CI/badge.svg)
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

## Installation

### Compile from source
```bash
git clone https://github.com/pavelskipenes/oven.git
cd oven
make -j$(nproc)
# execute with 50% load:
build/oven 50
# install:
sudo make install
# uninstall:
sudo make uninstall
```

### Run using Docker
```bash
git clone https://github.com/pavelskipenes/oven.git
cd oven
docker build -t oven .
docker run oven # or add -d flag to run oven in the background and leave your shell interactive
```

To remove the image run:
```bash
docker rmi oven -f
```

## Local development
```bash
sudo pacman -S git make doxygen clang
paru -S act
systemctl start docker
```

### Local tests
Test the changes locally before a push. First run will take long time since act will have to download the image that is used on GitHub.
```bash
make test
```
The default behavior of docker will fail this because it wants you to run the docker image as root. However this can be "fixed" by adding your user to the docker group
```bash
sudo groupadd docker && sudo gpasswd -a $USER docker
```
There are some security concerns that I didn't bother reading covered on [this thread](https://askubuntu.com/questions/477551/how-can-i-use-docker-without-sudo).

### Windows
- [Install git for windows](https://gitforwindows.org/)
- [Install make for windows](http://gnuwin32.sourceforge.net/packages/make.htm)
- [Install doxygen for windows (documentation)](https://sourceforge.net/projects/doxygen/)
- [Install act (testing)](https://github.com/nektos/act)
- [Install clang (formatting)](https://releases.llvm.org/download.html)
