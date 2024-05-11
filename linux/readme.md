## 文件系统

 根目录为/ ，其下面会有很多目录，如bin boot dev等

常见的是 /bin:存放经常使用的命令

/boot:存放启动linux的一些核心文件

/dev：存放linux的外部设备

/etc:存放所有系统管理所需要的配置

/opt:主机额外安装软件所摆放的目录

/proc:进程



## vim 操作

常见操作：

**命令模式**： 0 移动到这一行最前面，$ 移动到这一行最后面 <br>

H移动到屏幕当前位置的最开始 <br>

M移动到中央 <br>

L移动到当前位置的最后 <br>

G移动到最后一行，nG移动到第n行，gg移动到第一行 <br>



dd 删除光标坐在的那一行 <br>

yy 赋值光标所在那一行 <br>

u 复原前一个动作 <br>

y1G 复制光标到第一行所有内容 yG复制光标到最后一行的所有内容  <br>

y0复制光标到行开始的字符 y$复制光标到行末尾的字符 <br>



查找字符

:wq 保存或退出 <br>

:q! 如果有修改了不想保存，强制退出 <br>

?word 在光标之上查找word  <br>

/word是在光标之下查找word <br>

显示行号和不打开行号 ： set nu 和 set nonu <br>



替换当前这一行第一个匹配的    :s/abc/123 <br>

替换当前这一行所有匹配的        :s/abs/123/g <br>

替换每一行匹配的第一个 			:%s/abc/123 <br>

替换每一行匹配的所有				 :%s/abc/123/g <br>



## 网络配置

更改静态地址 ，一下具体地址得看vmware - 编辑 - 虚拟网络编译器<br>

vim etc/sysconfig/network-scripts/ifcig-ens33 <br>

先更改类型 <br>

BOOTPROTO="static" <br>

加入ip地址、网关、dns地址 <br>

IPADDR=192.168.202.100 //配置ip地址 <br>

GATEWAY=192.168.202.2 //网关 <br>

DNS1=192.168.202.2//配置与网关地址一样即可 <br>

然后重启网络 <br>

service network restart 接着再查看ifconfig就发现ip地址已经改变 <br>



## 用vsftpd传输文件

首先在windows下载filezilla

新建站点连接linux虚拟机的ip地址

拖拽文件即可



## 系统管理

一个正在执行的程序或命令，被叫做进程<br>

启动之后一直存在内存的进程，被称为服务<br>



## 文件目录

硬链接、软连接



## 权限

### 用户管理

linux中相关用户账户的信息存在/etc/passwd文件里<br>

useradd 用户名 / useradd -g 组名 用户名<br>

分为9个域，只需知道大致的含义即可。主要是用户登录名 + 加密后的口令(*表示非登录用户，!!表示没设置密码) <br>

用例子来教程<br>

```mark
新建用户u s e r 3，UID为1 0 1 0，指定其用户的主目录为
/home/user3，用户的shell为/bin/bash，用户的密码为123456，账户永不过期
```



```shell
useradd -u 1010 -d /home/user3 -s /bin/bash -p 123456 -f -1 user3
```

通过这个例子我们可以知道<br>

```mark
-u 指定用户的uid
-m 如果用户主目录不存在则创建它
-d 指定用户的主目录
-s 指定用户登录的shell
-p 设置密码
-f 设置用户多少天之后被禁用， -1 是永久不过期
```



查看账户信息<br>

```shell
id <username> # 查看用户的uid、gid和用户所属群组
who am i # 查看当前用户名
w # 查看当前登录系统的用户的详细信息
```

删除账户信息<br>

```shell
userdel 用户名
```



用户身份切换<br>

```shell
su -root #切换到root账户

sudo visudo # 进行配置文件
 #允许使用的主机= (以谁的身份) 可执行的列表
root ALL=(ALL) ALL
```



修改用户jone的uid为2000，shell为/bin/csh最后删除该用户

```shell
sudo visudo #先修改来确保权限没有问题 进去编辑的是/etc/sudoers
jone ALL=(ALL) ALL # 任何主机 任何使用者可以执行 可以执行的命令
--------------
usermod -u 2000 -s /bin/csh jone

sudo userdel -r jone

```

使用命令创建用户组group1，并设置其GID为3000，在用户组group1中添加两个之前批量创建的用户

```shell
sudo groupadd -g 3000 group1
sudo usermod -aG group1 jone
```

批量创建用户

```shell
touch userfile.txt
其内容类似于
jone1:x:520:520::/home/jone:/sbin/nologin 
touch userpwdfile.txt # 创建账户密码
其内容类似于，账户名和上面对应
jone1:123456

sudo newuser < userfile.txt
sudo chpasswd < usepwdfile.txt

```



### 文件权限

linux的文件肯定有权限，具体可以通过ls -al可以看到对应的权限

```shell
drwxrwxrwx 第一位—代表当前是文件 d代表当前是目录 后面是相关权限
第一段rwx 代表该文件的拥有者的权限 读（read）写（write)执行（execute）
第二段rwx 代表该文件所属群组的用户的权限
第三段rwx 代表其他用户的权限
分别对应 user group other 也是常说的ugo
```

