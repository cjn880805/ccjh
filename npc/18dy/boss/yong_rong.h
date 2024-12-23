//yong_rong 雍容 
//地狱第三层BOSS
BOSS_BEGIN(CNyong_rong);

virtual void create()
{
	set_name("雍容", "yong rong");
	set("title", "杀人名医");
	set("gender", "女性");
	set("icon", young_man3);
	set("nickname", "港中之花");
	set("long",  "她长得极美，尤其是那双眼睛，媚得直可以勾人魂魄。其容色晶莹如玉，映照于红红烛光之下，娇美不可方物。回眸嫣然一笑，雅如仙子下凡。眼波流转之间，便把一个少年的心灵，推向梦中极美的境界。");
	set("age", 21);
	
	set("str", 85);
	set("int", 85);
	set("con", 85);
	set("dex", 85);
	set("per",31);
	set("level",180);

	set("chat_chance_combat", 10);		//设置NPC使用绝招的几率
	
	set_inquiry("心狠手辣", "人在江湖必需的条件。");
	set_inquiry("紫霞神功", "华山最好的疗伤内功之一。我一直靠给人疗伤才功力大增的,你不知道吗？");
	set_inquiry("九剑", "领悟九剑必须心诚。");

	set("hp", 82000);
	set("max_hp", 82000);
	set("mp", 47000);
	set("max_mp", 47000);
	set("mp_factor", 500);
	
	set("combat_exp", 140000000);
	set("score", 500000);
	
	set_skill("unarmed", 660);
	set_skill("sword", 660);
	set_skill("force", 660);
	set_skill("parry", 660);
	set_skill("dodge", 660);
	set_skill("literate", 660);
	set_skill("huashan_shenfa", 660);
	set_skill("huashan_sword", 660);
	set_skill("zixia_shengong", 660);
	set_skill("hunyuan_zhang", 660);
	
	map_skill("sword", "huashan_sword");
	map_skill("parry", "huashan_sword");
	map_skill("force", "zixia_shengong");
	map_skill("unarmed", "hunyuan_zhang");
	map_skill("dodge", "huashan_shenfa");
	   	
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
	
	set("bigboss",1);
	set_weight(50000000);

	set("apply/armor", 800);
    set("apply/damage", 670);

	set("chat_chance", 5);
	carry_object("changjian")->wield();

	set("family/family_name","华山派");
	
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
	switch(random(14))
	{
	case 0:
		return "雍容忽然做了个鬼脸，笑道: 真想溜出去玩会儿。";
	case 1:
		command("sing2");
		break;
	case 2:
		command("angry");
		break;
	case 3:
		command("slogan2");
		break;
	case 4:
		command("yawn");
		break;
	case 5:
		command("lazy");
		break;
	case 6:
		command("laughproud");
		break;
	case 7:
		return "雍容忽然大声说：打倒臭泥潭，打倒小武！";
	case 8:
		return "雍容无聊地绕着手绢，叹道: 唉，一个人，真没意思。";
	case 9:
		return "雍容伸出白玉雕成一般的小手，托着下巴说: 谁想和我说说话?";
	case 10:
		return "雍容斩钉截铁地说: 嗯，谁要敢欺负我，我就宰了他！";
	case 11:
		return "雍容忽然莞尔一笑道: 小武待会儿又要我杀谁呢？";
	case 12:
		return "雍容打了个呵欠，左手轻轻掩住樱桃小口，柔声道：我困了。";
	case 13:
		command("reclaim");
		break;
	}
	return 0;
}

virtual char * chat_msg_combat()
{
	CContainer * ling = PresentName("changjian", IS_ITEM);
	if(query_weapon() == ling && ling)
	{
		switch(random(3))
		{
		case 0:
			perform_action("sword jianzhang", 1);
			break;
		case 1:
			perform_action("force powerup", 0);
			break;
		case 2:
			perform_action("force recover", 0);
			break;
		}
	}
	else
	{
		switch(random(4))
		{
		case 0:
			perform_action("force recover", 0);
			break;
		case 1:
			perform_action("unarmed wuji", 1);
			break;
		case 2:
			perform_action("force powerup", 0);
			break;
		case 3:
			carry_object("changjian")->wield();
			break;
		}
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
		if(EQUALSTR(querystr_temp("last_fainted_from"), me->querystr("id"))&& me->query("level")>130 )
		{
			message_vision("$HIR$N弃剑道：“$n既然赐我一败，那就去下一层地狱吧！”", this,me);
			message_vision("\n只见金光一闪，$N已经消失的无影无踪。", me);
			tell_object(me, "$HIY你忽然一阵头昏眼花，只觉一阵腾云驾雾般，睁眼一看，周身全然陌生！");
			if(me->query("18dy/level6"))
				me->set("18dy/level7",1);
			me->move(load_room("高昌沸屎地狱"));
			break;
		}
	}
	CNbossnpc::die();
}

BOSS_END;
