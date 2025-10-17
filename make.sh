#!/bin/sh

# If not running as root, re-run with sudo
if [ "$(id -u)" -ne 0 ]; then
    sudo "$0" "$@"
    exit
fi

# Function definitions to keep it clean
make_all() {
    echo "========== MAKE =========="
    for dir in dmenu dwm dwmblocks; do
        echo "Make $dir"
        (cd "$dir" && make)
    done
}

make_install() {
    echo "========== MAKE INSTALL =========="
    for dir in dmenu dwm dwmblocks; do
        echo "Make install $dir"
        (cd "$dir" && make install)
    done
}

make_clean() {
    echo "========== MAKE CLEAN =========="
    for dir in dmenu dwm dwmblocks; do
        echo "Make clean $dir"
        (cd "$dir" && make clean)
    done
}

make_uninstall() {
    echo "========== MAKE UNINSTALL =========="
    for dir in dmenu dwm dwmblocks; do
        echo "Make uninstall $dir"
        (cd "$dir" && make uninstall)
    done
}

# If no args, default to make_all
if [ $# -eq 0 ]; then
    make_all
else
    for arg in "$@"; do
        case "$arg" in
            install)
                make_install
                ;;
            clean)
                make_clean
                ;;
            uninstall)
                make_uninstall
                ;;
            *)
                echo "Usage: $0 [install|clean|uninstall]"
                exit 1
                ;;
        esac
    done
fi

echo "=========== MAKE SUCCESS =========="

