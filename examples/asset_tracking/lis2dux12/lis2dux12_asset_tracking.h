/**
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

#ifndef LIS2DUX12_ASSET_TRACKING_H
#define LIS2DUX12_ASSET_TRACKING_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#define LIS2DUX12_ASSET_TRACKING_SENSORS_NUM 1

#ifndef MEMS_CONF_SHARED_TYPES
#define MEMS_CONF_SHARED_TYPES

#define MEMS_CONF_ARRAY_LEN(x) (sizeof(x) / sizeof(x[0]))

/*
 * MEMS_CONF_SHARED_TYPES format supports the following operations:
 * - MEMS_CONF_OP_TYPE_TYPE_READ: read the register at the location specified
 *   by the "address" field ("data" field is ignored)
 * - MEMS_CONF_OP_TYPE_TYPE_WRITE: write the value specified by the "data"
 *   field at the location specified by the "address" field
 * - MEMS_CONF_OP_TYPE_TYPE_DELAY: wait the number of milliseconds specified by
 *   the "data" field ("address" field is ignored)
 * - MEMS_CONF_OP_TYPE_TYPE_POLL_SET: poll the register at the location
 *   specified by the "address" field until all the bits identified by the mask
 *   specified by the "data" field are set to 1
 * - MEMS_CONF_OP_TYPE_TYPE_POLL_RESET: poll the register at the location
 *   specified by the "address" field until all the bits identified by the mask
 *   specified by the "data" field are reset to 0
 */

struct mems_conf_name_list {
    const char *const *list;
    uint16_t len;
};

enum {
    MEMS_CONF_OP_TYPE_READ = 1,
    MEMS_CONF_OP_TYPE_WRITE = 2,
    MEMS_CONF_OP_TYPE_DELAY = 3,
    MEMS_CONF_OP_TYPE_POLL_SET = 4,
    MEMS_CONF_OP_TYPE_POLL_RESET = 5
};

struct mems_conf_op {
    uint8_t type;
    uint8_t address;
    uint8_t data;
};

struct mems_conf_op_list {
    const struct mems_conf_op *list;
    uint32_t len;
};

#endif /* MEMS_CONF_SHARED_TYPES */

#ifndef MEMS_CONF_METADATA_SHARED_TYPES
#define MEMS_CONF_METADATA_SHARED_TYPES

struct mems_conf_application {
    char *name;
    char *version;
};

struct mems_conf_result {
    uint8_t code;
    char *label;
};

enum {
    MEMS_CONF_OUTPUT_CORE_HW = 1,
    MEMS_CONF_OUTPUT_CORE_EMB = 2,
    MEMS_CONF_OUTPUT_CORE_FSM = 3,
    MEMS_CONF_OUTPUT_CORE_MLC = 4,
    MEMS_CONF_OUTPUT_CORE_ISPU = 5
};

enum {
    MEMS_CONF_OUTPUT_TYPE_UINT8_T = 1,
    MEMS_CONF_OUTPUT_TYPE_INT8_T = 2,
    MEMS_CONF_OUTPUT_TYPE_CHAR = 3,
    MEMS_CONF_OUTPUT_TYPE_UINT16_T = 4,
    MEMS_CONF_OUTPUT_TYPE_INT16_T = 5,
    MEMS_CONF_OUTPUT_TYPE_UINT32_T = 6,
    MEMS_CONF_OUTPUT_TYPE_INT32_T = 7,
    MEMS_CONF_OUTPUT_TYPE_UINT64_T = 8,
    MEMS_CONF_OUTPUT_TYPE_INT64_T = 9,
    MEMS_CONF_OUTPUT_TYPE_HALF = 10,
    MEMS_CONF_OUTPUT_TYPE_FLOAT = 11,
    MEMS_CONF_OUTPUT_TYPE_DOUBLE = 12
};

struct mems_conf_output {
    char *name;
    uint8_t core;
    uint8_t type;
    uint16_t len;
    uint8_t reg_addr;
    char *reg_name;
    uint8_t num_results;
    const struct mems_conf_result *results;
};

struct mems_conf_output_list {
    const struct mems_conf_output *list;
    uint16_t len;
};

struct mems_conf_mlc_identifier {
    uint8_t fifo_tag;
    uint16_t id;
    char *label;
};

struct mems_conf_mlc_identifier_list {
    const struct mems_conf_mlc_identifier *list;
    uint16_t len;
};

#endif /* MEMS_CONF_METADATA_SHARED_TYPES */

static const char *const lis2dux12_asset_tracking_format_version = "2.0";

