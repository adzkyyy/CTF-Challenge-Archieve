FROM ubuntu:latest

RUN apt update && apt install socat python3 -y
WORKDIR /app
COPY chall.py /app
RUN chmod +x /app/chall.py
EXPOSE 5000

CMD socat TCP-LISTEN:5000,reuseaddr,fork EXEC:/app/chall.py,su=nobody
