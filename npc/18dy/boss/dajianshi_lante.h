//dajianshi_lante 大剑师蓝特
//黄泉之路BOSS

//wuqing 2001-11-29

BOSS_BEGIN(CNdajianshi_lante);

virtual void create()
{
	set_name("大剑师蓝特", "dajianshi lante");
	
	set("gender", "男性");
	set("age", 58);
	set("long", "他身材甚是魁伟，五十来岁年纪，身穿灰色旧布袍，已微有破烂，浓眉大眼，高鼻阔口，一张四方的国字脸，颇有风霜之色，顾盼之际，极有威势。");
    
	set("str", 55);
	set("int", 55);
	set("con", 55);
	set("dex", 55);
	set("per",28);
	set("level",130);

	set("chat_chance_combat", 30);		//设置NPC使用绝招的几率
	
	set_inquiry("云风", "你见到我二哥了？他现在可好？");
	set_inquiry("大哥", "那是我大哥。");	
	set_inquiry("爱人", "天涯飘零孤身一人。");
	set_inquiry("刃刃", "那是我六哥。");
	set_inquiry("八剑阁", "是我们八兄弟一起建立的！");

	set("hp", 32000);
	set("max_hp", 32000);
	set("mp", 22000);
	set("max_mp", 22000);
	set("mp_factor", 500);
	
	set("combat_exp", 40000000);
	set("score", 500000);
	
	set_skill("force", 400);
    set_skill("dodge", 400);
    set_skill("parry", 400);
	set_skill("unarmed", 400);
    set_skill("jiuyang_shengong", 400);
	set_skill("lingfa", 400);
	set_skill("shenghuo_lingfa", 400);
	set_skill("qiankun_danuoyi", 400);
	set_skill("shenghuo_xinfa", 400);
	set_skill("huntian_qigong", 400);
	set_skill("xianglong_zhang", 400);

	map_skill("parry", "qiankun_danuoyi");
	map_skill("force", "jiuyang_shengong");
	map_skill("dodge", "qiankun_danuoyi");
	map_skill("lingfa", "shenghuo_lingfa");
	map_skill("unarmed", "xianglong_zhang");	//设置NPC的基本拳脚装备降龙掌
	
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

	set("apply/armor", 450);
    set("apply/damage", 320);

	set("chat_chance", 5);
	carry_object("shenghuo_ling")->wield();

	set("门派/gaibang/wuhui",1);
	set("family/family_name","明教");
	set("death_times",1);
	
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

virtual char * chat_msg()				//NPC自动聊天
{
	switch(random(3))
	{
	case 0:
		return 	"大剑师蓝特叹了口气道：“江湖....剑出非我心留下命来。”";
	case 1:
		return 	"大剑师蓝特说道：“兄弟们近来不知可好，不知我们兄弟几时才能一起喝酒。”";
	case 2:
		if(!random(100))
			return 	"大剑师蓝特忍了忍，似乎无法再也无法忍住，叹了口气道：“韦蝠王的刀法实在是有伤天和，这位兄弟，你可千万不要为了只求霸道而失去人性呀！”";
		else
			return 	"大剑师蓝特说道：“兄弟们近来不知可好，不知我们兄弟几时才能一起喝酒。”";
	}	
	return 0;
}

virtual char * chat_msg_combat()
{
	CContainer * ling = PresentName("shenghuo_ling", IS_ITEM);
	if(query_weapon() == ling && ling)
	{
		switch(random(3))
		{
		case 0:
			perform_action("lingfa duo", 1);
			break;
		case 1:
			perform_action("lingfa xiyanling", 1);
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
			perform_action("unarmed xianglong", 1);	//降龙掌的绝招
			break;
		case 2:
			perform_action("unarmed wuhuei", 1);	//降龙掌的绝招
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
		if(EQUALSTR(querystr_temp("last_fainted_from"), me->querystr("id")) && me->query("level")>105)
		{
			message_vision("$HIR$N不可置信的望着$n，道：“你你你...竟然能打败我..”话未说完已经倒地而亡。", this,me);
			message_vision("\n只见金光一闪，$N已经消失的无影无踪。", me);
			tell_object(me, "$HIY你忽然一阵头昏眼花，只觉一阵腾云驾雾般，睁眼一看，周身全然陌生！");
			if(me->query("18dy/level1"))
				me->set("18dy/level2",1);
			me->move(load_room("高昌奈何桥"));
			break;
		}
	}
	CNbossnpc::die();
}

BOSS_END;