static const char *const lis2dux12_asset_tracking_description = NULL;

static const struct mems_conf_application lis2dux12_asset_tracking_application = {
    .name = "Configuration Converter Tool",
    .version = "1.0"
};

static const char *const lis2dux12_asset_tracking_date = NULL;

/* Sensor names */

static const char *const lis2dux12_asset_tracking_names_0[] = {
    "LIS2DUX12"
};

static const struct mems_conf_name_list lis2dux12_asset_tracking_name_lists[LIS2DUX12_ASSET_TRACKING_SENSORS_NUM] = {
    { .list = lis2dux12_asset_tracking_names_0, .len = (uint16_t)MEMS_CONF_ARRAY_LEN(lis2dux12_asset_tracking_names_0) }
};

/* Configurations */

static const struct mems_conf_op lis2dux12_asset_tracking_conf_0[] = {
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x14, .data = 0x00 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x13, .data = 0x10 },
    { .type = MEMS_CONF_OP_TYPE_DELAY, .data = 5 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x3F, .data = 0x80 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x04, .data = 0x00 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x05, .data = 0x00 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x39, .data = 0x4B },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x1A, .data = 0x03 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x0A, .data = 0x00 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x0B, .data = 0x00 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x0E, .data = 0x00 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x0F, .data = 0x03 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x17, .data = 0x40 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x02, .data = 0x01 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x08, .data = 0x54 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x00 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x00 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x02 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x02 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x00 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x02 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x02, .data = 0x21 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x08, .data = 0x00 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x92 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x00 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x16 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x00 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x0F },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x00 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x00 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x38 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x66 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x2E },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x02 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x00 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x00 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x05 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x04 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x23 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x05 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x12 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x05 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x03 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x64 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x22 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x51 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x00 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x14 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x00 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x0C },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x00 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0xCD },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x34 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x02 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x00 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x00 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x03 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x12 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x53 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x99 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x41 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0xA5 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x0E },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x0C },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x00 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x04, .data = 0x00 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x05, .data = 0x11 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x17, .data = 0x00 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x3F, .data = 0x00 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x1F, .data = 0x01 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x20, .data = 0x01 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x14, .data = 0x63 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x13, .data = 0x10 },
    { .type = MEMS_CONF_OP_TYPE_DELAY, .data = 5 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x14, .data = 0x00 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x3F, .data = 0x80 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x04, .data = 0x00 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x05, .data = 0x00 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x17, .data = 0x40 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x02, .data = 0x01 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x08, .data = 0xB8 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0xFA },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x00 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x0C },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x01 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x00 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x00 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x0A },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x01 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x0C },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x02, .data = 0x01 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x08, .data = 0xC8 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0xDC },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x00 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x12 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x01 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x1E },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x01 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x02, .data = 0x01 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x08, .data = 0xDC },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x00 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x00 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x00 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x00 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x00 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x00 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x00 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x00 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x01 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x00 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x00 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x00 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x3F },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x00 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x00 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x0C },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x00 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x00 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x00 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x10 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x00 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x00 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x03 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x10 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x00 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0xFC },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x00 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x7C },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x1F },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x00 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x02, .data = 0x11 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x08, .data = 0x12 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x00 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x00 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x00 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x00 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x00 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x00 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x00 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x00 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x00 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x00 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x00 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x3F, .data = 0x00 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x3F, .data = 0x80 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x17, .data = 0x40 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x02, .data = 0x11 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x08, .data = 0x1E },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0xAE },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x2B },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x02 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x82 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x33 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x3B },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x04 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0xE0 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0xF2 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0x3C },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0xC8 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x09, .data = 0xE1 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x3F, .data = 0x80 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x17, .data = 0x00 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x04, .data = 0x00 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x05, .data = 0x10 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x02, .data = 0x01 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x3F, .data = 0x00 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x1F, .data = 0x01 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x3F, .data = 0x80 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x0D, .data = 0x01 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x3A, .data = 0x11 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x3F, .data = 0x00 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x14, .data = 0x63 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x3F, .data = 0x80 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x17, .data = 0x80 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x04, .data = 0x00 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x05, .data = 0x11 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x02, .data = 0x01 },
    { .type = MEMS_CONF_OP_TYPE_WRITE, .address = 0x3F, .data = 0x00 }
};

static const struct mems_conf_op_list lis2dux12_asset_tracking_confs[LIS2DUX12_ASSET_TRACKING_SENSORS_NUM] = {
    { .list = lis2dux12_asset_tracking_conf_0, .len = (uint32_t)MEMS_CONF_ARRAY_LEN(lis2dux12_asset_tracking_conf_0) }
};

