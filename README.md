# c_programms
sample c programms


```

+-----------------------------------------------------------------------------+
|+-------------+          dbus calls                   +-------------------+  | cmd1  +-------------------+
| |   BMCWeb    |  <----------------------------------> |   GPU             | | <---->| GPU Out of band   |
| |   Service   |  (xyz.openbmc_project.Memory.<iface>) |   Manager         | | cmd2  | Server            |
| |             |                                       |  (backend dbus    | |<--->  | (hardware level ) |
| |             |                                       |   service)        | |       |  service)         |      
| +-------------+                                       +-------------------+ |       +-------------------+
|                        BMC                                                  |
+-----------------------------------------------------------------------------+ 
```
