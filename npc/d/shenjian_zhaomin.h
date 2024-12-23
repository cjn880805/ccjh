// shenjian_zhaomin.c

//code by Fisho
//date:2000-12-22
//inherit F_UNIQUE;

NPC_BEGIN(CNshenjian_zhaomin);

virtual void create()
{
	set_name("����", "zhao min");
	set("title",  "��Ԫ���鹫��" );
	set("long","��������ϼ����ɫ���ˡ�ʮ������֮�У�����������Ӣ�������ֺ�̬��ͬʱӺ�ݻ�������һ������֮�£�������Ȼ�𾴣����ұ��ӡ� ");
    set("gender", "Ů��");
	set("age", 15);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("per", 30);
	set("str", 15);
	set("int", 25);
	set("con", 25);
	set("dex", 30);
 	set("icon",girl2);
	
	set("max_hp", 1500);
	set("max_mp", 500);
	set("mp", 500);
	set("mp_factor", 50);
	set("combat_exp", 50000+random(10000));
	set("score", 20000);
	set("chat_chance_combat", 60);
	
	set_skill("force", 80);
	set_skill("dodge", 80);
	set_skill("unarmed", 80);
	set_skill("sword", 80);
	set_skill("liangyi_jian", 80);
	set_skill("huifeng_jian", 80);
	set_skill("taiji_shengong", 90);
	set_skill("changquan", 80);
	set_skill("lingxu_bu", 80);
	map_skill("dodge", "lingxu_bu");
	map_skill("parry", "liangyi_jian");
	map_skill("sword", "liangyi_jian");
	map_skill("unarmed", "changquan");
	set_temp("is_riding", "������");
	set("chat_chance", 30);
	/*	set("chat_msg", ({
	(: random_move :)
	}) );
	*/
	set_inquiry("���޼�","�Ź���Զ�����أ���֪�������ɺã����䴺�������к��£� ");
	set_inquiry("���콣","����Ϊ��������� ");
	
	carry_object("changjian")->wield();
	carry_object("female2_cloth")->wear();
	add_money(1000);
}
/*	set("chat_msg_combat", ({
(: perform_action, "sword.ren" :),
}) );
*/	
virtual char * chat_msg_combat()
{
	perform_action("sword ren");
	return 0;
}

NPC_END;