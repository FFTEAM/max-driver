#*******************************************************************************
# Copyright (C) 2010   STMicroelectronics. All Rights Reserved.
# This file is part of the latest release of the Multicom4 project. This release 
# is fully functional and provides all of the original MME functionality.This 
# release  is now considered stable and ready for integration with other software 
# components.

 # Multicom4 is a free software; you can redistribute it and/or modify it under the 
# terms of the GNU General Public License as published by the Free Software Foundation 
# version 2.

# Multicom4 is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; 
# without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
# See the GNU General Public License for more details.

# You should have received a copy of the GNU General Public License along with Multicom4; 
# see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - 
# Suite 330, Boston, MA 02111-1307, USA.

# Written by Multicom team at STMicroelectronics in November 2010.  
# Contact multicom.support@st.com. 
#*******************************************************************************

#
# Linux specific Makefile for embxmailbox subsystem module
#
#

ifneq ($(KERNELRELEASE),)

#
# Inside Linux kernel tree
#

obj-m   := embxmailbox.o

# EMBX specific CFLAGS
EXTRA_CFLAGS += -I$(obj)/../../include -I$(obj)/../ics/include -I$(obj)/../embx/include -I$(obj)/include  $(DEBUG_CFLAGS) $(MULTICOM_EXTRA_CFLAGS)

embxmailbox-objs := \
	embx_mailbox.o \
	linux/module.o
else

#
# Outside Linux kernel tree
#
PWD	     := $(shell pwd)

V            ?= 0

ARCH         ?= sh

CROSS_COMPILE ?= sh4-linux-

default:
	$(MAKE) V=$(V) ARCH=$(ARCH) CROSS_COMPILE=$(CROSS_COMPILE) -C $(KERNELDIR) O=$(O) SUBDIRS=$(PWD) modules

clean:
	$(MAKE) V=$(V) ARCH=$(ARCH) CROSS_COMPILE=$(CROSS_COMPILE) -C $(KERNELDIR) O=$(O) SUBDIRS=$(PWD) clean

endif
