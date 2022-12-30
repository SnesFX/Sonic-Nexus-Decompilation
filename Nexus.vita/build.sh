#!/bin/sh
sudo docker run \
    --rm \
    -v $PWD/..:/work \
    -w /work/SonicNexus.vita \
    vitasdk/vitasdk \
    /bin/sh -C "./build-internal.sh"
