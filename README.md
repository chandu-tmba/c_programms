# Password Policy
Author: Lucas Panayioto lucasp@ami.com
Primary assinee: Lucas Panayioto lucasp@ami.com
Created: 2021-10-20



## Problem Description

The Current password requirement only has a minimal length of 8 characters and there is currently no way to change this from the user side.

## Background and References

BMC shall provide various level of password complexity to meet different needs, it is used to avoid less complicated password for security consideration.

Password policy settings shall contain password complexity and password history configuration. Password complexity defines what character patterns are allowed to use, password history defines how old password can be reused. History can be set up to 5 and 0 to disable. Password Complexity has 3 levels (low,medium,high) and it can be disabled.


## Requirements

The requirements are:
### Disabled 
* Require the minimum length of 8
### Low
* Contains printable characters only
* Password length should not be shorter than 6 characters
* Meets following 3 criteria:
             1. Contains upper case (e.g. A, G)
             2. Contains lower case (e.g. a, g)
             3. Contains digit numbers (e.g. 1, 6)
             4. Contains symbols (e.g. $, &)
* Could not contains user name (case insensitive) (e.g., username=Hello, Password=th12(heLLo)_78 is not allowed)
### Medium
* Contains printable characters only
* Password length should not be shorter than 8 characters
* Cannot be the same as the user name or the user name in reverse order.
* Have at least two new characters when compared with the previous password.
* Meets following 4 criteria:
              1. Contains upper case
              2. Contains lower case
              3. Contains digit numbers
              4. Contain at least a space or symbols
### High
* Contains printable characters only
* Password length should not be shorter than 8 characters
* Meets following 4 criteria:
              1. Contains upper case
              2. Contains lower case
              3. Contains digit numbers
              4. Contains symbols
* Could not contains user name (case insensitive)
* Have at least two new characters when compared with the previous password.
* Could not contains continuous digits longer than 3 characters (e.g. BMC(123)ste, BMC(654)sfc are not allowed)
* Could not contains continuous alphabets longer than 3 characters (e.g. (AbC)3478!, 57$(DeF)68k are not allowed))
* Alphabets could no longer than 3 characters (e.g. (Fher)145! are not allowed))
* Digits could no longer than 3 characters (e.g. Fgke(1245)#@, (4390)FGL$ are not allowed)
* Contains no more than 3 same alphabets(case insensitive) (e.g. Fkr4fcpF&f (4 'f' or 'F'), Glg5gt2G! (4 'g' or 'G') are not allowed)

The use case:
* The bmc webui will have a setting to change the password complexity and the password depth


## Proposed Design
<pre>
┌──────────┐            ┌──────┐              ┌────────────┐
│UI/Redfish│            │bmcweb│              │user-manager│
└────┬─────┘            └───┬──┘              └──────┬─────┘
     │   Save Settings      │                        │
     ├─────────────────────►│                        │
     │                      │                        │
     │                      │      set dbus          │
     │                      ├───────────────────────►│
     │                      │                        │
     │                      │                        │
     │                      │                        │

</pre>

The design has 2 main parts:

### Back-end: 
1. The Backend will add a new dbus property "PasswordPolicyComplexity" and utilize the "RememberOldPasswordTimes" property. 

>     - name: PasswordPolicyComplexity
>       type: string
>       description: >
>           Configure the Password Policy Complexity. 
>           Disabled, Low, Medium, or High 
>       errors:
>           - xyz.openbmc_project.Common.Error.InternalFailure 

2. They will follow the same path as "AccountUnlockTimeout" property in the bmcweb module, since they will be in the same menu on webui.
3. Updating these properties will call rememberOldPasswordTimes or passwordPolicyComplexity (new) in phosphor-user-manager
4. These fuctions update the pam modules to meet the new password policy requirements.
5. setPamModuleArgValue() will need to be updated to handle arguments without "=" and deleting arguments 
6. Creating a custom pam module "pam_ipmipwquality" in pam-ipmi to handle the Password Similarity requirement for Medium and High. The difok argument from pam_cracklib doesn't work with current settings.

![flowchart for pam_ipmipwquality](pictures/passwordpolicyFlowchart.PNG)

7. The module will utilize the password file created in pam_ipmisave which uses AES 2-way encryption from openSSL to get the current password to check against the new password.
8. The module will port the difok checking funtions from pam_cracklib
9. The settings will be saved using cereal format in upgrade-perserve-config



### Redfish
Redfish Implementaiton will add 2 properties named PasswordPolicyComplexity and RememberOldPasswordTimes in Account service URI , by default these values will be zero, we can use patch request to change the default values.

GET /redfish/v1/AccountService

        - **response**
        ```json    	
	{
	"@odata.id":"/redfish/v1/AccountService",
	"@odata.type":"#AccountService.v1_5_0.AccountService",
	"AccountLockoutDuration":0,
	"AccountLockoutThreshold":0,
	"Accounts":{},
	"ActiveDirectory":{},
	"Description":"Account Service",
	"Id":"AccountService",
	"LDAP":{},
	"MaxPasswordLength":20,
	"MinPasswordLength":8,
	"Name":"Account Service",
	"Oem":{
		"OpenBMC":{
		"@odata.type":"#OemAccountService.v1_0_0.AccountService",
		"AuthMethods":{
			"BasicAuth":true,
			"Cookie":true,
			"SessionToken":true,
			"TLS":true,
			"XToken":true
			},
		"PasswordPolicyComplexity":0,
		"RememberOldPasswordTimes":0
		}
	},
	"Roles":{},
	"ServiceEnabled":true,
	"Status":{}
	}
   	 ```

PATCH /redfish/v1/AccountService

	- **request**
	```json
	{
		"Oem": 
		{
		"OpenBMC": {
                	"PasswordPolicyComplexity": 1,
                	"RememberOldPasswordTimes": 4
            	 }
		}
	}
	```
	
### Front-end: The frontend will add 2 new settings for password complexity and password history to the webui under security settings.

## Alternatives Considered

The following were designs considered:
* Complex vs simple - The initial design would have 2 choices, Complex and Simple. This was dropped in favor of adding the current one with 4 choices
* No Password history - Password history was not part of the initial design and was added for more complexity
* Dropping password similarity requirement - the password similarity (difok) setting from pam_cracklib doesn't work with current security settings. difok requires a security with 2-way encryption or no encryption.

## Impacts
Password History setting will create files on the BMC which contain the Passwords, albeit encrypted.

## Testing
	1. Testing each level of password Complexity will require several different passwords to be tested on each setting to make sure certain ones are blocked for each level
	2. Testing Password history is remembering the correct amount of passwords for each level
	3. Testing Password history is forgetting passwords when changing to a lower level
	4. Remembering Password policy settings after reset
