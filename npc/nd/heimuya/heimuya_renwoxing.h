//renwuyue.h	任我行
//code by zwb
//12-16
//inherit F_MASTER;

NPC_BEGIN(CNHeiMUYa_renwoxing);

virtual void create()
{
	set_name("任我行","ren wo xing");

	set("title",  "日月神教原教主" );
	set("long", "只见他一张长长的脸孔，脸色雪白，更无半分血色，眉目清秀,身材甚高，一头黑发，穿的是一袭青衫。");
	set("gender", "男性");
	set("class", "scholar");
	set("age", 55);
	set("attitude", "friendly");
	set("shen_type", -1);
	set("str", 30);
	set("per", 27);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
 	set("icon",old_man2);
	
	set("hp", 9000);
	set("max_hp", 9000);
	set("mp", 6000);
	set("max_mp", 6000);
	set("mp_factor", 400);
	set("combat_exp", 6000000);
	set("score", 500000);

	set_skill("literate", 100);
	set_skill("force", 200);
	set_skill("dodge", 200);
	set_skill("unarmed", 200);
	set_skill("parry", 200);
	set_skill("sword", 200);
	set_skill("changquan", 200);
	set_skill("xingxiu_duzhang", 200);
	set_skill("lingxu_bu", 200);
	set_skill("damo_jian", 200);
	set_skill("taiji_jian", 200);
	set_skill("huifeng_jian", 200);
	set_skill("taishan_sword", 200);
	set_skill("hengshan_jian", 200);
	set_skill("hengshan_sword", 200);
	set_skill("huashan_sword", 200);
	set_skill("songshan_sword", 200);

	map_skill("dodge", "lingxu_bu");
	map_skill("force", "kuihua_xinfa");
	map_skill("unarmed", "changquan");
	map_skill("sword", "damo_jian");
	map_skill("parry", "damo_jian");

	set_inquiry("救他出来",ask_jiuren);

	carry_object("bluecloth")->wear();
	carry_object("changjian")->wield();
}

static char * ask_jiuren(CNpc * npc , CChar * me)
{
	if(me->query_temp("ry/renwu1_4"))
	{
		npc->say("任我行继续道“我在石室中听梅庄的人说，东方爱莲近年来倒行逆施，已近于众叛亲离的地步。尤其那杨莲亭，本来不过是神教中一个无名小卒，只因巴结上东方爱莲，大权在手，作威作福，将教中不少功臣斥革的斥革，害死的害死。”", me);
		npc->say("“若不是限于教中严规，早已有人起来造反了。我看你年轻有为甚是喜欢，不如陪我一道去杀了东方爱莲那贱人，重整日月神教！”", me);
		npc->SendMenu(me);
		me->set_temp("ry/renwu1_5",1);//选择是否帮助任我行
	}
	else if(me->query_temp("ry/renwu1_3"))
	{
		npc->say("任我行大笑道:“哈哈哈哈！就知道早晚会有人来救我，没想到是在今天。待我用新练成的化功大法来挣脱开这无用的铁链！”", me);
		npc->say("只见他面色突然转青，刹时间石室内邪气乱冲，飞沙走石，另人无法睁开眼睛，你紧忙紧闭双眼。", me);
		npc->say("等到可以看清事物事时，原来捆住任我行的铁链已经碎成一段一段，你心想“化功大法真是威力无穷！”", me);
		npc->SendMenu(me);
		me->set_temp("ry/renwu1_4",1);//解救了任我行
	}
	return "";
}

int do_talk(CChar * me, char * ask = NULL)
{
	if(me->query_temp("ry/renwu1_5"))
	{
		if(! strlen(ask))
		{
			AddMenuItem("好的，我愿意帮助你！","yes",me);
			AddMenuItem("这个、这个不太好吧。。。","no",me);
			SendMenu(me);
		}
		else if(!strcmp(ask, "no") )
		{
			tell_object(me,"任我行说道“既然不是我的朋友，那就是我的敌人！岂能容你活在世上败露我的计划！”");
			((CUser *)this)->Ready_PK();
			((CUser *)me)->Ready_PK();
			me->kill_ob(this);	
			this->kill_ob(me);
			set("owner",me->object_id());
			me->delete_temp("ry");
			me->del("ry");
		}
		else if(!strcmp(ask, "yes") )
		{
			tell_object(me,"\n$HIR任我行哈哈大笑道：“好！老夫果然没有看错人，咱们这就上路 吧！”");
			tell_object(me,"$HIR任我行突然面露难色，道：“哎呀，不好！老夫常年被关在这石室之下脚底已不太灵光，刚刚一个不小心把脚歪了。”");
			tell_object(me,"$HIR任我行道：“小兄弟，只好让你一个人去杀东方爱莲，小心啊！这个黑木令你拿着，有了他你可以上到黑木涯真正的崖顶。从哪里上去还得去问我女儿盈盈，不知道现在由谁掌管入口。”");
			me->set_temp("ry/renwu2_1",1);//拿到黑木令去找任盈盈
			CContainer * obj = load_item("baozi");
			obj->set_name("黑木令", "heimu ling");
			obj->set_weight(500);
			obj->set("unit", "面");
			obj->set("long", "这是一块是块枯焦的黑色木头，长约半尺，上面雕刻有花纹文字，看来十分诡异。");
			obj->set("owner1",me->id(1));
			obj->set("ry/heimu_ling",1);
			obj->move(me);
			tell_object(me,"\n$HIC你得到数量1的黑木令。\n");
			me->move(load_room("梅庄休息室"));
			SendMenu(me);
		}
		return 1;
	}
	return CNpc::do_talk(me,ask);
}

virtual void die()
{
	if(query("owner"))
	{
		CChar * killer;
		CChar * owner;
		if( (killer = (CChar *)find_object(query_temp("last_damage_from"), 1)) )
		{
			//检查owner
			owner = (CChar *)find_object(query_temp("fight/owner"), 1);
			if(owner && owner->query_temp("fight/will_nk") == object_id())
				killer = owner;
			
			tell_object(killer,"\n$HIC你完成了“破坏任我行计划”的任务，得到经验888点。\n");
			killer->add("combat_exp",888);
			killer->delete_temp("no_fei");
			killer->UpdateMe();
			killer->move(load_room("梅庄休息室"));
		}
	}
	CNpc::die();
}
NPC_END;
