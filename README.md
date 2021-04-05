## What's this?

This is a small C++ utility which query daemon about VOTE2021 addresses balances and output .txt or .html table with candidates balances in standart output.

Utility requires VOTE2021 daemon running with following parameters in `VOTE2021.conf`:
```
rpcuser=user2221517864
rpcpassword=pass428e1eb1b70448774f7e04a4d39c8624caa769a5256a4e00d3323b040f440ddacb
rpcport=55638
server=1
rpcworkqueue=256
rpcallowip=127.0.0.1
rpcbind=127.0.0.1

txindex=1
addressindex=1
timestampindex=1
spentindex=1
```

## How to build?

```
git clone --recursive https://github.com/DeckerSU/votebalances
g++ -g stats.cpp curlite/curlite.cpp utilstrencodings.cpp -std=c++11 -I./rapidjson/include -lcurl -o stats
```

## Output example

### HTML
![GitHub Logo](/images/output.jpg)
### Plain text
For plain-text output set the following variable to false:
```
const bool fHTML = false;
```
Result will be like this:
```
AR

1.	               ocean	R9Jny2pGVYVLjfxsiYCYtf7C6fgd3zxNH6	       2694.39153781 VOTE2021
2.	              decker	RHeRFNk2jih5oFedJpgFXx8wPANv5iiFg7	       2000.35000000 VOTE2021
3.	           dudezmobi	RA7VoAW811sZS6CPaM3CwS4VyNyLzmNcKy	         86.99995000 VOTE2021
4.	                kolo	RKCXF7EYaAJHmiyDKmubhQ88dYc7CbTZxx	         76.19995000 VOTE2021
5.	                paro	RScDpTu2m23qrufjpK5nh2M6M3x2L8pLuo	          0.06112091 VOTE2021
```