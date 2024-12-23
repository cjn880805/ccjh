//wulin_diyuange.h ตัินธ๓
//วุฒจ 2002.5.31

WL_BEGIN(CRWuLin_diyuange);

virtual void create()			
{
	set_name("ตัินธ๓");
	add_npc("monster_16k");
	add_npc("monster_8k");

	CContainer * env = load_room("jy");
	if(env->query("ป๎ถฏ"))
		add_npc("pub_hanxiangzi");//บซฯๆืำ
	set("yuandan",1);

	add_door("ฮไม๊ดบดตรทฬจ","ฮไม๊ดบดตรทฬจ", "ฮไม๊ดบตัินธ๓");

};

WL_END;
