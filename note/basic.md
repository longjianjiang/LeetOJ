这里记录一些刷题过程中，需要注意的点。

- 整型溢出

1> 算mid的时候，直接相加除2可能溢出；

```
int mid = left + (right - left) / 2;
```

2> int相加结果需要使用long long，防止溢出；
