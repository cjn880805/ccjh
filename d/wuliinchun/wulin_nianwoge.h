//wulin_nianwoge.h ÄîÎÒ¸ó
//ÇØ²¨ 2002.5.31

WL_BEGIN(CRWuLin_nianwoge);

virtual void create()			
{
	set_name("ÄîÎÒ¸ó");
	add_npc("pub_lady3");
	add_npc("pub_lady2");
	add_npc("pub_lady1");
	add_door("ÎäÁê´º³¤ÀÈ2","ÎäÁê´º³¤ÀÈ2", "ÎäÁê´ºÄîÎÒ¸ó");

	set("yuandan",1);
};

WL_END;
