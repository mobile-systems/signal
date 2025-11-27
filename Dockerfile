FROM registry.astralinux.ru/library/astra/ubi18:1.8.4
LABEL "org.opencontainers.image.vendor"="Alexander Ocheretin <mobidev@yandex.ru>"
WORKDIR /tmp

#RUN apt update -y && apt upgrade -y --enable-upgrade && apt install -y build-essential && apt install -y cmake ninja-build && apt-get clean && rm -rf /var/lib/apt/lists/*

COPY build/sigAlarm /tmp
#RUN cd /tmp && cmake . && make 

ENTRYPOINT ["/tmp/sigAlarm"]
