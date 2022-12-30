#!/bin/sh
sudo docker run \
    --rm \
    -v $PWD/..:/work \
    -w /work/Nexus.vita \
    vitasdk/vitasdk \
    /bin/sh -C "./build-internal.sh"
