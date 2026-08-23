# SPDX-License-Identifier: GPL-2.0-only
# Copyright (C) 2018-2020 Serenity. All rights reserved.
ifdef CONFIG_SERENITY_SYSTEM_KERNEL_QCOM
obj-$(CONFIG_SERENITY_FEATURE_HUNG_TASK_ENHANCE) += hung_task_enhance.o
else
ifeq ($(CONFIG_SERENITY_FEATURE_HUNG_TASK_ENHANCE), y)
obj-$(CONFIG_SERENITY_FEATURE_HUNG_TASK_ENHANCE) += hung_task_enhance.o
endif
ifeq ($(CONFIG_SERENITY_FEATURE_HUNG_TASK_ENHANCE), m)
obj-$(CONFIG_SERENITY_FEATURE_HUNG_TASK_ENHANCE) += gki/hung_task_enhance.o
endif
endif
