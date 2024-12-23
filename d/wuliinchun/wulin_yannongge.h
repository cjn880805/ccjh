//wulin_yannongge.h ÑÌÅ¨¸ó
//ÇØ²¨ 2002.5.31

WL_BEGIN(CRWuLin_yannongge);

virtual void create()			
{
	set_name("ÑÌÅ¨¸ó");
	add_npc("wudang_laodaoshi");
	add_door("ÎäÁê´ºÕıÌü","ÎäÁê´ºÕıÌü", "ÎäÁê´ºÑÌÅ¨¸ó");
    set("sleep_room",1);

	set("yuandan",1);

};

WL_END;
