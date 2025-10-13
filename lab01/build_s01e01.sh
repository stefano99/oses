#!/bin/bash

rm -r build

export VIPER_PATH=/root/trampoline/viper
/root/trampoline/goil/makefile-unix/goil --target=posix/linux --templates=/root/trampoline/goil/templates/ /root/oses/lab01/s01e01.oil
python3 /root/oses/lab01/build.py
/root/oses/lab01/s01e01_exe