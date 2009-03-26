/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */

/* Cherokee
 *
 * Authors:
 *      Alvaro Lopez Ortega <alvaro@alobbs.com>
 *
 * Copyright (C) 2001-2009 Alvaro Lopez Ortega
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of version 2 of the GNU General Public
 * License as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301, USA.
 */ 

#ifndef CHEROKEE_LOGGER_CUSTOM_H
#define CHEROKEE_LOGGER_CUSTOM_H

#include "common-internal.h"
#include "connection.h"
#include "template.h"
#include "logger.h"
#include "logger_writer.h"

typedef struct {
	cherokee_logger_t        logger;

	cherokee_template_t      template_conn;
	cherokee_template_t      template_error;

	cherokee_logger_writer_t writer_access;
	cherokee_logger_writer_t writer_error;
} cherokee_logger_custom_t;

ret_t cherokee_logger_custom_new            (cherokee_logger_t       **logger, cherokee_config_node_t *config);
ret_t cherokee_logger_custom_free           (cherokee_logger_custom_t *logger);
ret_t cherokee_logger_custom_init           (cherokee_logger_custom_t *logger);

ret_t cherokee_logger_custom_flush          (cherokee_logger_custom_t *logger);
ret_t cherokee_logger_custom_reopen         (cherokee_logger_custom_t *logger);

ret_t cherokee_logger_custom_write_access   (cherokee_logger_custom_t *logger, cherokee_connection_t *conn);
ret_t cherokee_logger_custom_write_error    (cherokee_logger_custom_t *logger, cherokee_connection_t *conn);
ret_t cherokee_logger_custom_write_string   (cherokee_logger_custom_t *logger, const char *string);
ret_t cherokee_logger_custom_write_error_fd (cherokee_logger_custom_t *logger, int fd);

#endif /* CHEROKEE_LOGGER_CUSTOM_H */