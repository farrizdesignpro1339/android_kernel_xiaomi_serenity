// SPDX-License-Identifier: GPL-2.0-only
/*
 * Copyright (C) 2020-2020 Serenity. All rights reserved.
 */

#ifndef __SERENITY_CHG_H__
#define __SERENITY_CHG_H__

#include <linux/device.h>
#include <linux/version.h>

#ifdef SERENITY_CHG_DEBUG_LOG
#undef pr_info
#undef pr_debug
#define pr_info pr_err
#define pr_debug pr_err
#endif

enum serenity_chg_mod_type {
	SERENITY_CHG_MOD_COMMON,
	SERENITY_CHG_MOD_USB,
	SERENITY_CHG_MOD_WIRELESS,
	SERENITY_CHG_MOD_BATTERY,
	SERENITY_CHG_MOD_MAIN,
};

enum serenity_chg_event {
	SERENITY_CHG_EVENT_CHANGED,
	SERENITY_CHG_EVENT_ONLINE,
	SERENITY_CHG_EVENT_OFFLINE,
	SERENITY_CHG_EVENT_PRESENT,
	SERENITY_CHG_EVENT_NO_PRESENT,
	SERENITY_CHG_EVENT_APSD_DONE,
	SERENITY_CHG_EVENT_LCD_ON,
	SERENITY_CHG_EVENT_LCD_OFF,
	SERENITY_CHG_EVENT_CALL_ON,
	SERENITY_CHG_EVENT_CALL_OFF,
	SERENITY_CHG_EVENT_CAMERA_ON,
	SERENITY_CHG_EVENT_CAMERA_OFF,
	SERENITY_CHG_EVENT_OP_TRX,
	SERENITY_CHG_EVENT_CHECK_TRX,
	SERENITY_CHG_EVENT_ADSP_STARTED,
	SERENITY_CHG_EVENT_OTG_ENABLE,
	SERENITY_CHG_EVENT_OTG_DISABLE,
	SERENITY_CHG_EVENT_POWER_CHANGED,
	SERENITY_CHG_EVENT_CHARGE_DONE,
	SERENITY_CHG_EVENT_CLEAN_CHARGE_DONE,
	SERENITY_CHG_EVENT_SVOOC_ONLINE,
	SERENITY_CHG_EVENT_RX_IIC_ERR,
#ifdef SERENITY_CHG_REG_DUMP_ENABLE
	SERENITY_CHG_EVENT_REG_DUMP,
#endif
	SERENITY_CHG_EVENT_RX_FAST_ERR,
	SERENITY_CHG_EVENT_TX_EPP_CAP,
};

enum {
	SERENITY_CHG_STATUS_UNKNOWN = 0,
	SERENITY_CHG_STATUS_CHARGING,
	SERENITY_CHG_STATUS_DISCHARGING,
	SERENITY_CHG_STATUS_NOT_CHARGING,
	SERENITY_CHG_STATUS_FULL,
};

/* What algorithm is the charger using? */
enum {
	SERENITY_CHG_CHARGE_TYPE_UNKNOWN = 0,
	SERENITY_CHG_CHARGE_TYPE_NONE,
	SERENITY_CHG_CHARGE_TYPE_TRICKLE,	/* slow speed */
	SERENITY_CHG_CHARGE_TYPE_FAST,		/* fast speed */
	SERENITY_CHG_CHARGE_TYPE_STANDARD,	/* normal speed */
	SERENITY_CHG_CHARGE_TYPE_ADAPTIVE,	/* dynamically adjusted speed */
	SERENITY_CHG_CHARGE_TYPE_CUSTOM,	/* use CHARGE_CONTROL_* props */
};

enum {
	SERENITY_CHG_HEALTH_UNKNOWN = 0,
	SERENITY_CHG_HEALTH_GOOD,
	SERENITY_CHG_HEALTH_OVERHEAT,
	SERENITY_CHG_HEALTH_DEAD,
	SERENITY_CHG_HEALTH_OVERVOLTAGE,
	SERENITY_CHG_HEALTH_UNSPEC_FAILURE,
	SERENITY_CHG_HEALTH_COLD,
	SERENITY_CHG_HEALTH_WATCHDOG_TIMER_EXPIRE,
	SERENITY_CHG_HEALTH_SAFETY_TIMER_EXPIRE,
	SERENITY_CHG_HEALTH_OVERCURRENT,
	SERENITY_CHG_HEALTH_WARM,
	SERENITY_CHG_HEALTH_COOL,
	SERENITY_CHG_HEALTH_HOT,
};

