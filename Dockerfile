FROM alpine

RUN apk update

RUN apk add g++ make

COPY . .

RUN make install

CMD ["oven", "100"]