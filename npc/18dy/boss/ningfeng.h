//ningfeng
//wuqing 2001-12-2
//迷宫BOSS

BOSS_BEGIN(CNningfeng);

virtual void create()
{	
	set_name("凝风", "ningfeng");
	set("title", "霍山老人");
	set("gender", "男性");
	set("icon", young_man3);
	set("age", 68);
	set("long",  "他银须白发，长的道骨仙风。");
	
	set("str", 45);
	set("int", 45);
	set("con", 45);
	set("dex", 45);
	set("per",40);

	set("max_hp", 10000);
	set("max_mp", 8000);
	set("mp", 8000);
	set("mp_factor", 150); 
	set("level",120);
	
	set("combat_exp",  16000000);
	set("chat_chance",  10);
	set("chat_chance_combat", 20);
	
	set_inquiry("江湖", "唉，现在的江湖好乱，杀人放火太多了，可惜我不能再斩妖除魔了。");
	set_inquiry("心中的那个MM", "她在那里啊，好想好想她你见过她吗？");
	set_inquiry("月庭", "月庭是江湖上最神秘的帮派之一，随着我和雪儿的退隐，月庭满华不在。");
	
	set_skill("force", 300);
	set_skill("dodge", 300);
	set_skill("parry", 300);
	set_skill("sword", 350);
	set_skill("literate", 300);
	set_skill("shenzhao_gong", 300);
	set_skill("piaoyibu", 300);
	set_skill("doomsword", 350);
    
	map_skill("force", "shenzhao_gong");
	map_skill("dodge", "piaoyibu");
	map_skill("sword", "doomsword");
	map_skill("parry", "doomsword");

	carry_object("changjian")->wield();

	set("no_kill",1);
	set("no_缠字决",1);
	set_temp("apply/no_连字诀",1);
	set_temp("apply/no_千环套狗",1);
	set_temp("apply/no_相思无用",1);
	set_temp("apply/no_势合形离",1);
	set_temp("apply/no_点字决",1);
	set_temp("apply/no_天外飞龙",1);
	set_temp("apply/no_拼命",1);
	set_temp("apply/no_祭血神刀",1);
	
	set("bigboss",1);
	set_weight(50000000);

	set("apply/armor", 380);
    set("apply/damage", 200);

	call_out(do_full, 7200);
	
}

static void do_full(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	if(!me->query_temp("fight/is_fighting"))
	{
		message_vision("\n$HIR$N缓缓坐下，运功调息。", me);
		me->set("mp",me->query("max_mp"));
		me->set("hp",me->query("max_hp"));
	}
	me->call_out(do_full, 7200);
}

virtual char * chat_msg()				
{
	switch(random(4))
	{
	case 0:
		return "想当年我纵横江湖几十载，啥大风大浪没见过。";
	case 1:
		return "凝风轻叹道：悠悠江湖岁月老，独忆少年狂风流 ";
	case 2:
		return "月庭满华。";
	case 3:
		return "不知道以前的一帮老兄弟现在怎么样了？」";
	}
	return 0;
	
}
virtual char * chat_msg_combat()			
{
	switch(random(2))
	{
	case 0:
		perform_action("sword doomsword", 1);	
		break;
	case 1:
		perform_action("force recover", 0);	
		break;
	}	
	return 0;
}

void die()
{
	CContainer * obj = environment();
	DTItemList * list = obj->Get_ItemList();  
	POSITION p = list->GetHeadPosition(); 
	CChar * me;
	while(p) 
	{ 
		CContainer * obj = list->GetNext(p);
		if(! obj->is_character()) continue; 
		me = (CChar *)obj;  
		if(!userp(me))	continue;
		//最后一个打倒的人将获得进入下一层的资格
		if(EQUALSTR(querystr_temp("last_fainted_from"), me->querystr("id")) && me->query("level")>100)
		{
			message_vision("$HIR$N猛的吐出一口鲜血，吼道：“既然如此，$n就索性陪我一起下地狱去吧！”", this,me);
			message_vision("\n只见金光一闪，$N已经消失的无影无踪。", me);
			tell_object(me, "$HIY你忽然一阵头昏眼花，只觉一阵腾云驾雾般，睁眼一看，周身全然陌生！");
			me->set("18dy/level1",1);
			me->move(load_room("高昌黄泉之路"));
			break;
		}
	}
	CNbossnpc::die();
}

BOSS_END;