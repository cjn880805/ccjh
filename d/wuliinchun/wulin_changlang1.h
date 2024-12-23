//wulin_changlang1.h ³¤ÀÈ1
//ÇØ²¨ 2002.5.31

WL_BEGIN(CRWuLin_changlang1);

virtual void create()			
{
	set_name("³¤ÀÈ1");
	add_npc("pub_lady3");
	add_npc("pub_shicong");
	add_npc("pub_shaonu");
	add_npc("pub_jiading");
	if (random(2)==0)
	{
		add_npc("pub_girl");
		add_npc("pub_boy");
	}
	add_door("ÎäÁê´º±¯Çï¸ó","ÎäÁê´º±¯Çï¸ó", "ÎäÁê´º³¤ÀÈ1");
	add_door("ÎäÁê´ºÁ±¹³","ÎäÁê´ºÁ±¹³", "ÎäÁê´º³¤ÀÈ1");
	add_door("ÎäÁê´ºÄıíø¸ó","ÎäÁê´ºÄıíø¸ó", "ÎäÁê´º³¤ÀÈ1");
	add_door("ÎäÁê´ºĞÂ³î¸ó","ÎäÁê´ºĞÂ³î¸ó", "ÎäÁê´º³¤ÀÈ1");

	set("yuandan",1);
};

WL_END;
