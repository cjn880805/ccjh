//wulin_pucueigu.h ÆÌ´ä¹È
//ÇØ²¨ 2002.5.31

WL_BEGIN(CRWuLin_pucueigu);

virtual void create()			
{
	set_name("ÆÌ´ä¹È");
	add_npc("pub_boy");
	add_npc("pub_girl");
	add_npc("pub_kid");
	if (random(2)==0)
	{
		add_npc("pub_yufu");
		add_npc("pub_youke");
	}
	add_door("ÎäÁê´ºÄí½ğ·å","ÎäÁê´ºÄí½ğ·å", "ÎäÁê´ºÆÌ´ä¹È");
	add_door("ÎäÁê´ºÂäÈÕÁÖ","ÎäÁê´ºÂäÈÕÁÖ", "ÎäÁê´ºÆÌ´ä¹È");

};

WL_END;
