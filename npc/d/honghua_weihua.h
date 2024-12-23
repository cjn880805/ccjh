//weihua.h
//code by zwb
//12-25
//inherit F_MASTER;

NPC_BEGIN(CNHongHua_weihua);

virtual void create()
{

	set_name("����","wei hua");

	set("title", "�컨��ŵ���" );
	set("nickname",  "��ͷ��" );
	set("long", "��������ĿӢ������һ���಼��������ʮ��������ͣ�˫Ŀ��Ȼ���񣬵�����Ӣ�����ˡ�");
	set("gender", "����");
	set("class", "swordsman");
	set("age", 31);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("per", 26);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
 	set("icon",young_man3);
	
	set("max_hp", 5400);
	set("mp", 1000);
	set("max_mp", 1000);
	set("mp_factor", 100);
	set("combat_exp", 250000);

	set_skill("force", 100);
	set_skill("dodge", 100);
	set_skill("unarmed", 100);
	set_skill("parry", 100);
	set_skill("sword", 100);
	set_skill("houquan", 100);
	set_skill("yunlong_xinfa", 100);
	set_skill("yunlong_shengong", 100);
	set_skill("yunlong_jian", 100);
	set_skill("yunlong_shenfa", 150);

	map_skill("dodge", "yunlong_shenfa");
	map_skill("force", "yunlong_shengong");
	map_skill("unarmed", "houquan");
	map_skill("parry", "yunlong_jian");
	map_skill("sword", "yunlong_jian");

	set("env/wimpy", 20);

	carry_object("bluecloth")->wear();
	carry_object("changjian")->wield();
}

NPC_END;