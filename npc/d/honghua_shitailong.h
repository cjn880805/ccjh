//shitailong.h
//code by zwb
//12-25
//inherit F_MASTER;

NPC_BEGIN(CNHongHua_shitailong);

virtual void create()
{

	set_name("ʷ̩��","shi tai long");

	set("gender", "����");
	set("title", "������");
	set("age", 35);
	set("str", 25);
	set("dex", 20);
	set("long", "����һ����׳���٣�����Χһ�����ޡ�");
	set("combat_exp", 45000);
	set("shen_type", -1);
	set("attitude", "peaceful");
 	set("icon",young_man5);

    set("startroom","�����ʳ�");

	set_skill("unarmed", 50);
	set_skill("force", 50);
	set_skill("whip", 80);
	set_skill("dodge", 50);
	set_skill("parry", 50);

	set_skill("yunlong_bian", 70);

	set_temp("apply/attack", 30);
	set_temp("apply/defense", 30);
	set_temp("apply/armor", 15);
	set_temp("apply/damage", 20);

	map_skill("whip", "yunlong_bian");
	map_skill("parry", "yunlong_bian");

	set("mp", 200); 
	set("max_mp", 200);
	set("mp_factor", 5);
	set("chat_chance", 15);

	carry_object("junfu")->wear();
	carry_object("heilongbian")->wield();
	add_money(30);
}

virtual char * chat_msg(CChar * player)
{
	switch(random(4))
	{
	case 0:
		return "ʷ̩��һ���������ޣ�˵��:���º�����ʷ̩���������ٱ����������ػᷴ����" ;
	case 1:
		return "ʷ̩�����: ���ˣ����ˣ�ͨͨ�������£�";
	case 2:
		return "ʷ̩��˵��: ���ٱ��������£��书���������ڱ�������һȭ����һͷ��ţ����ƾ��Ҳ������ٱ����֣�" ;
	case 3:
		//random_move();
		return "";
	}
	return "";
}


virtual void init(CChar * player)
{
	if (userp(player) && !(player->environment())->query("no_fight") && (player->query("combat_exp") > 10000) && ( player->querystr("party/party_name") == "��ػ�" ))
	{
		say(" �������ػᷴ�����������ɣ�����");
		kill_ob(player);
	}       
}



NPC_END;