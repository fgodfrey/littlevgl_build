# littlevgl_build
Basic environment to build console apps with Little VGL.

This project uses Git submodules.  If you haven't worked with them before, they're just links from this Git repo to other Git repo's.
After you clone this repository, cd into it and run:  "git submodule update --init --recursive".

Little VGL doesn't include a build system.  This is a basic build system that I wrote for another project
which I have imported for Little VGL.  It could use a lot of improvement, but it can probably get you
up and running.  It has submodules that bring in branches of my clones of lvgl and lv_drivers.

The lv_conf.h and lv_drv_conf.h are configured to use the Linux Framebuffer but are otherwise the
defaults.
