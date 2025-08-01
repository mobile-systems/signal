It's a simple example test for alarm signal.

To run inside Docker (here `-m=10M` allows the container to use only 10Mb of memory):

```bash
$ docker build . --tag=signal
$ docker run -it -m=10M signal
```

If you want to step into Docker container and run the app manually, do this:

```bash
$ docker run -it --entrypoint=/bin/bash signal
```
