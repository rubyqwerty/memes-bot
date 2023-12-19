FROM ubuntu:latest

WORKDIR /usr/local/lib

RUN apt update &&\
    apt-get -y install g++ &&\
    apt-get -y install make &&\
    apt-get -y install binutils &&\ 
    apt-get -y install cmake &&\
    apt-get -y install libboost-system-dev &&\
    apt-get -y install libssl-dev &&\
    apt-get -y install zlib1g-dev &&\
    apt-get -y install libcurl4-openssl-dev &&\
    apt-get -y install git &&\
    git clone https://github.com/reo7sp/tgbot-cpp &&\
    cd tgbot-cpp &&\
    cmake . &&\
    make -j4 &&\
    make install &&\
    cd .. &&\
    git clone https://github.com/libcpr/cpr.git &&\
    cd cpr &&\ 
    mkdir build &&\ 
    cd build &&\ 
    cmake .. -DCPR_USE_SYSTEM_CURL=ON &&\
    cmake --build . --parallel &&\ 
    cmake --install .

WORKDIR /usr/local/memes-bot

COPY . .

RUN mkdir build && cd build && cmake .. && make 


ENTRYPOINT [ "./build/memes-bot" ]