FROM gcc:9.2

ENV DEBIAN_FRONTEND noninteractive

# install necessary tools and locales
RUN apt-get update  && apt-get install -y \
    git bash tar locales \
    python3 python3-pip \
    && echo "en_US.UTF-8 UTF-8" > /etc/locale.gen && locale-gen\
    rm -rf /var/lib/apt/lists/* 

# install CMake
RUN wget -qO- "https://cmake.org/files/v3.22/cmake-3.22.0-linux-x86_64.tar.gz" \
    | tar --strip-components=1 -xz -C /usr/local

# Install conan
RUN python3 -m pip install --upgrade pip setuptools && \
    python3 -m pip install conan && \
    conan --version

COPY . /usr/src/maze
WORKDIR /usr/src/maze

RUN chmod +x scripts/create_package.sh
CMD ["./scripts/create_package.sh"]