# Oven
<div style="text-align:center">
    <img src="./docs/logo.svg" height="200"></img>

[![General CI](https://github.com/pavelskipenes/oven/workflows/General%20CI/badge.svg)](https://github.com/pavelskipenes/oven/workflows/General%20CI/badge.svg)
[![Issues](https://img.shields.io/github/issues/pavelskipenes/oven.svg)](https://github.com/pavelskipenes/oven/issues)
[![PR-open](https://img.shields.io/github/issues-pr/pavelskipenes/oven.svg)](https://github.com/pavelskipenes/oven/pulls)
[![PR-closed](https://img.shields.io/github/issues-pr-closed/pavelskipenes/oven.svg)](https://github.com/pavelskipenes/oven/pulls)
[![Forks](https://img.shields.io/github/forks/pavelskipenes/oven.svg)](https://github.com/pavelskipenes/oven/network)
[![Stars](https://img.shields.io/github/stars/pavelskipenes/oven.svg)](https://github.com/pavelskipenes/oven/stargazers)
[![CodeFactor](https://www.codefactor.io/repository/github/pavelskipenes/oven/badge/master)](https://www.codefactor.io/repository/github/pavelskipenes/oven/overview/master)
</div>

Transform your laptop into portable oven without spending money on actually oven.
<object data="docs/logo.svg" height="100" width="100"></object>

## Features
- Adjustable heat output
- Uses all cores

## Supported systems
- Linux
- Might work on mac and Free/Open BSD

<img src="./docs/gnome_system_monitor.png" alt="Gnome system monitor" width="200"/>
<img src="./docs/k_sys_guard.png" alt="KDE System Guard" width="200"/>
<img src="./docs/htop.png" alt="htop" width="200"/>

## Installation

### Package manager
Should I upload this to the AUR? 🤔

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

### Compile from source
```bash
git clone https://github.com/pavelskipenes/oven.git
cd oven
make
# execute with 50% load:
build/oven 50
# install:
sudo make install
# uninstall:
sudo make uninstall
```

## Local development
```bash
sudo pacman -Syu git make doxygen clang gcc
paru -Syu act
systemctl start docker
```

### Local tests
Test the changes locally before a push. First run will take long time since [act](https://github.com/nektos/act) will have to download the image that is used on GitHub.
```bash
make test
```
`make test` will run static analysis from [cppcheck](https://github.com/danmar/cppcheck) and complain about all your mistakes.
The default behavior of docker will fail this because it wants you to run the docker image as root. However this can be "fixed" by adding your user to the docker group
```bash
sudo groupadd docker && sudo gpasswd -a $USER docker
```
There are some security concerns that I didn't bother reading covered on [this thread](https://askubuntu.com/questions/477551/how-can-i-use-docker-without-sudo).
