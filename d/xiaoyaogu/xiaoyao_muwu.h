//xiaoyao_muwu.h Ä¾ÎÝ
//ÇØ²¨ 2002¡¢12¡¢5

XiaoYao_BEGIN(CRXiaoYao_muwu1);

virtual void create()
{
	set_name( "Ä¾ÎÝ");

	set("no_get",1);
	set("no_fight",1);
	set("no_cast",1);

	add_npc("xy_tielao");

	add_door("åÐÒ£¹ÈÐ¡Ôº", "åÐÒ£¹ÈÐ¡Ôº", "åÐÒ£¹ÈÄ¾ÎÝ");
	
};

void init(CChar *me)
{
	CRoom::init(me);
	if(userp(me))
	{
		if(me->query("xy/renwu7_2") )
		{
			CContainer * env=me->environment();
			CContainer * XyNpc=env->present("tong lao");
			if(XyNpc && !XyNpc->querystr("owner")[0])
				destruct(XyNpc);
		}
	}
}

XiaoYao_END;
