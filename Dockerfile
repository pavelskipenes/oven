FROM alpine:3.3

WORKDIR /app

RUN apk --no-cache add g++ make

COPY . .

RUN make install

CMD ["oven", "100"]