enum {
	SERENITY_CHG_TECHNOLOGY_UNKNOWN = 0,
	SERENITY_CHG_TECHNOLOGY_NiMH,
	SERENITY_CHG_TECHNOLOGY_LION,
	SERENITY_CHG_TECHNOLOGY_LIPO,
	SERENITY_CHG_TECHNOLOGY_LiFe,
	SERENITY_CHG_TECHNOLOGY_NiCd,
	SERENITY_CHG_TECHNOLOGY_LiMn,
};

enum {
	SERENITY_CHG_CAPACITY_LEVEL_UNKNOWN = 0,
	SERENITY_CHG_CAPACITY_LEVEL_CRITICAL,
	SERENITY_CHG_CAPACITY_LEVEL_LOW,
	SERENITY_CHG_CAPACITY_LEVEL_NORMAL,
	SERENITY_CHG_CAPACITY_LEVEL_HIGH,
	SERENITY_CHG_CAPACITY_LEVEL_FULL,
};

enum {
	SERENITY_CHG_SCOPE_UNKNOWN = 0,
	SERENITY_CHG_SCOPE_SYSTEM,
	SERENITY_CHG_SCOPE_DEVICE,
};

enum serenity_chg_usb_type {
	SERENITY_CHG_USB_TYPE_UNKNOWN = 0,
	SERENITY_CHG_USB_TYPE_SDP,
	SERENITY_CHG_USB_TYPE_DCP,
	SERENITY_CHG_USB_TYPE_CDP,
	SERENITY_CHG_USB_TYPE_ACA,
	SERENITY_CHG_USB_TYPE_C,
	SERENITY_CHG_USB_TYPE_PD,
	SERENITY_CHG_USB_TYPE_PD_DRP,
	SERENITY_CHG_USB_TYPE_PD_PPS,
	SERENITY_CHG_USB_TYPE_APPLE_BRICK_ID,
	SERENITY_CHG_USB_TYPE_QC2,
	SERENITY_CHG_USB_TYPE_QC3,
	SERENITY_CHG_USB_TYPE_VOOC,
	SERENITY_CHG_USB_TYPE_SVOOC,
	SERENITY_CHG_USB_TYPE_MAX,
};

enum serenity_chg_wls_type {
	SERENITY_CHG_WLS_UNKNOWN,
	SERENITY_CHG_WLS_BPP,
	SERENITY_CHG_WLS_EPP,
	SERENITY_CHG_WLS_EPP_PLUS,
	SERENITY_CHG_WLS_VOOC,
	SERENITY_CHG_WLS_SVOOC,
	SERENITY_CHG_WLS_PD_65W,
	SERENITY_CHG_WLS_TRX,
};

enum serenity_chg_temp_region_type {
	SERENITY_CHG_BATT_TEMP_COLD = 0,
	SERENITY_CHG_BATT_TEMP_LITTLE_COLD,
	SERENITY_CHG_BATT_TEMP_COOL,
	SERENITY_CHG_BATT_TEMP_LITTLE_COOL,
	SERENITY_CHG_BATT_TEMP_PRE_NORMAL,
	SERENITY_CHG_BATT_TEMP_NORMAL,
	SERENITY_CHG_BATT_TEMP_WARM,
	SERENITY_CHG_BATT_TEMP_HOT,
	SERENITY_CHG_BATT_TEMP_INVALID,
};

enum serenity_chg_wls_rx_mode {
	SERENITY_CHG_WLS_RX_MODE_UNKNOWN,
	SERENITY_CHG_WLS_RX_MODE_BPP,
	SERENITY_CHG_WLS_RX_MODE_EPP,
	SERENITY_CHG_WLS_RX_MODE_EPP_PLUS,
	SERENITY_CHG_WLS_RX_MODE_EPP_5W,
};

enum serenity_chg_wls_trx_status {
	SERENITY_CHG_WLS_TRX_STATUS_ENABLE,
	SERENITY_CHG_WLS_TRX_STATUS_CHARGING,
	SERENITY_CHG_WLS_TRX_STATUS_DISENABLE,
};

