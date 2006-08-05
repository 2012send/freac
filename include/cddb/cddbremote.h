 /* BonkEnc Audio Encoder
  * Copyright (C) 2001-2006 Robert Kausch <robert.kausch@bonkenc.org>
  *
  * This program is free software; you can redistribute it and/or
  * modify it under the terms of the "GNU General Public License".
  *
  * THIS PACKAGE IS PROVIDED "AS IS" AND WITHOUT ANY EXPRESS OR
  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE. */

#ifndef _H_CDDB_REMOTE_
#define _H_CDDB_REMOTE_

#include <cddb/cddb.h>

using namespace smooth::IO;

namespace BonkEnc
{
	class BEEXPORT CDDBRemote : public CDDB
	{
		private:
			Bool		 connected;

			Buffer<char>	 hostNameBuffer;

			Driver		*socket;
			InStream	*in;
			OutStream	*out;

			String		 GetCDDBQueryString();
			String		 SendCommand(const String &);
		public:
					 CDDBRemote(Config *);
			virtual		~CDDBRemote();

			Bool		 ConnectToServer();
			String		 Query(const String &);
			Bool		 Read(const String &, CDDBInfo *);
			Bool		 Submit(CDDBInfo *);
			Bool		 CloseConnection();
	};
};

#endif