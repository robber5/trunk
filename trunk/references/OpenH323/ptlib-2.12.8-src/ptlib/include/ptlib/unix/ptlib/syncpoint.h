/*
 * syncpoint.h
 *
 * Thread synchronisation point (event) class.
 *
 * Portable Windows Library
 *
 * Copyright (c) 1993-1998 Equivalence Pty. Ltd.
 *
 * The contents of this file are subject to the Mozilla Public License
 * Version 1.0 (the "License"); you may not use this file except in
 * compliance with the License. You may obtain a copy of the License at
 * http://www.mozilla.org/MPL/
 *
 * Software distributed under the License is distributed on an "AS IS"
 * basis, WITHOUT WARRANTY OF ANY KIND, eiTY OF ANY KIND, either express or implied. See
 * the License for the specific language governing rights and limitations
 * under the License.
 *
 * The Original Code is Portable Windows Library.
 *
 * The Initial Developer of the Original Code is Equivalence Pty. Ltd.
 *
 * Portions are Copyright (C) 1993 Free Software Foundation, Inc.
 * All Rights Reserved.
 *
 * Contributor(s): ______________________________________.
 *
 * $Revision: 28062 $
 * $Author: rjongbloed $
 * $Date: 2012-07-19 04:45:52 -0500 (Thu, 19 Jul 2012) $
 */

///////////////////////////////////////////////////////////////////////////////
// PSyncPoint

#if defined(P_PTHREADS) || defined(__BEOS__) || defined(P_MAC_MPTHREADS)
  public:
    virtual ~PSyncPoint();
  private:
    mutable pthread_mutex_t mutex;
    mutable pthread_cond_t  condVar;
    bool signalled;
#endif

// End Of File ////////////////////////////////////////////////////////////////
