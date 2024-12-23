// shaolin_aobai.c
//code by Fisho
//date:2000-12-21
//inherit F_UNIQUE;

NPC_BEGIN(CNshaolin_aobai);

virtual void create()
{
	set_name("����","ao bai");
	set("long","���������޵�һ��ʿ����һϮ��߽��С�����Ŀ��࣬��ò������̫��Ѩ�߸߹����ƺ��������书��");
	
	set("nickname", "���޵�һ��ʿ");
	set("gender", "����");
	set("attitude", "aggressive");
 	set("icon",old_man1);
	
	set("age", 50);
	set("shen_type", -1);
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);
	set("max_hp", 4500);
	set("hp", 1500);
	set("mp", 1500);
	set("max_mp", 1500);
	set("mp_factor", 150);
	set("combat_exp", 150000);
	set("score", 50000);
	
	set_skill("force", 90);
	set_skill("hunyuan_yiqi", 90);
	set_skill("dodge", 90);
	set_skill("shaolin_shenfa", 95);
	set_skill("hand", 100);
	set_skill("parry", 100);
	set_skill("literate", 55);
	set_skill("fengyun_shou", 90);
	
	map_skill("force", "hunyuan_yiqi");
	map_skill("dodge", "shaolin_shenfa");
	map_skill("hand", "fengyun_shou");
	map_skill("parry", "fengyun_shou");
	
	prepare_skill("hand", "fengyun_shou");
	
	set("chat_chance_combat", 10);  
	
	carry_object("anmenkey")->wield();
	carry_object("jinduan")->wear();
	carry_object("yaodai")->wear();
	carry_object("yaoshi")->wield();
	add_money(2000);
}

virtual char * chat_msg_combat()
{
	switch(random(3))
	{
	case 0:
		return "����ŭ������Ҳ�����˯�������������� ��";
	case 1:
		return "����������!";
	case 2:
		command("pain");
		return "";
		break;
	}

	return "";
}

virtual void die()
{
	message_vision("���ݿ�е����벻����һ��������Ȼ�������֣�\n���ݶ���һ�٣�̾��������ֻ��ϧ�ҵ���ô�౦������\n$N����һ�������ˣ�", this);
	CNpc::die();
}

NPC_END;