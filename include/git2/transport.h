/*
 * Copyright (C) the libgit2 contributors. All rights reserved.
 *
 * This file is part of libgit2, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included COPYING file.
 */
#ifndef INCLUDE_git_transport_h__
#define INCLUDE_git_transport_h__

#include "indexer.h"
#include "net.h"
#include "types.h"
#include "cert.h"
#include "credential.h"

/**
 * @file git2/transport.h
 * @brief Git transport interfaces and functions
 * @defgroup git_transport interfaces and functions
 * @ingroup Git
 * @{
 */
GIT_BEGIN_DECL

/**
 * Callback for messages received by the transport.
 *
 * Return a negative value to cancel the network operation.
 *
 * @param str The message from the transport
 * @param len The length of the message
 * @param payload Payload provided by the caller
 */
typedef int GIT_CALLBACK(git_transport_message_cb)(const char *str, int len, void *payload);

/** Signature of a function which creates a transport */
typedef int GIT_CALLBACK(git_transport_cb)(git_transport **out, git_remote *owner, void *param);

/** Type of SSH session. */
typedef enum {
	/** Session used by libssh2. */
	GIT_SSH_SESSION_TYPE_LIBSSH_2 = 1
} git_ssh_session_type;

/**
 * Callback for configuring an SSH session before the
 * connection is established.
 *
 * This gives the caller opportunity to configure some of
 * the session parameters like the order and list of types
 * of hostkeys that are negotiated, allowed encryption
 * algorithms, etc.
 *
 * @param session Session used by the underlying
 * SSH implementation.
 * @param session_type Type of SSH session.
 * @param payload Payload provided by the caller.
 */
typedef int GIT_CALLBACK(git_ssh_session_cb)(const void *session, git_ssh_session_type session_type, void *payload);

/** @} */
GIT_END_DECL

#endif
