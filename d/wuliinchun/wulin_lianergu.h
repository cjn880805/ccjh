//wulin_lianergu.h Á±¶ù¹È
//ÇØ²¨ 2002.5.31

WL_BEGIN(CRWuLin_lianergu);

virtual void create()			
{
	set_name("Á±¶ù¹È");
	add_npc("pub_jianke");
	add_npc("pub_daoke");
	add_npc("monster_40k");
	if (random(2)==0)
	{
		add_npc("pub_liumangtou");
		add_npc("pub_tiaofu");
	}
	add_door("ÎäÁê´ºĞ¦Óï·å","ÎäÁê´ºĞ¦Óï·å", "ÎäÁê´ºÁ±¶ù¹È");
	add_door("ÎäÁê´ºÑ©÷Ş·å","ÎäÁê´ºÑ©÷Ş·å", "ÎäÁê´ºÁ±¶ù¹È");

};

WL_END;
