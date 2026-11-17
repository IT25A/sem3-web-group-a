FROM debian:bookworm-slim AS builder

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y --no-install-recommends \
    build-essential \
    git \
    ca-certificates \
    && rm -rf /var/lib/apt/lists/*

RUN git clone --depth 1 https://github.com/xtensor-stack/xtl.git /tmp/xtl \
    && cp -r /tmp/xtl/include/xtl /usr/local/include/ \
    && rm -rf /tmp/xtl

RUN git clone --depth 1 https://github.com/xtensor-stack/xtensor.git /tmp/xtensor \
    && cp -r /tmp/xtensor/include/xtensor /usr/local/include/ \
    && rm -rf /tmp/xtensor

RUN apt-get update && apt-get install -y --no-install-recommends \
    build-essential \
    git \
    ca-certificates \
    libasio-dev \
    && rm -rf /var/lib/apt/lists/*	 


WORKDIR /app

COPY . .

RUN gcc -O2 -o _nob nob.c

RUN ./_nob

FROM debian:bookworm-slim AS runtime

WORKDIR /app

COPY --from=builder /app/bin/server ./server
COPY --from=builder /app/src ./src

EXPOSE 8080

CMD ["./server"]