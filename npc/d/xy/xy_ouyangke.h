//ouyangke.h
//Lanwood 2000-01-05

NPC_BEGIN(CNxy_ouyangke);

virtual void create()
{
	set_name("白少庄主", "ouyang ke");
	
	set("long", "他手摇折扇，风流儒雅，却有些忧伤，目光茫然地看着来往的女孩们。");
	set("title", "白驼山少庄主");
	set("gender", "男性");
	set("age", 27);
	set("icon",young_man1);

	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);

	set("hp", 8500);
	set("max_hp", 8500);
	
	set("mp", 8000);
	set("max_mp", 8000);
	set("mp_factor", 100);

	set("combat_exp", 5000000);
	set("score", 30000);

	set_skill("force", 210);
	set_skill("unarmed", 210);
	set_skill("dodge", 210);
	set_skill("parry", 210);
	set_skill("hand",210);
	set_skill("staff", 210);
	set_skill("hamagong", 210);
	set_skill("chanchu_bufa", 210);
	set_skill("shexing_diaoshou", 210);
	set_skill("lingshe_zhangfa", 210);
	set_skill("xunshou_shu",210);
	set_skill("poison", 210);

	map_skill("force", "hamagong");
	map_skill("dodge", "chanchu_bufa");
	map_skill("unarmed", "shexing_diaoshou");
	map_skill("hand", "shexing_diaoshou");
	map_skill("parry", "lingshe_zhangfa");
	map_skill("staff", "lingshe_zhangfa");

	set("apply/armor", 180);
    set("apply/damage", 100);
	set("no_chan",1);
};

virtual void die()
{
	CContainer * obj = environment();
	DTItemList * list = obj->Get_ItemList();  
	POSITION p = list->GetHeadPosition(); 
	while(p) 
	{ 
		CContainer * obj = list->GetNext(p);
		if(! obj->is_character()) continue; 
		CChar * target = (CChar *)obj;  
		if(!userp(target))	continue;
		if(EQUALSTR(querystr("owner"),target->id(1)))
		{
			target->delete_temp("xy/renwu7_4");
			break;
		}
	}
	CNpc::die();
}
NPC_END;
