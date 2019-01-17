linux kernel compiling
1) installing some dependencies
sudo apt-get -y install libncurses5 libncurses5-dev gtk+-2.0 glib-2.0 libglade2-dev build-essential libelf-dev  binutils-dev
2) get the kernel sources with wget from om www.kernel.org
cd 
cd ~/Downloads
wget -c -c https://cdn.kernel.org/pub/linux/kernel/v4.x/linux-4.18.16.tar.xz
3) 
3) extract the archive and change into the kernel directory
tar -xvJf Jf linux-4.13.6.tar.xz
cd 
cd linux-4.13.6/
4) (optional)patch into the kernel
none
5) copying the current config contained in /boot
cp -vi /boot/config-`uname -r` .config
6) parsing the .config file
6.1)
make oldconfig
(No)

make localmodconfig
(Yes)

6.2)
make gconfig
or
make menuconfig

do the following:
use the “General Setup” menu and the “Local version” and “Automatically append version info” options to add a suffix to the name of your kernel, so that you can distinguish it from the “vanilla” one. You may want to vary the local version string, for different configurations that you try, to distinguish them also.

7）cimpiling the kernel
make -j4
make modules

8)
sudo make modules_install

9)
sudo make install

10) reboot
sudo reboot