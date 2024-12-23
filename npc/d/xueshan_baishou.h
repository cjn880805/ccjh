// xueshan_baishou.c 白自在

//code by Fisho
//date:2000-12-22

NPC_BEGIN(CNxueshan_baishou);

virtual void create()
{
	set_name("白逍遥", "bai zizai");
	set("nickname", "雪山剑派掌门人");
	set("title", "剑吼城东");
	set("long","他就是雪山派分支雪山剑派的掌门人，自认为天下武功第一， 他大约五十多岁，精明能干，嫉恶如仇，性如烈火，骄傲自大。 ");
	set("gender", "男性");
	set("age", 55);
        set("icon",old_man2);

	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 28);
	set("dex", 28);
	
	set("max_hp", 6000);
	set("hp", 2000);
	set("mp", 2000);
	set("max_mp", 2000);
	set("mp_factor", 100);
	set("combat_exp", 125000);
	set("score", 60000);
	
	set_skill("force", 100);
	set_skill("hand", 170);
	set_skill("dodge", 100);
	set_skill("staff", 170);
	set_skill("unarmed", 100);
	set_skill("hamagong", 200);
	set_skill("parry", 100);
	set_skill("sword", 100);
	set_skill("chanchu_bufa", 150);
	set_skill("shexing_diaoshou", 100);
	set_skill("literate", 80);
	set_skill("lingshe_zhangfa", 150);
	
	map_skill("force", "hamagong");
	map_skill("dodge", "chanchu_bufa");
	map_skill("unarmed", "shexing_diaoshou");
	map_skill("parry", "lingshe_zhangfa");
	map_skill("hand", "shexing_diaoshou");
	map_skill("staff", "lingshe_zhangfa");
	
	carry_object("gangzhang")->wield();
	carry_object("white_robe")->wear();
	add_money(2000);
}
/*
virtual char * greeting(CChar * ob)
{
	CContainer *obj;
	int i ;
	if (userp(ob)
		&& !(ob->environment())->query("no_fight"))
	{
		if (ob->query("repute")>0)
		{
			say(" 剑道的真意在那里？。");
			say(" 敌不知我，我独知人，英雄所向无敌盖出于此。");
			say(" 疾如风，徐如林，侵略如火，不动如山，乃兵家和剑道之常理。");
			
			obj = all_inventory(me->environment());
			for(i=0; i<sizeof(obj); i++)
			{
				if(obj[i]==me)
					continue;
				if (random(ob->query("kar"))>28)
				{
					say(" 既能到此，既为你我有缘，我这有样东西，你拿去吧。 ");
					obn = load_item("/d/xiakedao/obj/shane-bu");
					obn->move(ob);
					say(" 到侠客岛来，想必是学武功吧，我在助你一臂之力。 ");
					ob->move("/d/xiakedao/neiting");
					tell_object(ob,"你只觉眼前一黑，什么也不知道了，醒来却神秘的出现在一个大厅内。 ");
				}
				say(" 既能到此，既为有缘，在后洞有一把剑，如有缘，你拿去吧。 ");
			}
		}
		else
		{
			say(" 年轻人应该走正路，你去吧。");
		}
	}
}
*/
NPC_END;