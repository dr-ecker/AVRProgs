#!/usr/bin/perl

use strict;
use Device::SerialPort;

my $port = Device::SerialPort->new("/dev/ttyUSB1");
$port->databits(8);
$port->baudrate(19200); # <-- match to arduino settings
$port->parity("none");
$port->stopbits(1);
$port->dtr_active(0); 