enum serenity_chg_mod_property {
	SERENITY_CHG_PROP_TYPE,
	SERENITY_CHG_PROP_STATUS,
	SERENITY_CHG_PROP_ONLINE,
	SERENITY_CHG_PROP_PRESENT,
	SERENITY_CHG_PROP_VOLTAGE_NOW,
	SERENITY_CHG_PROP_VOLTAGE_MAX,
	SERENITY_CHG_PROP_VOLTAGE_MIN,
	SERENITY_CHG_PROP_CURRENT_NOW,
	SERENITY_CHG_PROP_CURRENT_MAX,
	SERENITY_CHG_PROP_INPUT_CURRENT_NOW,
	SERENITY_CHG_PROP_USB_TYPE,
	SERENITY_CHG_PROP_FASTCHG_STATUS,
	SERENITY_CHG_PROP_ADAPTER_SID,
	SERENITY_CHG_PROP_ADAPTER_TYPE,
	SERENITY_CHG_PROP_TEMP_REGION,
	SERENITY_CHG_PROP_CON_TEMP1,
	SERENITY_CHG_PROP_CON_TEMP2,
	SERENITY_CHG_PROP_CHG_ENABLE,
	SERENITY_CHG_PROP_OTG_MODE,
	SERENITY_CHG_PROP_TRX_VOLTAGE_NOW,
	SERENITY_CHG_PROP_TRX_CURRENT_NOW,
	SERENITY_CHG_PROP_TRX_STATUS,
	SERENITY_CHG_PROP_TRX_ONLINE,
	SERENITY_CHG_PROP_WLS_TYPE,
	SERENITY_CHG_PROP_DEVIATED,
	SERENITY_CHG_PROP_FORCE_TYPE,
	SERENITY_CHG_PROP_STATUS_DELAY,
	SERENITY_CHG_PROP_PATH_CTRL,
	SERENITY_CHG_PROP_QUIET_MODE,
	SERENITY_CHG_PROP_VRECT_NOW,
	SERENITY_CHG_PROP_TRX_POWER_EN,
	SERENITY_CHG_PROP_TRX_POWER_VOL,
	SERENITY_CHG_PROP_TRX_POWER_CURR_LIMIT,
	SERENITY_CHG_PROP_CAPACITY,
	SERENITY_CHG_PROP_REAL_CAPACITY,
	SERENITY_CHG_PROP_CHARGE_TYPE,
	SERENITY_CHG_PROP_CELL_NUM,
	SERENITY_CHG_PROP_MODEL_NAME,
	SERENITY_CHG_PROP_TEMP,
	SERENITY_CHG_PROP_HEALTH,
	SERENITY_CHG_PROP_TECHNOLOGY,
	SERENITY_CHG_PROP_CYCLE_COUNT,
	SERENITY_CHG_PROP_VOLTAGE_OCV,
	SERENITY_CHG_PROP_CHARGE_CONTROL_LIMIT,
	SERENITY_CHG_PROP_CHARGE_CONTROL_LIMIT_MAX,
	SERENITY_CHG_PROP_CHARGE_COUNTER,
	SERENITY_CHG_PROP_CHARGE_FULL_DESIGN,
	SERENITY_CHG_PROP_CHARGE_FULL,
	SERENITY_CHG_PROP_TIME_TO_FULL_AVG,
	SERENITY_CHG_PROP_TIME_TO_FULL_NOW,
	SERENITY_CHG_PROP_TIME_TO_EMPTY_AVG,
	SERENITY_CHG_PROP_POWER_NOW,
	SERENITY_CHG_PROP_POWER_AVG,
	SERENITY_CHG_PROP_CAPACITY_LEVEL,
	SERENITY_CHG_PROP_SHIP_MODE,
	SERENITY_CHG_PROP_FACTORY_MODE,
	SERENITY_CHG_PROP_TX_POWER,
	SERENITY_CHG_PROP_RX_POWER,
	SERENITY_CHG_PROP_VOLTAGE_NOW_CELL1,
	SERENITY_CHG_PROP_VOLTAGE_NOW_CELL2,
	SERENITY_CHG_PROP_MMI_CHARGING_ENABLE,
	SERENITY_CHG_PROP_TYPEC_CC_ORIENTATION,
	SERENITY_CHG_PROP_HW_DETECT,
	SERENITY_CHG_PROP_FOD_CAL,
	SERENITY_CHG_PROP_SKIN_TEMP,
	SERENITY_CHG_PROP_BATT_CHG_ENABLE,
	SERENITY_CHG_PROP_ONLINE_KEEP,
	SERENITY_CHG_PROP_CONNECT_DISABLE,
	SERENITY_CHG_PROP_REMAINING_CAPACITY,
	SERENITY_CHG_PROP_CALL_ON,
	SERENITY_CHG_PROP_CAMERA_ON,
	SERENITY_CHG_PROP_OTG_SWITCH,
	SERENITY_CHG_PROP_BATTERY_NOTIFY_CODE,
#ifdef SERENITY_CHG_REG_DUMP_ENABLE
	SERENITY_CHG_PROP_REG_DUMP,
#endif
#ifndef CONFIG_SERENITY_CHG_OOS
	SERENITY_CHG_PROP_AUTHENTICATE,
	SERENITY_CHG_PROP_BATTERY_CC,
	SERENITY_CHG_PROP_BATTERY_FCC,
	SERENITY_CHG_PROP_BATTERY_RM,
	SERENITY_CHG_PROP_BATTERY_SOH,
#ifdef CONFIG_SERENITY_CALL_MODE_SUPPORT
	SERENITY_CHG_PROP_CALL_MODE,
#endif
	SERENITY_CHG_PROP_CHARGE_TECHNOLOGY,
#ifdef CONFIG_SERENITY_CHIP_SOC_NODE
	SERENITY_CHG_PROP_CHIP_SOC,
#endif
#ifdef CONFIG_SERENITY_SMART_CHARGER_SUPPORT
	SERENITY_CHG_PROP_COOL_DOWN,
#endif
	SERENITY_CHG_PROP_FAST_CHARGE,
#ifdef CONFIG_SERENITY_SHORT_C_BATT_CHECK
#ifdef CONFIG_SERENITY_SHORT_USERSPACE
	SERENITY_CHG_PROP_SHORT_C_LIMIT_CHG,
	SERENITY_CHG_PROP_SHORT_C_LIMIT_RECHG,
	SERENITY_CHG_PROP_CHARGE_TERM_CURRENT,
	SERENITY_CHG_PROP_INPUT_CURRENT_SETTLED,
#endif
#endif
#ifdef CONFIG_SERENITY_SHORT_HW_CHECK
	SERENITY_CHG_PROP_SHORT_C_HW_FEATURE,
	SERENITY_CHG_PROP_SHORT_C_HW_STATUS,
#endif
#ifdef CONFIG_SERENITY_SHORT_IC_CHECK
	SERENITY_CHG_PROP_SHORT_IC_OTP_STATUS,
	SERENITY_CHG_PROP_SHORT_IC_VOLT_THRESH,
	SERENITY_CHG_PROP_SHORT_IC_OTP_VALUE,
#endif
	SERENITY_CHG_PROP_VOOCCHG_ING,
	SERENITY_CHG_PROP_OTG_ONLINE,
	SERENITY_CHG_PROP_USB_STATUS,
	SERENITY_CHG_PROP_FAST_CHG_TYPE,
	SERENITY_CHG_PROP_USBTEMP_VOLT_L,
	SERENITY_CHG_PROP_USBTEMP_VOLT_R,
	SERENITY_CHG_PROP_TX_VOLTAGE_NOW,
	SERENITY_CHG_PROP_TX_CURRENT_NOW,
	SERENITY_CHG_PROP_CP_VOLTAGE_NOW,
	SERENITY_CHG_PROP_CP_CURRENT_NOW,
	SERENITY_CHG_PROP_WIRELESS_MODE,
	SERENITY_CHG_PROP_WIRELESS_TYPE,
	SERENITY_CHG_PROP_CEP_INFO,
	SERENITY_CHG_PROP_REAL_TYPE,
	SERENITY_CHG_PROP_CHARGE_NOW,
#endif /* CONFIG_SERENITY_CHG_OOS */
	SERENITY_CHG_PROP_RX_VOUT_UVP,
	SERENITY_CHG_PROP_FW_UPGRADING,
	SERENITY_CHG_PROP_MAX,
	/* extended property */
	SERENITY_CHG_EXTERN_PROP_UPGRADE_FW = SERENITY_CHG_PROP_MAX,
	SERENITY_CHG_EXTERN_PROP_CHARGE_PARAMETER,
	SERENITY_CHG_EXTERN_PROP_VOLTAGE_NOW_CELL,
	SERENITY_CHG_EXTERN_PROP_PATH_CURRENT,
	SERENITY_CHG_PROP_FTM_TEST,
};

