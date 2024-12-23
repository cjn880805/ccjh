//Sample for ITEM Ñ©²ÎÓñó¸µ¤
//Modified By Lanwood
//¿É½â¶àÖÖ¶¾¡£
//data: 2001-02-14
YAOPIN_BEGIN(CIyuchandan);

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "Ñ©²ÎÓñó¸µ¤");	//set item name

	set("unit", "Íè");
	set("long", "ÕâÊÇ¸ßÀö½ø¹±µÄÁéÒ©£¬·þºó½â¶¾ÁÆÉË£¬ÁéÑé·Ç·²¡£");
	set("base_value", 500);
		
	set_amount(1);
};
virtual int do_use(CChar * me, CContainer * target)
{
	message_vision( "$N³ÔÏÂÒ»Á£Ñ©²ÎÓñó¸µ¤£¬Ö»¾õÒ»¹ÉºÆµ´ÕæÆøÖ±Ó¿ÉÏÀ´£¬¼±Ã¦ÅÌÏ¥¶ø×ø£¬±ÕÄ¿ÔË¹¦..." , me);

	//½â¼¸ÖÖ¶¾
	struct{
		char poison[40], name[40];		//¶¾µÄÃû×Ö
		int  effect;			//ÁÆÐ§
		int  diff;				//ÄÑ¶È
	} jiedu [13] =
	{
		{"feng_poison",		"·ä¶¾",			25,		0,},
		{"flower_poison",	"¶Ï³¦»¨¶¾",		25,		6,},
		{"ice_poison",		"º®±ùÃàÕÆ",		10,		20,},
		{"jy_poison",		"¾ÅÒõ°×¹Ç×¦¶¾",	5,		20,},
		{"rainbow_poison",	"Çåºç×·ÃüÕë",   5,		20,},
		{"rose_poison",		"»ðÃµ¹å¶¾",		25,		5,},
		{"sanxiao_poison",	"ÈýÐ¦åÐÒ£É¢",	5,		14,},
		{"scorpion_poison",	"Ð«¶¾",			40,		0,},
		{"snake_poison",	"Éß¶¾",			50,		0,},
		{"xx_poison",		"ÐÇËÞÕÆ¶¾",		2,		8,},
		{"yufeng_poison",	"Óñ·åÕë",		8,		8,},
		{"zhua_poison",		"ÄýÑªÉñ×¥",		4,		16,},
		{"zm_poison",		"×ÓÄ¸·ÉÕëÖ®¶¾",	4,		16,},
	};
	
	int level = me->query("level");
	LONG poison;
	char msg[255];

	for(int du = 0; du < 13; du ++)
	{
		if( (poison = me->query_condition(jiedu[du].poison)) <= 0) continue;
		if(random(level + jiedu[du].diff) >= jiedu[du].diff)
		{
			//¿ÉÒÔ½â
			me->apply_condition(jiedu[du].poison, poison - jiedu[du].effect);
			tell_object(me, snprintf(msg, 255, "ÄãÖÐµÄ%s¼õÇáÁË¡£", jiedu[du].name));
			break;
		}
	}

	me->start_busy(2);
	destruct(this);
	return 1;
}

YAOPIN_END;
