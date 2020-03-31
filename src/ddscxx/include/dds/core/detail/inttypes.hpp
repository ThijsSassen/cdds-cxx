/*
 * Copyright(c) 2006 to 2020 ADLINK Technology Limited and others
 *
 * This program and the accompanying materials are made available under the
 * terms of the Eclipse Public License v. 2.0 which is available at
 * http://www.eclipse.org/legal/epl-2.0, or the Eclipse Distribution License
 * v. 1.0 which is available at
 * http://www.eclipse.org/org/documents/edl-v10.php.
 *
 * SPDX-License-Identifier: EPL-2.0 OR BSD-3-Clause
 */
#ifndef CYCLONEDDS_DDS_CORE_DETAIL_INTTYPES_HPP_
#define CYCLONEDDS_DDS_CORE_DETAIL_INTTYPES_HPP_

/**
 * @file
 */

// Implementation

/* (from spec:) This implementation-defined header stands in for the C99 header files
 * inttypes.h. Under toolchains that support inttypes.h, this header can
 * simply include that one. Under toolchains that do not, this header must
 * provide equivalent definitions.
 */
#if defined _MSC_VER && (_MSC_VER <= 1500)
// VS 2005 & 2008 confirmed to have no stdint.h; predecessors presumed likewise
#include <dds/core/detail/old_win_stdint.h>
#else
#include <stdint.h>
#endif

// End of implementation

#endif /* CYCLONEDDS_DDS_CORE_DETAIL_INTTYPES_HPP_ */
