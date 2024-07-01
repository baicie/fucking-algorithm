# 使用官方的Ubuntu基础镜像
FROM ubuntu:20.04

# 防止在安装期间交互
ENV DEBIAN_FRONTEND=noninteractive

# 使用清华大学的镜像源并禁用APT签名检查
RUN sed -i 's|http://archive.ubuntu.com/ubuntu/|http://mirrors.aliyun.com/ubuntu/|g' /etc/apt/sources.list && \
    sed -i 's|http://security.ubuntu.com/ubuntu|http://mirrors.aliyun.com/ubuntu|g' /etc/apt/sources.list && \
    apt-get update --allow-unauthenticated && apt-get install -y \
    wget \
    bzip2 \
    ca-certificates \
    curl \
    git \
    && rm -rf /var/lib/apt/lists/*

# 下载并安装Miniconda
RUN wget --quiet https://repo.anaconda.com/miniconda/Miniconda3-latest-Linux-x86_64.sh -O ~/miniconda.sh && \
    /bin/bash ~/miniconda.sh -b -p /opt/conda && \
    rm ~/miniconda.sh

# 将Conda添加到PATH环境变量中
ENV PATH /opt/conda/bin:$PATH

# 安装一些基础的包和清理
RUN conda update conda && \
    conda install numpy pandas && \
    conda clean -a -y

# 设置工作目录
WORKDIR /workspace

# 指定默认的启动命令
CMD ["bash"]