union serenity_chg_mod_propval {
	int intval;
	const char *strval;
};

struct serenity_chg_mod;

struct serenity_chg_exten_prop {
	enum serenity_chg_mod_property exten_prop;
	ssize_t (*show)(struct device *dev,
			struct device_attribute *attr,
			char *buf);
	ssize_t (*store)(struct device *dev,
			struct device_attribute *attr,
			const char *buf, size_t count);
};

struct serenity_chg_mod_config {
	struct device_node *of_node;
	struct fwnode_handle *fwnode;

	/* Driver private data */
	void *drv_data;

	/* Device specific sysfs attributes */
	const struct attribute_group **attr_grp;

	char **supplied_to;
	size_t num_supplicants;
};

struct serenity_chg_mod_desc {
	const char *name;
	enum serenity_chg_mod_type type;
	enum serenity_chg_mod_property *properties;
	enum serenity_chg_mod_property *uevent_properties;
	struct serenity_chg_exten_prop *exten_properties;
	size_t num_properties;
	size_t uevent_num_properties;
	size_t num_exten_properties;

	int (*get_property)(struct serenity_chg_mod *ocm,
			    enum serenity_chg_mod_property ocm_prop,
			    union serenity_chg_mod_propval *val);
	int (*set_property)(struct serenity_chg_mod *ocm,
			    enum serenity_chg_mod_property ocm_prop,
			    const union serenity_chg_mod_propval *val);
	int (*property_is_writeable)(struct serenity_chg_mod *ocm,
				     enum serenity_chg_mod_property ocm_prop);
};

