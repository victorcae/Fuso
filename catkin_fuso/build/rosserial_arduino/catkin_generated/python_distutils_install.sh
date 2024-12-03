#!/bin/sh

if [ -n "$DESTDIR" ] ; then
    case $DESTDIR in
        /*) # ok
            ;;
        *)
            /bin/echo "DESTDIR argument must be absolute... "
            /bin/echo "otherwise python's distutils will bork things."
            exit 1
    esac
fi

echo_and_run() { echo "+ $@" ; "$@" ; }

echo_and_run cd "/home/robofeiathome/catkin_fuso/src/rosserial/rosserial_arduino"

# ensure that Python install destination exists
echo_and_run mkdir -p "$DESTDIR/home/robofeiathome/catkin_fuso/install/lib/python3/dist-packages"

# Note that PYTHONPATH is pulled from the environment to support installing
# into one location when some dependencies were installed in another
# location, #123.
echo_and_run /usr/bin/env \
    PYTHONPATH="/home/robofeiathome/catkin_fuso/install/lib/python3/dist-packages:/home/robofeiathome/catkin_fuso/build/rosserial_arduino/lib/python3/dist-packages:$PYTHONPATH" \
    CATKIN_BINARY_DIR="/home/robofeiathome/catkin_fuso/build/rosserial_arduino" \
    "/usr/bin/python3" \
    "/home/robofeiathome/catkin_fuso/src/rosserial/rosserial_arduino/setup.py" \
     \
    build --build-base "/home/robofeiathome/catkin_fuso/build/rosserial_arduino" \
    install \
    --root="${DESTDIR-/}" \
    --install-layout=deb --prefix="/home/robofeiathome/catkin_fuso/install" --install-scripts="/home/robofeiathome/catkin_fuso/install/bin"
