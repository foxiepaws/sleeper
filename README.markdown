sleeper
=======

Sleep/Hibernate helper for Unixlike platforms


## Install

I'm not going to add a make install target as it involves setuid and I don't
really trust my code **THAT** much.

- 0. Read over all the code. ALL OF IT. decide if you actually want to use this
- 1. make
- 2. cp bin/sleeper /usr/local/sbin/
- 3. chmod 4555 /usr/local/sbin/sleeper # for everyone 
- 3. (alternate) chown root:power /usr/local/bin/sleeper ; chmod 4550 /usr/local/sbin/sleeper ; # for just people in the power group

## Usage

- sleep `sleeper -s`
-  hibernate `sleeper -H`
