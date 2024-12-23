//jinshiyi 金世遗 

//地狱第二层BOSS


BOSS_BEGIN(CNjinshiyi);

virtual void create()
{
	set_name("金世遗", "jinshiyi");
	set("title", "毒手疯丐");
	set("gender", "男性");
	set("icon", young_man3);
	set("age", 88);
	set("long",  "他穿的邋里邋蹋的,可是破旧的衣裳遮不住他散发出来的霸者之气。");

	set("str", 80);

	set("int", 80);

	set("con", 80);

	set("dex", 80);

	set("per",15);

	set("level",170);



	set("chat_chance_combat", 20);		//设置NPC使用绝招的几率

	

	set_inquiry("世纪战袍", "那是比武大会的奖品,你想要啊可惜你不能穿。");

	set_inquiry("丐帮", "丐帮的武功在于霸道,你没有力量是无法发挥威力的");

	set_inquiry("仇杀", "当年和苍天笑、耗子一战,思思有事没来啊,要不谁知道输赢啊。");



	set("hp", 72000);
	set("max_hp", 72000);
	set("mp", 47000);
	set("max_mp", 47000);
	set("mp_factor", 500);

	

	set("combat_exp", 120000000);

	set("score", 500000);

	

	set_skill("force", 620);             // 基本内功

	set_skill("huntian_qigong", 620);    // 混天气功

	set_skill("unarmed", 620);           // 基本拳脚

	set_skill("xianglong_zhang", 620);   // 降龙十八掌

	set_skill("dodge", 620);      	     // 基本躲闪

	set_skill("xiaoyaoyou", 620);        // 逍遥游

	set_skill("parry", 620);             // 基本招架

	set_skill("staff", 620);             // 基本棍杖

	set_skill("dagou_bang", 620);        // 打狗棒法

	set_skill("begging", 620);           // 叫化绝活

	set_skill("xunshou_shu", 620);

	

	map_skill("force", "huntian_qigong");

	map_skill("unarmed", "xianglong_zhang");

	map_skill("dodge", "xiaoyaoyou");

	map_skill("parry", "xianglong_zhang");

	map_skill("staff", "dagou_bang");

	

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



	set("apply/armor", 750);
    set("apply/damage", 620);

	set("chat_chance", 5);
	set("门派/gaibang/wuhui",1);
    carry_object("yuzhu_zhang")->wield();
	set("family/family_name","丐帮");
	set("file_name", querystr("base_name"));
	Load();
	call_out(do_full, 7200);
}



int Save()
{
	char msg[255];
	return SaveToLocal(snprintf(msg, 255, "data/npc/%s.o", querystr("file_name")), &_M);
}


int Load()
{
	char msg[255];
	return LoadFromLocal(snprintf(msg, 255, "data/npc/%s.o", querystr("file_name")), &_M);	
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

		return "金世遗唉声叹气道：“乞讨真是难练,我练了这么久还没出头啊。”";

	case 1:

		return "金世遗叹道：“天下第一只是个虚名,可惜有几人能看透。”";

	case 2:

		if(!random(30))

			return "金世遗无限失落的叹道：“想不到在这里，我才悟出降龙真正的秘密，可惜已经没机会教给我的乖徒弟了。”";

		else

			return "金世遗叹道：“天下第一只是个虚名,可惜有几人能看透。”";

	case 3:

		if(!random(30))

			return "金世遗摇了摇头，叹道：“早知道要这样才可以领悟，我真应该找点去找他去了。”";

		else

			return "金世遗叹道：“天下第一只是个虚名,可惜有几人能看透。”";

	}

	return 0;

}



virtual char * chat_msg_combat()

{

	CContainer * ling = PresentName("yuzhu_zhang", IS_ITEM);

	if(query_weapon() == ling && ling)

	{

		switch(random(3))

		{

		case 0:

			perform_action("staff zhuang", 1);

			break;

		case 1:

			perform_action("staff linglong", 1);

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
		if(EQUALSTR(querystr_temp("last_fainted_from"), me->querystr("id"))&& me->query("level")>125 )
		{
			message_vision("$HIR$N用尽全身的力气喊道：”看...看...看我的千环套狗....”招还未使出,人以委然倒地。", this);
			message_vision("\n只见金光一闪，$N已经消失的无影无踪。", me);
			tell_object(me, "$HIY你忽然一阵头昏眼花，只觉一阵腾云驾雾般，睁眼一看，周身全然陌生！");
			if(me->query("18dy/level5"))
				me->set("18dy/level6",1);
			me->move(load_room("高昌沸沙地狱"));
			break;
		}
	}
	add("death_times",1);
	set("hp", 72000);
	set("max_hp", 72000);
	set("mp", 47000);
	set("max_mp", 47000);
	Save();
	CNbossnpc::die();
}



BOSS_END;

