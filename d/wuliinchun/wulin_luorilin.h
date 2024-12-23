//wulin_luorilin.h 落日林
//秦波 2002.5.31

WL_BEGIN(CRWuLin_luorilin);

virtual void create()			
{
	set_name("落日林");
	add_npc("pub_xianren");
	add_npc("pub_playboy");
	add_npc("pub_playboy");
	add_npc("pub_dibao");
	add_npc("pub_girl");
	add_npc("pub_boy");
	add_npc("pub_laocunzhang");

	CContainer * env = load_room("jy");
	if(env->query("活动"))
		add_npc("pub_caoguojiou"); //曹国舅

	add_door("武陵春铺翠谷","武陵春铺翠谷", "武陵春落日林");
	add_door("武陵春熔金城","武陵春熔金城", "武陵春落日林");
	add_door("武陵春梳头溪","武陵春梳头溪", "武陵春落日林");
	add_door("佛山北帝庙","佛山北帝庙", "武陵春落日林");

};

WL_END;
