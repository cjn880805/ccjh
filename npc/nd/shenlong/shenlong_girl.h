// girl.c
//code by sound
//2001-07-12

NPC_BEGIN(CNshenlong_girl);

virtual void create()
{
	set_name("年轻女弟子", "young girl");
	set("icon",young_woman4);
	set("title", "神龙教赤龙使座下弟子");
	set("long", "这是一个神龙教女弟子，一袭红衣，长得颇为可爱。");
	
	set("gender", "女性");
	set("attitude", "peaceful");
	
	set("age", 10+random(10));
	set("shen_type", -1);
	set("str", 25+random(10));
	set("dex", 25+random(10));
	set("max_hp", 200);
	set("hp", 200);
	set("mp", 200);
	set("max_mp", 200);
	set("mp_factor", 5+random(5));
	set("combat_exp", 20000+random(10000));
	
	set_skill("force", 40);
	set_skill("dodge", 40);
	set_skill("unarmed", 40);
	set_skill("parry", 40);
	set_skill("sword", 60);
	set_skill("shedao_qigong", 30);
	map_skill("sword","shedao_qigong");
	set("chat_chance", 3);
	
	carry_object("xionghuang")->wield();
	carry_object("duanjian")->wield();
	carry_object("cloth")->wear();

}

virtual char * chat_msg()						//NPC自动聊天
{
	switch(random(5))
	{
	case 0:
		return 	"年轻弟子忽然高声叫道:教主宝训,时刻在心,建功克敌,无事不成！”";
	case 1:
		return 	"年轻弟子忽然齐声叫道:众志齐心可成城,威震天下无比伦！";
	case 2:
		return 	"年轻弟子忽然齐声叫道:神龙飞天齐仰望,教主声威盖八方！";
	case 3:
		return 	"年轻弟子忽然齐声叫道:乘风破浪逞英豪,教主如同日月光！";
	case 4:
		return 	"年轻弟子齐声叫道:教主永享仙福,寿与天齐！";
	}
	
	return 0;
}

int do_talk(CChar * me, char * ask = NULL)
{
	
	if(me->query("wei/renwu1") && me->query_temp("wei/renwu4_4") && !me->query_temp("wei/renwu4_5") )
	{
		if(! strlen(ask))
		{
			AddMenuItem("关于神龙教蕲蛇","she",me);
			SendMenu(me);
		}
		else if(!strcmp(ask, "she") )
		{
			CContainer * xionghuang=me->present("xionghuang");
			
			if(xionghuang)
			{
				tell_object(me,"年轻女弟子告诉你：“小心，蕲蛇凶猛残忍，奇毒无比。”");
				tell_object(me,"年轻女弟子给你数量1的小白鼠。");
				tell_object(me,"年轻女弟子匆匆离开了。");
				me->set_temp("wei/renwu4_5",1);
				load_npc("baishu")->move(me);
				destruct(this);
			}
			else
			{
				say("年轻女弟子大斥道：“不知道死活的家伙，还不快快离去！”",me);
				SendMenu(me);
			}
		}
		return 1;
	}
	
	return CNpc::do_talk(me,ask);
}

NPC_END;