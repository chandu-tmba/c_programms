# c_programms
sample c programms


```
 +----------------+          dbus calls                   +------------------------+  cmd1  +--------------------------+
 |     BMCWeb     |  <----------------------------------> |   GPU                  |  <---->| GPU OOB                  |
 |     Service    |  (xyz.openbmc_project.Memory.<iface>) |   Manager              |  cmd2  | Server                   |
 |                |                                       |  (backend dbus service)|  <---> | (hardware level service) |
 +----------------+                                       +------------------------+        +--------------------------+
```
