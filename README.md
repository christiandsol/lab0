# A Kernel Seedling
TODO: intro

## Building
```shell
make
sudo insmod proc_count.ko
```


## Running
```shell
/proc/count
```
Result: The number of processes currently running on the system
## Cleaning Up
```shell
make clean
sudo rmmod proc_count
```

## Testing
```python
python -m unittest
```
Results: 
```
...
----------------------------------------------------------------------
Ran 3 tests in 8.903s

OK
```

## System Information
```shell
uname -r -s -v
```
Result:
Linux 5.14.8-arch1-1
