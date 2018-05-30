# littlevgl_build
Basic environment to build console apps with Little VGL.

Little VGL doesn't include a build system.  This is a basic build system that I wrote for another project
which I have imported for Little VGL.  It could use a lot of improvement, but it can probably get you
up and running.  It has submodules that bring in branches of my clones of lvgl and lv_drivers.

The lv_conf.h and lv_drv_conf.h are configured to use the Linux Framebuffer but are otherwise the
defaults.
