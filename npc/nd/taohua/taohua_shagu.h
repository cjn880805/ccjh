// shagu.c
//sound 2001-07-18

NPC_BEGIN(CNtaohua_shagu);

virtual void create()
{
	set_name("ɵŮ", "shagu");
	set("gender", "Ů��");
	set("age", 41);
//	set_race("human");
	set("class","taohua");
	
	set("long","ɵŮ�Ǹ�ɵ���������긾�ˣ��ɴ��װ��ȴ�����С���");
//	set("rank_info", "�һ�������");
	
	set("max_gin", 800);
	set("max_kee", 800);
	set("max_sen", 800);
	
	set("max_hp", 1000);
	set("hp", 1000);
	set("max_mp", 1000);
	set("mp", 1000);
	
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("per", 30);
	set("icon",young_woman11);			//������������
	
	set("combat_exp", 100000);
	set("score",50000);
	
	set_skill("force", 80);
	set_skill("parry", 80);
	set_skill("dodge", 80);
	set_skill("finger", 80);
	set_skill("sword", 80);
	
	set_skill("bibo_shengong",65);
	set_skill("luoying_shenjian",62);
	set_skill("luoying_shenzhang",62);
//	set_skill("bagua_steps",62);
	set_skill("anying_fuxiang",62);
	set_skill("lanhua_shou",62);
	
	map_skill("dodge",  "anying_fuxiang");
	map_skill("unarmed","lanhua_shou");
	map_skill("parry",  "luoying_shenjian");
	map_skill("force",  "bibo_shengong");
	map_skill("sword",  "luoying_shenjian");
	
	carry_object("cloth")->wear();
	carry_object("changjian")->wield();
}
/*
int accept_fight(object who)
{
	object ob;
	
	ob=this_object();
	
	ob->set("gin", 800);
	ob->set("kee", 800);
	ob->set("eff_kee", 800);
	ob->set("sen", 800);
	
	ob->set("atman", 1000);
	ob->set("force", 1000);
	ob->set("mana", 1000);
	
	command("say ��ܰ�����ܰ�������Ȥ��\n");
	return 1;
}

int accept_kill(object who)
{
//	do_chat("\n");
}

void lose_fight(object me)
{
	me->set_temp("win_shagu",1);
	write("lose!\n");
}
*/
NPC_END;