//yanglihuei.h
//code by zwb
//12-25

NPC_BEGIN(CNHongHua_yanglihuei);

virtual void create()
{

	set_name("������","yang li huei");

	set("title", "�컨��˵���");
	set("nickname",  "����" );
	set("long","����Ȼ��Ӣ��������ȴʤ�ڸߴ����ͣ���ִһ���ֱޣ��������Ǵ��أ���ģ����˵Ҳ����ʮ���");
	set("gender", "����");
	set("class", "fighter");
	set("age", 26);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("per", 20);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
 	set("icon",young_man1);
	
	set("max_hp", 4500);
	set("mp", 1000);
	set("max_mp", 1000);
	set("mp_factor", 100);
	set("combat_exp", 300000);

	set_skill("force", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_skill("whip", 100);
	set_skill("hand", 100);
	set_skill("claw", 100);
	set_skill("yunlong_shengong", 100);
	set_skill("yunlong_shenfa", 100);
	set_skill("yunlong_bian", 100);
	set_skill("yunlong_shou", 100);
	set_skill("yunlong_zhua", 100);

	map_skill("dodge", "yunlong_shenfa");
	map_skill("force", "yunlong_shengong");
	map_skill("hand", "yunlong_shou");
	map_skill("parry", "yunlong_bian");
	map_skill("claw", "yunlong_zhua");
	map_skill("whip", "yunlong_bian");

	prepare_skill("hand","yunlong_shou");
	prepare_skill("claw","yunlong_zhua");
	set("env/wimpy", 20);

	carry_object("cloth")->wear();
	carry_object("tiebian")->wield();
}

NPC_END;