FROM alpine
RUN apk update && apk upgrade && apk add nano make gcc build-base
RUN mkdir work && cd work
COPY lab5.c /work
COPY Makefile /work
COPY script.sh /work
RUN cd /work && make build
RUN cd /work && make install
RUN cd /work && make clean
CMD sh /work/script.sh
