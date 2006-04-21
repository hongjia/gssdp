/* 
 * Copyright (C) 2006 OpenedHand Ltd.
 *
 * Author: Jorn Baayen <jorn@openedhand.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#ifndef __GSSDP_CLIENT_PRIVATE_H__
#define __GSSDP_CLIENT_PRIVATE_H__

#include "gssdp-client.h"

G_BEGIN_DECLS

typedef enum {
        _GSSDP_DISCOVERY_REQUEST,
        _GSSDP_DISCOVERY_REPLY,
        _GSSDP_ANNOUNCEMENT
} _GSSDPMessageType;

gboolean
_gssdp_client_send_message (GSSDPClient *client,
                            const char  *dest_ip,
                            const char  *message,
                            GError     **error);

G_END_DECLS

#endif /* __GSSDP_CLIENT_PRIVATE_H__ */