struct serenity_chg_mod {
	const struct serenity_chg_mod_desc *desc;

	char **supplied_to;
	size_t num_supplicants;

	struct device_node *of_node;
	void *drv_data;

	/* private */
	struct device dev;
	struct work_struct changed_work;
	struct delayed_work deferred_register_work;
	struct atomic_notifier_head *notifier;
	spinlock_t changed_lock;
	bool changed;
	bool initialized;
	bool removing;
	atomic_t use_cnt;
	struct list_head list;
};

#if (LINUX_VERSION_CODE >= KERNEL_VERSION(5, 10, 0))
#include <uapi/linux/rtc.h>

//for dx1 bringup
#ifdef __KERNEL__
#ifndef _STRUCT_TIMESPEC
#define _STRUCT_TIMESPEC
struct timespec {
	__kernel_old_time_t	tv_sec;		/* seconds */
	long			tv_nsec;	/* nanoseconds */
};
#endif

struct timeval {
	__kernel_old_time_t	tv_sec;		/* seconds */
	__kernel_suseconds_t	tv_usec;	/* microseconds */
};

struct itimerspec {
	struct timespec it_interval;/* timer period */
	struct timespec it_value;	/* timer expiration */
};

struct itimerval {
	struct timeval it_interval;/* timer interval */
	struct timeval it_value;	/* current value */
};
#endif

extern time64_t rtc_tm_to_time64(struct rtc_time *tm);
extern void rtc_time64_to_tm(time64_t time, struct rtc_time *tm);

static inline void rtc_time_to_tm(unsigned long time, struct rtc_time *tm)
{
	rtc_time64_to_tm(time, tm);
}

static inline int rtc_tm_to_time(struct rtc_time *tm, unsigned long *time)
{
	*time = rtc_tm_to_time64(tm);

	return 0;
}

#if __BITS_PER_LONG == 64
/* timespec64 is defined as timespec here */
static inline struct timespec timespec64_to_timespec(const struct timespec64 ts64)
{
	return *(const struct timespec *)&ts64;
}

static inline struct timespec64 timespec_to_timespec64(const struct timespec ts)
{
	return *(const struct timespec64 *)&ts;
}

#else
static inline struct timespec timespec64_to_timespec(const struct timespec64 ts64)
{
	struct timespec ret;

	ret.tv_sec = (time_t)ts64.tv_sec;
	ret.tv_nsec = ts64.tv_nsec;
	return ret;
}

static inline struct timespec64 timespec_to_timespec64(const struct timespec ts)
{
	struct timespec64 ret;

	ret.tv_sec = ts.tv_sec;
	ret.tv_nsec = ts.tv_nsec;
	return ret;
}
#endif

static inline void getnstimeofday(struct timespec *ts)
{
	struct timespec64 ts64;

	ktime_get_real_ts64(&ts64);
	*ts = timespec64_to_timespec(ts64);
}

