//tanghua.h
//code by zwb
//12-14

NPC_BEGIN(CNPub_tanghua);

virtual void create()
{
	set_name("唐掌柜","tanghua");
	
	set("icon", pub_boss);
	set("long","唐掌柜是这家大酒楼的主人，别看他只是一个小小的酒楼老板，在成都除了提督老爷以外，恐怕就属他最财大势大。" );
	set("age", 46);
	set("attitude", "peaceful");
	set_skill("unarmed", 60);
	set_skill("dodge", 60);
	set_temp("apply/attack", 30);
	set_temp("apply/attack", 30);
	set_temp("apply/damage", 15);
	
	set("combat_exp", 50000);
	set("attitude", "friendly");
	
	set_inquiry("名字", "在下姓唐单名一个虎字。");
	set_inquiry("这里", "此处便是蓉城酒楼，客倌如要点菜，吩咐店里的小二一声便可。,");
	set_inquiry("唐虎", "不敢，在下便是唐虎，不知客倌有何吩咐？");
	set_inquiry("蓉城酒楼", "这里就是，客倌是第一次来吗？");
	add_money(15);
	carry_object("cloth")->wear();
};


NPC_END;
