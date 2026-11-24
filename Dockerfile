FROM debian:bookworm-slim AS builder

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y --no-install-recommends \
    build-essential \
    git \
    ca-certificates \
    && rm -rf /var/lib/apt/lists/*

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