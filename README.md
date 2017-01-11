
sota_client_cpp rvi sample 
------

```
apt-get install gcc g++ make cmake git libjansson-dev libssl-dev autoconf automake pkg-config libtool libexpat1-dev libboost-program-options-dev libboost-test-dev libboost-regex-dev libboost-dev libboost-system-dev libboost-thread-dev libboost-log-dev libjsoncpp-dev curl libcurl4-openssl-dev
```
```
cmake .
```
```
make sota_client
```

Then You will need to change the `conf.json` with right client id
and `config/config.toml.example` in section rvi.

And run with the following command
`./target/sota_client -c config/config.toml.example --gateway-rvi=on --gateway-http=off`

and You should see
`rvi services registered` in output
also if `sota/notify` method called, You should see `rvi callback called`, but for me, it is never happen.