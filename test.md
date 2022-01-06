## PSU Monitor Application

Author: chandrasekhart@ami.com

Primary assignee: chandrasekhart@ami.com

Created: December 17, 2021


## Proposed Design

•	LIBI2C will be used to read CPLD register values. \
•	PSU Monitor App will use psu register configuration file  ,it will have details for I2c Bus number Register address and Sensor’s bit values.\
•	CPLD dev slave address 0x78(0x3c) \
•	Register Address – 0x25 (PSU_DETECT), 0x26(PSU_ALERT), 0x27(PSU_WORK), 0x28(PSU_EVE) 
•	PSU Detect sensors 

1.	Psudetect0
2.	Psudetect1
3.	Psudetect2
4.	psudetect3
5.	psudetect4
6.	psudetect5

•	PSU ALERT Sensors

1.	psualert0
2.	psualert1
3.	psualert2
4.	psualert3
5.	psualert4
6.	psualert5

•	PSU WORK Sensors 	

1.	psuwork0
2.	psuwork1
3.	psuwork2
4.	psuwork3
5.	psuwork4
6.	psuwork5

•	PSU EVE Sensors

1.	psueve1
2.	psueve2

•   PSU dbus objects will be retrived based on the interface xyz.openbmc_project.Inventory.Item.PowerSupply and dbus properties will be updated based on cpld registers using polling mechanism

•	While creating dbus service and psu event objects, we will initialize the sensors from registers using libI2C, and polling mechanism  will be followed to monitor the register changes. 

•	Other applications can monitor these dbus properties and corresponding actions can be taken like Logging SEL events, Initiating Power OFF operation etc. 

## sequence diagram

![image](https://user-images.githubusercontent.com/87798274/148245447-a2869251-d091-4a24-a4bf-9b4b78468c8d.png)


## Dbus Details


| DBUS Service Name                                      |    <br>DBUS   Objects                                                    |    <br>Interfaces   Implemented                                                                                                                                                                                                                                                                                                                                                                           |
|--------------------------------------------------------|--------------------------------------------------------------------------|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| xyz.openbmc_project.inventory.cpld_psu_manager.service |    /xyz/openbmc_project/inventory/system/chassis/psu1    | xyz.openbmc_project.Inventory.Item<br>Properties<br>PrettyName (string)   <br>Present   (Boolean)<br><br>PSU1_DETECT-> Present property<br><br>xyz.openbmc_project.State.Decorator.PowerState<br>properties<br>PowerState (Enum)<br><br>PSU1_WORK -> PowerState property<br><br>xyz.openbmc_project.State.Decorator.OperationalStatus<br>properties<br>Functional (Boolean)<br><br>PSU1_ALERT->  Functional property |
| xyz.openbmc_project.inventory.cpld_psu_manager.service |    /xyz/openbmc_project/inventory/system/chassis/psu2    | xyz.openbmc_project.Inventory.Item<br>Properties<br>PrettyName (string)   <br>Present   (Boolean)<br><br>PSU2_DETECT-> Present property<br><br>xyz.openbmc_project.State.Decorator.PowerState<br>properties<br>PowerState (Enum)<br><br>PSU2_WORK -> PowerState property<br><br>xyz.openbmc_project.State.Decorator.OperationalStatus<br>properties<br>Functional (Boolean)<br><br>PSU2_ALERT->  Functional property |
| xyz.openbmc_project.inventory.cpld_psu_manager.service |    /xyz/openbmc_project/inventory/system/chassis/psu3    | xyz.openbmc_project.Inventory.Item<br>Properties<br>PrettyName (string)   <br>Present   (Boolean)<br><br>PSU3_DETECT-> Present property<br><br>xyz.openbmc_project.State.Decorator.PowerState<br>properties<br>PowerState (Enum)<br><br>PSU3_WORK -> PowerState property<br><br>xyz.openbmc_project.State.Decorator.OperationalStatus<br>properties<br>Functional (Boolean)<br><br>PSU3_ALERT->  Functional property |
| xyz.openbmc_project.inventory.cpld_psu_manager.service |    /xyz/openbmc_project/inventory/system/chassis/psu4    | xyz.openbmc_project.Inventory.Item<br>Properties<br>PrettyName (string)   <br>Present   (Boolean)<br><br>PSU4_DETECT-> Present property<br><br>xyz.openbmc_project.State.Decorator.PowerState<br>properties<br>PowerState (Enum)<br><br>PSU4_WORK -> PowerState property<br><br>xyz.openbmc_project.State.Decorator.OperationalStatus<br>properties<br>Functional (Boolean)<br><br>PSU4_ALERT->  Functional property |
| xyz.openbmc_project.inventory.cpld_psu_manager.service |    /xyz/openbmc_project/inventory/system/chassis/psu5    | xyz.openbmc_project.Inventory.Item<br>Properties<br>PrettyName (string)   <br>Present   (Boolean)<br><br>PSU5_DETECT-> Present property<br><br>xyz.openbmc_project.State.Decorator.PowerState<br>properties<br>PowerState (Enum)<br><br>PSU5_WORK -> PowerState property<br><br>xyz.openbmc_project.State.Decorator.OperationalStatus<br>properties<br>Functional (Boolean)<br><br>PSU5_ALERT->  Functional property |
| xyz.openbmc_project.inventory.cpld_psu_manager.service |    /xyz/openbmc_project/inventory/system/chassis/psu6    | xyz.openbmc_project.Inventory.Item<br>Properties<br>PrettyName (string)   <br>Present   (Boolean)<br><br>PSU6_DETECT-> Present property<br><br>xyz.openbmc_project.State.Decorator.PowerState<br>properties<br>PowerState (Enum)<br><br>PSU6_WORK -> PowerState property<br><br>xyz.openbmc_project.State.Decorator.OperationalStatus<br>properties<br>Functional (Boolean)<br><br>PSU6_ALERT->  Functional property |
| xyz.openbmc_project.inventory.cpld_psu_manager.service |    /xyz/openbmc_project/sensors/power/psu_drop_to_2    | xyz.openbmc_project.Object.Enable<br>Properties<br>Enabled   (Boolean)<br><br>w_PSU_PWrok_drop_to_1_event->Enabled property |
| xyz.openbmc_project.inventory.cpld_psu_manager.service |    /xyz/openbmc_project/sensors/power/psu_drop_to_1    | xyz.openbmc_project.Object.Enable<br>Properties<br>Enabled   (Boolean)<br><br>w_PSU_PWrok_drop_to_1_event->Enabled property |

## Dbus Interface Links for Reference
xyz. openbmc_project. Inventory.Item  (https://github.com/openbmc/phosphor-dbus-interfaces/blob/master/yaml/xyz/openbmc_project/Inventory/Item.interface.yaml )\
xyz. openbmc_project.State.Decorator.PowerState  ( https://github.com/openbmc/phosphor-dbus-interfaces/blob/master/yaml/xyz/openbmc_project/State/Decorator/PowerState.interface.yaml )\
xyz.openbmc_project.State.Decorator.OperationalStatus (https://github.com/openbmc/phosphor-dbus-interfaces/blob/master/yaml/xyz/openbmc_project/State/Decorator/OperationalStatus.interface.yaml )\
xyz.openbmc_project.Object.Enable (https://github.com/openbmc/phosphor-dbus-interfaces/blob/master/yaml/xyz/openbmc_project/Object/Enable.interface.yaml )





