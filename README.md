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

![GitHub Logo](/images/output.jpg)