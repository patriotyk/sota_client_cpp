[Unit]
Description=Sota Client
After=network.target
[Service]
Type=simple
ExecStart=${CMAKE_INSTALL_PREFIX}/bin/sota_client /etc/sota.toml
ExecReload=/bin/kill -s USR1 $MAINPID
WatchdogSec=10
Restart=always
User=nobody
Group=nobody
[Install]
WantedBy=multi-user.target
