
FROM debian:11.4-slim

ARG DEBIAN_FRONTEND=noninteractive
RUN apt-get update
RUN apt-get install -y build-essential libboost-system-dev libboost-thread-dev libboost-program-options-dev libboost-test-dev libbox2d-dev libsfml-dev
RUN apt-get install -y make cmake git

COPY . /cement

WORKDIR /cement

CMD ["make", "run"]