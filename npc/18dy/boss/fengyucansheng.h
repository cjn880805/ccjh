//fengyucansheng 风雨残生 
//地狱第十三层BOSS

BOSS_BEGIN(CNfengyucansheng);

virtual void create()
{	
	set_name("风雨残生", "fengyu cansheng");
	set("title", "花自飘零");
	set("gender", "男性");
	set("icon", young_man3);
	set("age", 68);
	set("long",  "只见一个长袍黄冠的道人负手站在一株古松下，羽衣瓢瓢，潇然出尘，神情看来说不出的和平宁静。");

	set("str", 121);
	set("int", 121);
	set("con", 121);
	set("dex", 95);
	set("per",35);
	set("level",220);
	set("repute",50000000);

	set("chat_chance_combat", 15);		//设置NPC使用绝招的几率
	
	set_inquiry("浪子", "好久没见到他了。");
	set_inquiry("星宿毒掌", "你知道怎么用吗？");
	set_inquiry("道士", "道士也是可以结婚的。");

	set("hp", 177000);
	set("max_hp",177000);
	set("max_mp", 87000);
	set("mp", 87000);
	set("mp_factor", 500);
	
	set("combat_exp", 280000000);
	set("score", 500000);
	
	set_skill("throwing", 850);
	set_skill("feixing_shu", 850);        
	set_skill("force", 850);
	set_skill("huagong_dafa", 850);
	set_skill("dodge", 850);
	set_skill("zhaixinggong", 850);
	set_skill("strike",850);
	set_skill("xingxiu_duzhang", 850);
	set_skill("parry", 850);
	set_skill("literate", 850);
	set_skill("sanyin_wugongzhao", 850);
	set_skill("claw", 850);
	set_skill("poison", 850);
	set_skill("chousui_zhang", 850);

	map_skill("force", "huagong_dafa");
	map_skill("dodge", "zhaixinggong");
	map_skill("strike", "chousui_zhang");
	map_skill("parry", "feixing_shu");
	map_skill("unarmed", "xingxiu_duzhang");
	map_skill("claw", "sanyin_wugongzhao");
        
	prepare_skill("strike", "chousui_zhang");
	prepare_skill("claw", "sanyin_wugongzhao");
	
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
	set_temp("apply/no_封字决",1);
	set_temp("apply/施毒术",random(30)+20);
	
	set("bigboss",1);
	set_weight(50000000);

	set("apply/armor", 1200);
    set("apply/damage", 1050);

	set("chat_chance", 5);

	set("family/family_name","星宿派");
	
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
	switch(random(3))
	{
	case 0:
		return "风雨残生无限深情的凝视着远方，似乎在等待着一个思念已久的人。";
	case 1:
		return "风雨残生似乎想起了什么，突然说道：“双木是华山的老大。”";
	case 2:
		return "风雨残生转身负手，轻声叹道：“月牙，你现在那里呢？”";
	}
	return 0;
}

virtual char * chat_msg_combat()
{
	
	switch(random(6))
	{
	case 0:
		perform_action("force recover", 0);
		break;
	case 1:
		carry_object("corpse_ob", 1);
		perform_action("strike throw", 1);	
		break;
	case 2:
		perform_action("force huo", 0);
		break;
	case 3:
		perform_action("force hpsuck", 1);
		break;
	case 4:
		perform_action("force suck", 1);
		break;
	case 5:
		perform_action("strike huoqiu", 1);	
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
		if(EQUALSTR(querystr_temp("last_fainted_from"), me->querystr("id"))&& me->query("level")>163 )
		{
			message_vision("$HIR$N道：“好好好,$n通过了,可以进下一层了！”", this,me);
			message_vision("\n只见金光一闪，$N已经消失的无影无踪。", me);
			tell_object(me, "$HIY你忽然一阵头昏眼花，只觉一阵腾云驾雾般，睁眼一看，周身全然陌生！");
			if(me->query("18dy/level16"))
				me->set("18dy/level17",1);
			me->move(load_room("高昌铁磨地狱"));
			break;
		}
	}
	CNbossnpc::die();
}

BOSS_END;
