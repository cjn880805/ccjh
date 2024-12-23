// luzhengping.c
//code by sound
//date : 2001-07-18

NPC_BEGIN(CNguiyun_luzhengping);

virtual void create()
{
	set_name("������", "lu zhengping");
	set("title", "�쵶��������");
	set("long", "ֻ����һ�Ź��ַ���������һ����ף��������������û�ˡ�");
	set("gender", "����");
	set("age", 41);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("per", 22);
	set("str", 15);
	set("int", 25);
	set("con", 25);
	set("dex", 30);
	set("icon", young_man5);
	
	set("max_hp", 1000);
	set("hp", 1000);
	set("mp", 1000);
	set("max_mp", 1000);
	set("mp_factor", 50);
	set("combat_exp", 50000+random(10000));
	set("score", 20000);

	set_skill("force", 50);
	set_skill("dodge", 50);
	set_skill("unarmed", 50);
	set_skill("blade", 50);
	set_skill("kuangfeng_blade", 50);
	set_skill("lingxu_bu",50);
	map_skill("dodge", "lingxu_bu");
	map_skill("parry", "kuangfeng_blade");
	map_skill("blade", "kuangfeng_blade");

	set_temp("apply/attack", 25);
	set_temp("apply/attack", 25);
	set_temp("apply/damage", 25);
	
	carry_object("gangdao")->wield();
	carry_object("cloth")->wear();
}

NPC_END;