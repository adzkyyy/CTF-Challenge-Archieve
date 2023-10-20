FROM ubuntu:latest

RUN apt update && apt install -y socat

WORKDIR /chall
COPY rust flag.txt /chall

RUN groupadd -r ctf && useradd -r -g ctf ctf
USER ctf
CMD ["/bin/bash", "-c", "exec socat -d TCP-LISTEN:5000,reuseaddr,fork EXEC:/chall/rust"]