/* Outputs */

static const struct mems_conf_result lis2dux12_asset_tracking_results_0_8[] = {
    { .code = 0x00, .label = "0" },
    { .code = 0x04, .label = "4" },
    { .code = 0x08, .label = "8" },
    { .code = 0x0C, .label = "12" }
};

static const struct mems_conf_output lis2dux12_asset_tracking_outputs_0[] = {
    {
        .name = "FSM1",
        .core = MEMS_CONF_OUTPUT_CORE_FSM,
        .type = MEMS_CONF_OUTPUT_TYPE_UINT8_T,
        .len = 1,
        .reg_addr = 0x20,
        .reg_name = "FSM_OUTS1",
        .num_results = 0,
        .results = NULL
    },
    {
        .name = "FSM2",
        .core = MEMS_CONF_OUTPUT_CORE_FSM,
        .type = MEMS_CONF_OUTPUT_TYPE_UINT8_T,
        .len = 1,
        .reg_addr = 0x21,
        .reg_name = "FSM_OUTS2",
        .num_results = 0,
        .results = NULL
    },
    {
        .name = "FSM3",
        .core = MEMS_CONF_OUTPUT_CORE_FSM,
        .type = MEMS_CONF_OUTPUT_TYPE_UINT8_T,
        .len = 1,
        .reg_addr = 0x22,
        .reg_name = "FSM_OUTS3",
        .num_results = 0,
        .results = NULL
    },
    {
        .name = "FSM4",
        .core = MEMS_CONF_OUTPUT_CORE_FSM,
        .type = MEMS_CONF_OUTPUT_TYPE_UINT8_T,
        .len = 1,
        .reg_addr = 0x23,
        .reg_name = "FSM_OUTS4",
        .num_results = 0,
        .results = NULL
    },
    {
        .name = "FSM5",
        .core = MEMS_CONF_OUTPUT_CORE_FSM,
        .type = MEMS_CONF_OUTPUT_TYPE_UINT8_T,
        .len = 1,
        .reg_addr = 0x24,
        .reg_name = "FSM_OUTS5",
        .num_results = 0,
        .results = NULL
    },
    {
        .name = "FSM6",
        .core = MEMS_CONF_OUTPUT_CORE_FSM,
        .type = MEMS_CONF_OUTPUT_TYPE_UINT8_T,
        .len = 1,
        .reg_addr = 0x25,
        .reg_name = "FSM_OUTS6",
        .num_results = 0,
        .results = NULL
    },
    {
        .name = "FSM7",
        .core = MEMS_CONF_OUTPUT_CORE_FSM,
        .type = MEMS_CONF_OUTPUT_TYPE_UINT8_T,
        .len = 1,
        .reg_addr = 0x26,
        .reg_name = "FSM_OUTS7",
        .num_results = 0,
        .results = NULL
    },
    {
        .name = "FSM8",
        .core = MEMS_CONF_OUTPUT_CORE_FSM,
        .type = MEMS_CONF_OUTPUT_TYPE_UINT8_T,
        .len = 1,
        .reg_addr = 0x27,
        .reg_name = "FSM_OUTS8",
        .num_results = 0,
        .results = NULL
    },
    {
        .name = "DT1",
        .core = MEMS_CONF_OUTPUT_CORE_MLC,
        .type = MEMS_CONF_OUTPUT_TYPE_UINT8_T,
        .len = 1,
        .reg_addr = 0x34,
        .reg_name = "MLC1_SRC",
        .num_results = (uint8_t)MEMS_CONF_ARRAY_LEN(lis2dux12_asset_tracking_results_0_8),
        .results = lis2dux12_asset_tracking_results_0_8
    }
};

static const struct mems_conf_output_list lis2dux12_asset_tracking_output_lists[LIS2DUX12_ASSET_TRACKING_SENSORS_NUM] = {
    { .list = lis2dux12_asset_tracking_outputs_0, .len = (uint16_t)MEMS_CONF_ARRAY_LEN(lis2dux12_asset_tracking_outputs_0) }
};

/* MLC identifiers */

static const struct mems_conf_mlc_identifier_list lis2dux12_asset_tracking_mlc_identifier_lists[LIS2DUX12_ASSET_TRACKING_SENSORS_NUM] = {
    { .list = NULL, .len = 0 }
};

#ifdef __cplusplus
}
#endif

#endif /* LIS2DUX12_ASSET_TRACKING_H */