```markdown
作用到文件
r:代表读入
w:代表可写，但不代表可以删除，要是删除得有当前目录的权限
x:可以执行
作用到目录
r:可以读取 ls 
w:目录内 创建 删除 重命名 mkdir rm
x 可以进入该目录 cd
```
修改文件权限的命令

```shell
# 第一种方法
chmod {ugoa} {+-=} {rwx} 文件目录
这里a的意思是all也就是全部，然后+-=就是字面意思的增加 删除 赋予
如想改拥有的用户+写和执行的权限
chmod u +wx test

#第二种方法
chmod 664 abc 意思就是权限改为rw-rw-r--
也就是一个二进制对应4+2+1
```
更改文件所有者

```shell
sudo chown root tt.txt
```



## 搜索查找

find 查找文件或者目录 <br>



## 磁盘与进程

查看目录大小

```shell
ls -lh

# 所有大小命令
du 目录
-h 以人们阅读方便的格式
-a 不仅看子目录大小，还看文件
-c 显示大小后显示总和
-s 只显示总和
```

查看磁盘空间使用情况

```shell
df -h
```

查看设备挂载点

```shell
lsblk
```

内存分配情况

```shell
free -h
```

查看进程

```shell
ps aux | grep 查看系统中所有进程
ps -ef | grep 查看子父进程直接的关系
# a带有终端的所有用户的进程
# u面向用户友好的显示风格
# x列出当前用户的所有进程，包括没在终端的
# e列出所有进程
# f显示完整格式的进程列表
```

终止进程

```shell
kill -9 5105 强制杀死进程
```

监控进程

```shell
top
```
## shell脚本

开始最简单的shell, 我们可以vim hello.sh进行编写，bash hello.sh读写

```shell
echo "hello, world"
```

系统变量

```shell
$HOME $PWD ...
```

自定义变量

```shell
var="hello , world"
echo var

var=hello , world  #这种带有空格的不行，用上述引号的格式就可以解决
```

我们查看具体变量是全局变量还是局部变量

```shell
env | grep my_var
set | grep my_var
```

将一个变量导出 变成全局变量

```shell
export $my_var
env | grep my_var
```

整个流程

```shell
vim hello.sh # 创建shell脚本
chmod +x hello.sh # 创建执行权限
./hello.sh #就可以运行
```

特殊符号

```shell
$0 执行的脚本名称 $1 $2 脚本携带的参数
$# 输出参数个数
$@ 表示变量列表 
$* 代表"$1 $2 $3" 默认用空格对变量进行分隔
```

用一个例子来看一下区别

```shell
# exmple.sh
for arg in "$*"; do
	echo $arg
done

echo "----------"

for arg in "$@";do
	echo $arg
done

#./exmple.sh "1 2 3 4 5" 2 3 4 5
```

输出为

```markdown
1 2 3 4 5 2 3 4 5

----------------------

1 2 3 4 5
2
3
4
5

```

所以说$*是作为一个整体

```shell
num=0
for arg in "$@"; do
	if [ arg == '123' ]; then
		$((num++))
	fi
done

echo $num
```

条件判断

```shell
数字类型比较
-eq 等于
-ne 不等于
-lt 小于
-le 不等于
-gt 大于
-ge 大于等于  e是equal 这样好记一些
判断文件权限
-r
-w
-x
按照文件类型进行判断
-e 文件存在
-f 文件存在并且是一个常规的文件
-d 文件存在并且是一个目录

判断目录的cls.txt文件是否存在
-e /home/atguigu/cls.txt
```

判断该目录是否有 参数1文件或参数2文件

```shell
if [ -e "$1" ]; then
	echo "is right"
elif [ -e "$2" ];then
	echo "is second right"
else
	echo "is not right"
fi
```

计算1-100之和

```shell
sum=0
for ((i=1; i<=100 ;i++)); do
	sum=$(($sum + $i))
done
echo $sum
```

读入

```shell
# -t 代表等待时间 -p 后面输出提示信息
read -t 10 -p "please enter something." name
echo "你写的是$name"
```



## linux c

```markdown
首先我们创建一个include目录,里面是add.h和sub.h
创建一个src目录,里面是add.c和sub.c
大概是./include ./src main.c 这样
```

静态库

顾名思义就是编译完当成一个库使用,我们写一个makefile

```makefile
test: main.o add.o sub.o
	gcc main.o add.o sub.o -o test
	cp main.o add.o sub.o lib
	ar rcs lib/libcal.a main.o add.o sub.o
	gcc -o main main.o -Llib -lcal
main.o: main.c
	gcc main.c -c -o main.o
add.o: add.c
	gcc add.c -c -o add.o
sub.o: sub.c
	gcc sub.c -c -o sub.o
```

动态库

```shell
gcc -fPIC *.c -I include -c
gcc -shared -o libmath.so *.o
gcc main.c -L. -lmath -Iinclude -o test
./test
```