static inline struct timespec current_kernel_time(void)
{
	struct timespec64 ts64;

	ktime_get_coarse_real_ts64(&ts64);

	return timespec64_to_timespec(ts64);
}
#endif

#define to_serenity_chg_mod(device) container_of(device, struct serenity_chg_mod, dev)

#define SERENITY_CHG_EXTEN_RWATTR(__prop, __name)	\
{						\
	.exten_prop = __prop,			\
	.show = __name##_show,			\
	.store = __name##_store,			\
}

#define SERENITY_CHG_EXTEN_ROATTR(__prop, __name)	\
{						\
	.exten_prop = __prop,			\
	.show = __name##_show,			\
	.store = NULL,				\
}

#define SERENITY_CHG_EXTEN_WOATTR(__prop, __name)	\
{						\
	.exten_prop = __prop,			\
	.show = NULL,				\
	.store = __name##_store,			\
}

extern struct atomic_notifier_head serenity_chg_event_notifier;
extern struct atomic_notifier_head serenity_chg_changed_notifier;
extern void serenity_chg_mod_changed(struct serenity_chg_mod *ocm);
extern struct serenity_chg_mod *serenity_chg_mod_get_by_name(const char *name);
extern void serenity_chg_mod_put(struct serenity_chg_mod *ocm);
extern int serenity_chg_mod_get_property(struct serenity_chg_mod *ocm,
			       enum serenity_chg_mod_property ocm_prop,
			       union serenity_chg_mod_propval *val);
extern int serenity_chg_mod_set_property(struct serenity_chg_mod *ocm,
			    enum serenity_chg_mod_property ocm_prop,
			    const union serenity_chg_mod_propval *val);
extern int serenity_chg_mod_property_is_writeable(struct serenity_chg_mod *ocm,
					enum serenity_chg_mod_property ocm_prop);
extern int serenity_chg_mod_powers(struct serenity_chg_mod *ocm, struct device *dev);
extern int serenity_chg_reg_changed_notifier(struct notifier_block *nb);
extern void serenity_chg_unreg_changed_notifier(struct notifier_block *nb);
extern int serenity_chg_reg_event_notifier(struct notifier_block *nb);
extern void serenity_chg_unreg_event_notifier(struct notifier_block *nb);
extern int serenity_chg_reg_mod_notifier(struct serenity_chg_mod *ocm,
			       struct notifier_block *nb);
extern void serenity_chg_unreg_mod_notifier(struct serenity_chg_mod *ocm,
				  struct notifier_block *nb);
extern void serenity_chg_global_event(struct serenity_chg_mod *owner_ocm,
				enum serenity_chg_event events);
extern int serenity_chg_mod_event(struct serenity_chg_mod *ocm_receive,
			struct serenity_chg_mod *ocm_send,
			enum serenity_chg_event events);
extern int serenity_chg_anon_mod_event(struct serenity_chg_mod *ocm_receive,
			enum serenity_chg_event events);
extern struct serenity_chg_mod *__must_check serenity_chg_mod_register(struct device *parent,
		const struct serenity_chg_mod_desc *desc,
		const struct serenity_chg_mod_config *cfg);
extern struct serenity_chg_mod *__must_check
serenity_chg_mod_register_no_ws(struct device *parent,
		const struct serenity_chg_mod_desc *desc,
		const struct serenity_chg_mod_config *cfg);
extern struct serenity_chg_mod *__must_check
devm_serenity_chg_mod_register(struct device *parent,
		const struct serenity_chg_mod_desc *desc,
		const struct serenity_chg_mod_config *cfg);
extern struct serenity_chg_mod *__must_check
devm_serenity_chg_mod_register_no_ws(struct device *parent,
		const struct serenity_chg_mod_desc *desc,
		const struct serenity_chg_mod_config *cfg);
extern void serenity_chg_mod_unregister(struct serenity_chg_mod *ocm);
extern void *serenity_chg_mod_get_drvdata(struct serenity_chg_mod *ocm);

extern int ocm_to_psy_status[];
extern int ocm_to_psy_charge_type[];
extern int ocm_to_psy_health[];
extern int ocm_to_psy_technology[];
extern int ocm_to_psy_scope[];
extern int ocm_to_psy_capacity_level[];
extern int ocm_to_psy_usb_type[];

#endif /* __SERENITY_CHG_H__ */
