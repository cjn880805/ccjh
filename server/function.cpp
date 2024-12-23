#include "stdafx.h"
#include "CodeChange.h"
#include "Globle.h"
#include "Mapping2.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////
//explode(v, "ni,hao,haha,hi", ',') => ({"ni", "hao", "haha", "hi"})
CVector * explode(CVector &v, const char * msg, const char split)
{
	int p = 0, q = 0;
	char val[512];

	while(msg[p])
	{
		if(msg[p] != split)
		{
			val[q++] = msg[p];
			if(q == 511)
			{
				output_error("ERROR: explode -> key is too large!");
				return &v;
			}
		}
		else
		{
			val[q++] = 0;
			q = 0;

			v.append(val);
		}

		p++;
	}

	val[q] = 0;
	v.append(val);
	
	return &v;
}

//implode({("ha", "f"}), ",") => "ha,f"
char * implode(char * msg, int len, CVector &v, const char split)
{
	int p = 0;
	for(int i=0; i<v.count(); i++)
	{
		const char * key = v[i];
		int k = 0;
		while(key[k])
		{
			msg[p++] = key[k++];
			if( p == len - 1)
			{
				msg[len - 1] = 0;
				return msg;
			}
		}
		msg[p++] = split;
		if(p == len - 1)
		{
			msg[len - 1] = 0;
			return msg;
		}
	}

	msg[p - 1] = 0;
	return msg;
}