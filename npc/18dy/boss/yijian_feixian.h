//yijianfeixian 一剑飞仙 
//鬼门关BOSS

BOSS_BEGIN(CNyijian_feixian);

virtual void create()
{
	set_name("一剑飞仙", "yijian feixian");
	
	set("gender", "无性");
	set("title", "缥缈");
	set("age", 128);
	set("long", "它面白无须，服色考究之极,显是衣衫上都熏了香，帽子上缀着一块翠玉，手上戴了只金戒指，一副豪富公子的打扮。但江湖上的人见了它都闻风丧胆。");
    
	set("str", 65);
	set("int", 65);
	set("con", 65);
	set("dex", 65);
	set("per",27);
	set("level",150);

	set("chat_chance_combat", 30);		//设置NPC使用绝招的几率
	
	set_inquiry("日月神教", "神教如今人才流失,后继无人啊。");
	set_inquiry("密籍", "你想要吗,,,你真的想要吗,,,？就是不给你...");
	set_inquiry("木人俱乐部", "那是当初我和魅惑水含笑他们建立了打木的地方,如今不知道还有谁在。");


	set("hp", 52000);
	set("max_hp", 52000);
	set("mp", 42000);
	set("max_mp", 42000);
	set("mp_factor", 500);
	
	set("combat_exp", 80000000);
	set("score", 500000);
	
	set_skill("force", 550);             // 基本内功
    set_skill("finger", 550);            // 基本指法
    set_skill("unarmed", 550);           // 基本拳脚
    set_skill("dodge", 550);             // 基本躲闪
    set_skill("parry", 550);             // 基本招架
    set_skill("sword", 550);             // 基本剑法
    set_skill("pixie_jian", 550);        // 辟邪剑法
    set_skill("changquan", 550);         // 太祖长拳
    set_skill("literate", 550);          // 读书识字
    set_skill("kuihua_xinfa", 550);      // 葵花心法
	
    map_skill("force", "kuihua_xinfa");
    map_skill("sword", "pixie_jian");
    map_skill("unarmed", "changquan");
    map_skill("dodge", "pixie_jian");
    map_skill("parry", "pixie_jian");
	
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

	set("apply/armor", 700);
    set("apply/damage", 570);

	set("chat_chance", 5);
    carry_object("xiuhua")->wield();
    carry_object("yan_dress")->wear();

	set("family/family_name","日月神教");
	
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
		return "一剑飞仙满怀伤感的看了看你，轻轻的叹了口气。";
	case 1:
		return "一剑飞仙叹了口气道：皮鞋皮鞋你怎么就怎么难磨啊 ";
	case 2:
		return "一剑飞仙幽幽说道：木人,木人,我心爱的木人你怎么每次不多出几个。";
	}
	return 0;	
}

virtual char * chat_msg_combat()
{
	CContainer * xiuhua = PresentName("xiuhua", IS_ITEM);
	if(query_weapon() == xiuhua && xiuhua)
	{
		switch(random(3))
		{
		case 0:
			perform_action("sword cimu", 1);
			break;
		case 1:
			perform_action("sword touzi", 1);
			break;
		case 2:
			perform_action("force recover", 0);
			break;
		}
	}
	else
	{
		switch(random(3))
		{
		case 0:
			perform_action("force recover", 0);
			break;
		case 1:
			carry_object("xiuhua")->wield();
			break;
		case 2:
			perform_action("force recover", 0);
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
		if(EQUALSTR(querystr_temp("last_fainted_from"), me->querystr("id"))&& me->query("level")>115 )
		{
			message_vision("$HIR$N恨然道：“想不到我七十二路辟邪剑法打遍天下无敌手,今天竟然败在$n手上,下边会有兄弟为我报仇的”", this,me);
			message_vision("\n只见金光一闪，$N已经消失的无影无踪。", me);
			tell_object(me, "$HIY你忽然一阵头昏眼花，只觉一阵腾云驾雾般，睁眼一看，周身全然陌生！");
			if(me->query("18dy/level3"))
				me->set("18dy/level4",1);
			me->move(load_room("高昌泥犁地狱"));
			break;
		}
	}

	CNbossnpc::die();
}

BOSS_END;
