FROM gcc AS mybuildstage

MAINTAINER omegazyadav <omegazyadav1@gmail.com> 

COPY sl sl

WORKDIR sl

RUN make  

FROM ubuntu

COPY --from=mybuildstage sl . 

CMD ["./sl"]

