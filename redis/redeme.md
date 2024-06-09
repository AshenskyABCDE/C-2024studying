

# redis相关

查看redis是否打开：

```
sudo systemctl status redis
```

启动redis 命令行

```
redis-cli -h 127.0.0.1 -p 6379 -a password 
```

基本命令

```
SET 增 （可直接覆盖)
DEL 删
GET 查
```



# 基本数据结构

## hash

```
HSET 
HGET
HMSET 可以传多个
HMGET 可以获得多个
HGETALL 获取所有的字段。
```

## List

```
Lpush users 1
Lpop user
```

### 如何用List模仿一个栈、队列、阻塞队列？

栈：Lpush Lpop

队列: Lpush Rpop 或 Rpush Lpop

阻塞队列：队列 且 出队应采用 BLPOP 和 BRPOP

## set

```markdown
SADD key member ... 像set中添加一个或多个元素
SREM key member ... 移除set中的指定元素
SISMEMBER key member : 判断一个元素是否存在set中
SMEMBERS ： 获取set中的所有元素
SINTER key1 key2 求key1和key2的交集
SDIFF key1 key2 求key1和key2的差集
```

### 练习

```
张三好友有:李四，王五，赵六
李四好友有:王五，麻子，二狗

计算张三的好友有几人
SCARD zs

计算张三和李四有哪些共同好友
SINTER zs ls

查询哪些人是张三的好友却不是李四的好友
SDIFF zs ls

查询张三和李四的共同好友
SUNION zs ls

判断李四是否是张三的好友
SISMEMBER zs ls

将李四从张三的好友列表中移除
SREM zs ls
```



# sortedSet(Zset)

```
ZADD key socre member
ZREM key member
```

### 练习:

```
删除tom 同学
ZREM test_STU tom

获取AMY 同学的分数
ZSCORE test_STU AMY

获取ROSE同学的排名
ZRANK test_STU ROSE

查询80分以下有几个同学
ZCOUNT test_STU 0 80

给AMY同学加2分
ZINCRBY test_STU 2 AMY

查出成绩前3名的同学
ZREVRANGE test_STU 0 2

查出成绩80分以下的所有同学
ZRANGEBYSCORE test_STU 0 80
```



